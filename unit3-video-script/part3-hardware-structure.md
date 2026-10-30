# PART 3 — Topic 3: Hardware Structure of the Basic MIPS Processor

---

## Scene 3.1 — Two Kinds of Hardware Elements

**Visual directions:** Heading "TOPIC 3 — HARDWARE STRUCTURE". Screen split into
two columns: "Combinational elements" and "State elements".

**Diagram instructions:** Left column icons: ALU, adder, multiplexor, sign-extend.
Right column icons: PC, register file, instruction memory, data memory. A clock
waveform under the right column with rising edges marked.

**Narration:**
> In Topic 2 we watched data move. Now we look closely at each piece of hardware.
> The notes use the term **datapath element**: a unit used to operate on or hold data
> within a processor. In the MIPS implementation, the datapath elements include the
> instruction and data memories, the register file, the ALU, and adders.
> Datapath elements come in two kinds.
> **Combinational elements** compute an output purely from their current inputs —
> like the ALU, adders, multiplexors and the sign-extension unit. They have no memory.
> **State elements** store values — like the PC, register file and data memory. They
> are updated on a clock edge. The notes describe the PC, register file writes and
> data memory writes as **edge-triggered** — they change only at the clock edge.
> We will introduce the components one at a time, and then put them all together.

**On-screen revision points:**
- **Datapath element**: unit that operates on or holds data in a processor.
- Combinational: ALU, adder, mux, sign-extend. State: PC, registers, memories.

---

## Scene 3.2 — Program Counter (PC)

**Visual directions:** Notes' Figure 2.1(b): a tall narrow box "PC" with one input
arrow and one output arrow. A 32-bit counter display shows 0x00400000 → 0x00400004
→ 0x00400008 ticking at each clock edge.

**Narration:**
> The **Program Counter**. Definition from the notes: the register containing the
> address of the instruction in the program being executed.
> It is a **32-bit register**. Its output goes to the instruction memory as the
> instruction address, and to the adder that computes PC + 4.
> The notes say the PC is written at the end of every clock cycle, so it does not
> need a write control signal. Every cycle, it simply loads whatever is at its
> input — PC + 4, a branch target, or a jump address.

**On-screen revision points:**
- PC: 32-bit register holding the address of the current instruction.
- Written every clock cycle → no write-control signal.

---

## Scene 3.3 — Instruction Memory

**Visual directions:** Notes' Figure 2.1(a): box "Instruction memory" with input
"Instruction address" and output "Instruction".

**Narration:**
> The **instruction memory** stores the program. Its input is an instruction
> address; its output is the 32-bit instruction at that address.
> The notes point out that the instruction memory only needs to provide **read**
> access, because the datapath does not write instructions. Since it only reads, we
> treat it as combinational logic: the output always reflects the contents at the
> address input, and no read control signal is needed.
> Why a separate memory for instructions and data? Because in a single-cycle design,
> no resource can be used more than once per instruction. A load must read an
> instruction and read data in the same cycle, so we need two memories.

**On-screen revision points:**
- Instruction memory: read-only in this datapath; no control signal.
- Separate instruction and data memories because single-cycle uses each unit once.

---

## Scene 3.4 — Adders

**Visual directions:** Notes' Figure 2.1(c): adder shape with two inputs, output
"Sum". Then two copies labelled "PC + 4 adder" and "Branch target adder".

**Narration:**
> An **adder**, in the notes' words, is an ALU wired to always add its two 32-bit
> inputs and place the sum on its output.
> Our datapath has **two** adders, apart from the main ALU.
> The first computes **PC + 4**, the address of the next sequential instruction —
> one input is the PC, the other is the constant 4.
> The second computes the **branch target**: PC + 4 plus the shifted, sign-extended
> offset.
> Why not reuse the main ALU? Because in a single cycle the ALU is busy — for a beq
> it is comparing the registers at the same moment.

**On-screen revision points:**
- Adder #1: PC + 4. Adder #2: branch target = (PC + 4) + (offset << 2).

---

## Scene 3.5 — The Fetch Datapath (Figure 2.2)

**Visual directions:** Build notes' Figure 2.2 piece by piece: PC → Read address
of Instruction memory; PC also → Add with 4; Add output loops back to PC.

**Narration:**
> Now combine the three elements. The PC sends its value to the instruction memory's
> read address, and the instruction comes out. At the same time, the PC goes to the
> adder with the constant 4, and the sum goes back to the PC input.
> At the next clock edge the PC is updated, and the next instruction is fetched.
> This small circuit, Figure 2.2 in the notes, is the fetch portion of every
> instruction. The fetched instruction is then used by other parts of the datapath.

---

## Scene 3.6 — The Register File

**Visual directions:** Notes' Figure 2.3(a). Register box with five inputs on the
left and two outputs on the right; "RegWrite" in blue at the bottom.

**Diagram instructions:**
```
          5 ─/─► Read register 1          Read data 1 ─/─ 32 ►
          5 ─/─► Read register 2          Read data 2 ─/─ 32 ►
          5 ─/─► Write register
         32 ─/─► Write data
                      RegWrite (control)
```
A slash with a number on a wire means "this many bits".

**Narration:**
> The **register file**. The notes define it as a state element that consists of a
> set of registers that can be read and written by supplying a register number to be
> accessed. It holds all 32 general-purpose registers.
> R-format instructions have three register operands, so for each instruction we may
> read two data words and write one.
> For each word to be **read**, we need an input that specifies the register number,
> and an output that carries the value. So: **Read register 1**, **Read register 2**,
> and **Read data 1**, **Read data 2**.
> To **write**, we need two inputs: the register number — **Write register** — and the
> value — **Write data**.
> So, four inputs — three register numbers and one data — and two outputs.
> The register number inputs are **5 bits** wide, since 2 to the power 5 is 32. The
> data input and the two data outputs are **32 bits** wide.
> Reads happen all the time: the register file always outputs the contents of
> whichever registers are on the read inputs. Writes are controlled by the
> **RegWrite** signal, which must be asserted for a write to happen at the clock edge.
> In other words, the register file has **two read ports and one write port**.

**On-screen revision points:**
- Register file: 2 read ports, 1 write port; 4 inputs, 2 outputs.
- Register numbers = 5 bits; data = 32 bits. Write needs RegWrite = 1.

---

## Scene 3.7 — The ALU

**Visual directions:** Notes' Figure 2.3(b): ALU shape, two 32-bit inputs, "ALU
operation" 4-bit control on top, outputs "ALU result" and "Zero".

**Narration:**
> The **Arithmetic and Logic Unit**, the ALU, operates on the values read from the
> registers.
> It has two 32-bit inputs and a 32-bit result. A **4-bit ALU operation** control
> input selects what it does — add, subtract, AND, OR, or set-on-less-than.
> It also has a one-bit output called **Zero**, which is 1 when the result is zero.
> We use Zero to implement beq: subtract the two registers, and if the result is
> zero, they are equal.

**On-screen revision points:**
- ALU: two 32-bit inputs, 32-bit result, Zero output, 4-bit ALU operation input.

---

## Scene 3.8 — The Data Memory

**Visual directions:** Notes' Figure 2.4(a): box "Data memory" with inputs Address,
Write data; output Read data; MemWrite on top, MemRead at the bottom (blue).

**Narration:**
> The **data memory** holds data for loads and stores. It is a state element with
> two inputs — the **address** and the **write data** — and one output — the **read
> data**.
> It has **separate read and write controls**, MemRead and MemWrite, although only
> one may be asserted on any clock.
> Why does it need a read signal when the register file does not? The notes explain
> that, unlike the register file, reading an invalid address in memory can cause
> problems. So memory is read only when the instruction is a load.
> Writes are edge-triggered.

**On-screen revision points:**
- Data memory: inputs Address, Write data; output Read data; MemRead, MemWrite.

---

## Scene 3.9 — The Sign-Extension Unit

**Visual directions:** Notes' Figure 2.4(b): ellipse "Sign-extend", input 16 bits,
output 32 bits. Then two animated bit examples.

**Worked example:**
```
Positive:  +32 = 0000 0000 0010 0000
   → 0000 0000 0000 0000 0000 0000 0010 0000 = 0x00000020 (= +32)

Negative:  −2  = 1111 1111 1111 1110
   → 1111 1111 1111 1111 1111 1111 1111 1110 = 0xFFFFFFFE (= −2)
```

**Narration:**
> The **sign-extension unit**. The notes define sign-extend as: to increase the size
> of a data item by replicating the high-order sign bit of the original data item in
> the high-order bits of the larger destination data item.
> The 16-bit immediate or offset must become 32 bits before the ALU or adder can use
> it. We copy bit 15 — the sign bit — into bits 16 to 31.
> If the number is positive, bit 15 is 0, so we fill with zeros. +32 stays +32.
> If it is negative, bit 15 is 1, so we fill with ones. −2 in 16 bits is FFFE, and
> it becomes FFFF FFFE, which is still −2.
> This is used by lw, sw, addi, and beq.

**On-screen revision points:**
- Sign-extend: copy bit 15 into bits 31–16. Preserves value and sign.

---

## Scene 3.10 — Shift Left 2 and Multiplexors

**Visual directions:** "Shift left 2" ellipse with wires visibly re-routed; then a
2-input mux with a select line toggling between 0 and 1.

**Diagram instructions:**
```
     in0 ─►┌───┐
           │ M │
     in1 ─►│ u │─► out        select = 0 → out = in0
           │ x │              select = 1 → out = in1
           └─▲─┘
           select
```

**Narration:**
> The **shift-left-2 unit** multiplies the branch offset by 4. The notes stress that
> no actual shift hardware is needed, since the amount is constant. It is just wiring
> that adds 0 0 at the low end. The shift throws away the top two bits, which are only
> sign bits after sign extension.
> A **multiplexor**, or **data selector**, chooses one of its inputs and passes it to
> the output, based on a select control line. With two inputs, one select bit is enough:
> 0 picks the first input, 1 picks the second.
> The complete datapath has these multiplexors:
> **ALUSrc mux** — ALU second input: register or sign-extended immediate.
> **MemtoReg mux** — register write data: ALU result or memory data.
> **PCSrc mux** — next PC: PC + 4 or branch target.
> And, as a clarification beyond the notes' figure, a **RegDst mux** choosing rt or rd
> as the write register, and a **Jump mux** for the jump address.

**On-screen revision points:**
- Multiplexor = data selector; select line picks the input.
- Muxes: ALUSrc, MemtoReg, PCSrc (+ RegDst, Jump as clarifications).

---

## Scene 3.11 — The Control Unit

**Visual directions:** "Control" ellipse with the 6-bit opcode (instruction
bits 31–26) as input and blue signal wires fanning out to every unit.

**Narration:**
> The **control unit** has the instruction as its input. It looks at the opcode — bits
> 31 to 26 — and sets the control lines for the functional units and the multiplexors.
> For R-type instructions the opcode is 0, so the ALU operation is further determined
> by the **funct** field, bits 5 to 0.
> One multiplexor is not set directly by the control unit: the PCSrc mux. It is set by
> ANDing the **Branch** control signal with the ALU's **Zero** output.
> Think of the control unit as a conductor of an orchestra. The datapath components are
> the musicians; they can all play, but the control unit decides who plays what on each
> instruction.

**On-screen revision points:**
- Control unit input: opcode (bits 31–26). Outputs: RegDst, ALUSrc, MemtoReg,
  RegWrite, MemRead, MemWrite, Branch, ALUOp (+ Jump).
- PCSrc = Branch AND Zero.

---

## Scene 3.12 — The Complete Datapath (Figure 4.11)

**Visual directions:** The complete datapath assembles itself from the components
introduced, one at a time, then the full labelled diagram holds on screen for 10
seconds.

**Diagram instructions (notes' Figure 4.11, with clarifications in dashed lines):**
- **PC** → Read address of **Instruction memory**; PC → **Add** (with **4**).
- Add output (PC + 4) → **Add** (branch adder, labelled "ALU result") and → input 0
  of **PCSrc Mux** (top right). Branch adder output → input 1 of PCSrc Mux. PCSrc Mux
  output → back to PC.
- Instruction [25:21] → **Read register 1**; [20:16] → **Read register 2**;
  [20:16] → **Write register** (dashed **RegDst mux** with [15:11] as second input —
  clarification); [15:0] → **Sign-extend** (16 → 32).
- Sign-extend output → **Shift left 2** → branch adder; and → input 1 of **ALUSrc
  Mux**.
- **Read data 1** → ALU top input. **Read data 2** → ALUSrc Mux input 0 and → **Write
  data** of Data memory.
- **ALU** (control "ALU operation", 4 bits) → **ALU result** → Data memory **Address**
  and → MemtoReg Mux input 0. ALU **Zero** → branch logic.
- **Data memory** (MemWrite top, MemRead bottom) Read data → **MemtoReg Mux** input 1.
- MemtoReg Mux output → loops along the bottom to the register file **Write data**.
- Control labels in blue: PCSrc, ALUSrc, ALU operation, MemWrite, MemtoReg, MemRead,
  RegWrite.
- Caption (from notes): "The simple datapath for the core MIPS architecture combines
  the elements required by different instruction classes."

**Narration:**
> Here it is — the complete single-cycle datapath, Figure 4.11 in the notes.
> Let us trace it from left to right.
> The **PC** feeds the **instruction memory** and the **PC + 4 adder**.
> The instruction is split into fields. Bits 25 to 21 go to read register 1. Bits 20
> to 16 go to read register 2 and to the write register input. Bits 15 to 0 go to the
> sign-extend unit.
> Read data 1 goes straight into the ALU. Read data 2 goes to the **ALUSrc
> multiplexor** and also to the data memory's write data input — that is the path
> used by store word.
> The sign-extended immediate goes into the ALUSrc multiplexor, and also through
> **shift left 2** into the **branch adder**.
> The ALU result goes to the data memory address and to the **MemtoReg multiplexor**.
> The memory read data also goes to MemtoReg. Its output loops back to the register
> file's write data.
> At the top, the **PCSrc multiplexor** chooses between PC + 4 and the branch target,
> and feeds the PC.
> The notes say this datapath can execute the basic instructions — load-store word,
> ALU operations and branches — in a single clock cycle. Just one additional
> multiplexor is needed to integrate branches. Support for jumps is added later.
> A clarification: in the notes' figure, the write register is wired only from bits
> 20 to 16 — that works for lw, but an R-type instruction writes rd, bits 15 to 11. The
> full textbook design adds a **RegDst multiplexor** here, shown dashed.

---

## Scene 3.13 — Hardware Path: R-Format, LW, SW, BEQ on the Complete Datapath

**Visual directions:** Four consecutive animations on the same full datapath, each in
its own colour. Unused units fade to 20% opacity. A side panel lists the active
control signals.

**Narration:**
> Let us run all four instruction types through the complete hardware.
> **R-format, `add $t1,$t2,$t3`, in green.** PC → instruction memory. rs and rt are
> read. ALUSrc = 0, so read data 2 enters the ALU. The ALU adds. Data memory is idle.
> MemtoReg = 0, so the ALU result travels back to write data. RegWrite = 1. PCSrc =
> 0, so PC + 4 is loaded.
> **LW, `lw $t0,32($s3)`, in blue.** rs is read. The offset is sign-extended, and
> ALUSrc = 1 sends it into the ALU. The ALU adds to form the address. MemRead = 1.
> Memory data goes through MemtoReg = 1 to write data. RegWrite = 1. PC + 4.
> **SW, `sw $t0,48($s3)`, in purple.** rs and rt are read. ALUSrc = 1; the ALU forms the
> address. Read data 2 flows along the lower wire into memory's write data. MemWrite =
> 1. RegWrite = 0. PC + 4.
> **BEQ, `beq $t1,$t2,L`, in orange.** rs and rt are read. ALUSrc = 0; the ALU
> subtracts. Meanwhile the offset is sign-extended, shifted left 2 and added to PC + 4.
> If Zero = 1, PCSrc = 1 and the target is loaded into the PC; otherwise PC + 4.
> RegWrite = 0, MemWrite = 0.
> The same hardware, four different behaviours — selected entirely by control signals.

**On-screen revision points:**
| Component | Purpose | Used by |
|---|---|---|
| PC | address of current instruction | all |
| Instruction memory | supplies instruction | all |
| Adder (PC + 4) | next sequential address | all |
| Register file | read rs, rt; write rd/rt | R, lw, sw, beq |
| Sign-extend | 16 → 32 bits | lw, sw, beq, addi |
| ALUSrc mux | register vs immediate | all with ALU |
| ALU | operation / address / compare | R, lw, sw, beq |
| Data memory | load / store data | lw, sw |
| MemtoReg mux | ALU vs memory to register | R, lw |
| Shift left 2 + adder | branch target | beq |
| PCSrc mux | PC + 4 vs target | all |
| Control unit | sets all control lines | all |

**Exam points for Topic 3:**
- Draw the complete datapath and label every unit and control line.
- Register file: 2 read ports, 1 write port; 5-bit register numbers.
- Instruction memory needs no read control; data memory needs MemRead/MemWrite.
- Shift left 2 is just wiring.

---

*End of Part 3 — the three priority topics are complete. Continue with Part 4.*
