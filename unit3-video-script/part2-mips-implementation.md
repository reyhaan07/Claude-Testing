# PART 2 — Topic 2: A Basic MIPS Implementation

---

## Scene 2.1 — The MIPS Subset We Implement

**Visual directions:** Heading "TOPIC 2 — A BASIC MIPS IMPLEMENTATION". Three
coloured category cards appear, exactly as listed in the notes.

**Diagram instructions:**
- Card 1 (blue): "Memory-reference: `lw`, `sw`"
- Card 2 (green): "Arithmetic-logical: `add`, `sub`, `AND`, `OR`, `slt`"
- Card 3 (orange): "Branch `beq` and jump `j` (added last)"
- Small grey card: "Not included: shift, multiply, divide, floating point"

**Narration:**
> Now that we know how instructions find their operands, let us see how a
> processor actually executes them.
> The notes examine an implementation of a **subset** of the core MIPS instruction
> set. It has three groups.
> First, the **memory-reference** instructions: load word, lw, and store word, sw.
> Second, the **arithmetic-logical** instructions: add, sub, AND, OR, and slt —
> "set on less than".
> Third, the instructions **branch equal**, beq, and **jump**, j, which are added
> last.
> The notes are clear that this subset does not include all integer instructions —
> shift, multiply and divide are missing — and no floating-point instructions.
> But it illustrates the key principles used in creating a datapath and designing
> the control. The remaining instructions are implemented in a similar way.
> Two new words: a **datapath** is the hardware that moves and processes data —
> memories, registers, ALU, adders and the wires between them. **Control** is the
> logic that tells the datapath what to do for each instruction.

**On-screen revision points:**
- Subset: lw, sw | add, sub, and, or, slt | beq, j.
- Datapath = hardware that operates on/holds data. Control = tells it what to do.

---

## Scene 2.2 — The First Two Steps Are Identical for Every Instruction

**Visual directions:** Two large animated steps. A PC box sends an address to
instruction memory; the instruction comes out and its register fields light up.

**Diagram instructions:**
```
Step 1:  PC ──address──► [Instruction memory] ──instruction──►
Step 2:  instruction[25:21] (rs) ──► Read register 1 ─┐
         instruction[20:16] (rt) ──► Read register 2 ─┴► [Registers] ─► Read data 1, Read data 2
```

**Narration:**
> The notes say: for every instruction, the first two steps are identical.
> Step one: send the **program counter** to the memory that contains the code, and
> **fetch** the instruction from that memory.
> Step two: **read one or two registers**, using fields of the instruction to select
> the registers to read. For load word, we need to read only one register — the base
> register. Most other instructions read two.
> After these two steps, the actions depend on the instruction class.
> But here is the good news: within each class, the actions are largely the same,
> regardless of the exact instruction. The simplicity and regularity of the MIPS
> instruction set simplifies the implementation.

**On-screen revision points:**
- Step 1: Fetch — PC → instruction memory → instruction.
- Step 2: Read registers — fields of the instruction select 1 or 2 registers.

---

## Scene 2.3 — Every Class (Except Jump) Uses the ALU

**Visual directions:** ALU symbol centre-screen. Three arrows labelled with the
three uses.

**Narration:**
> After reading the registers, all instruction classes except jump use the
> arithmetic-logical unit, the ALU — but for different purposes.
> Memory-reference instructions use the ALU for an **address calculation** — base
> plus offset, the base addressing we just learned.
> Arithmetic-logical instructions use it for the **operation execution** — the add,
> subtract, and, or, or comparison itself.
> Branches use it for **comparison** — are the two registers equal?
> After the ALU, the classes differ again.
> A memory-reference instruction must access the data memory — to read data for a
> load, or write data for a store.
> An arithmetic-logical or load instruction must write the data, from the ALU or
> the memory, back into a register.
> And for a branch, we may need to change the next instruction address based on the
> comparison; otherwise the PC is incremented by 4 to get the address of the next
> instruction.

**On-screen revision points:**
| Class | ALU used for | After the ALU |
|---|---|---|
| lw / sw | address calculation | access data memory (lw also writes register) |
| R-type | operation | write result to register |
| beq | comparison (subtract, check Zero) | choose PC+4 or branch target |
| j | not used | PC ← jump address |

---

## Scene 2.4 — The Five Phases of Execution

**Visual directions:** A horizontal 5-stage strip: Fetch → Register read/Decode →
ALU → Memory → Write-back, plus a separate "PC update" arrow looping back.

**Narration:**
> Let us give names to these steps; we will use them for every instruction.
> One — **instruction fetch**: read the instruction at address PC.
> Two — **register read**: read the registers named by rs and rt. At the same time
> the control unit looks at the opcode and decides what to do — this is decoding.
> Three — **ALU operation**: compute a result, an address, or a comparison.
> Four — **memory access**: only for lw and sw.
> Five — **write-back**: write a result into the register file — only for R-type
> and lw.
> And throughout — **PC update**: the PC becomes PC + 4, or the branch target, or
> the jump address.
> In this first design, the notes say every instruction begins execution on one
> clock edge and completes on the next clock edge. So all five phases happen in a
> **single clock cycle**. We call this a **single-cycle implementation**.

**On-screen revision points:**
- Fetch → Register read/decode → ALU → Memory → Write-back; PC update.
- Single-cycle: each instruction completes in one clock cycle.

---

## Scene 2.5 — High-Level View: Figure 1.1

**Visual directions:** Redraw the notes' Figure 1.1, then animate data flow.

**Diagram instructions (Figure 1.1, clean redraw):**
- Left: **PC** box → "Address" of **Instruction memory**; "Instruction" output
  splits into three "Register #" inputs of **Registers** and a branch to the
  **Data** input region.
- Top: an **Add** with inputs PC and constant **4**; a second **Add** with inputs
  (PC + 4) and the offset from the instruction. Both adder outputs loop back to PC.
- **Registers** outputs → **ALU** → "Address" of **Data memory**.
- Registers' second output → "Data" (write data) of Data memory.
- Data memory output and ALU output both loop back to the "Data" input of Registers.
- Thick lines labelled "buses"; dots where crossing lines connect.

**Narration:**
> This is Figure 1.1 from the notes — an abstract view of the implementation,
> showing the major functional units and the connections between them.
> All instructions start by using the program counter to supply the instruction
> address to the instruction memory.
> After the instruction is fetched, the register operands are specified by fields
> of that instruction.
> Once the register operands have been fetched, they can be used to compute a
> memory address for a load or store, an arithmetic result for an arithmetic-
> logical instruction, or a compare for a branch.
> For an arithmetic-logical instruction, the ALU result is written to a register.
> For a load or store, the ALU result is used as an address — to store a value from
> the registers, or to load a value from memory into the registers.
> Branches use the ALU output to decide the next instruction address, which comes
> either from the adder where PC and branch offset are summed, or from the adder
> that increments the current PC by 4.
> The thick lines are **buses** — groups of many signals, here usually 32 wires.
> The arrows show the direction of information. Where crossing lines are connected,
> a dot is drawn.

---

## Scene 2.6 — What Figure 1.1 Leaves Out

**Visual directions:** Figure 1.1 with three red circles where two wires meet one
input, and three red question marks next to units that need control.

**Narration:**
> The notes point out two omissions in Figure 1.1.
> **First**, in several places, data going to a unit comes from two different
> sources. The value written into the PC can come from one of two adders. The data
> written into the register file can come from the ALU or from data memory. And the
> second ALU input can come from a register or from the immediate field.
> You cannot simply wire two sources together. We need a logic element that
> chooses one of them — a **multiplexor**, which the notes say might better be
> called a **data selector**. It selects among its inputs based on its control lines.
> **Second**, several units must be controlled depending on the instruction type.
> The data memory must read on a load and write on a store. The register file must
> be written on a load and on an arithmetic-logical instruction. The ALU must
> perform one of several operations.
> These control lines are set based on fields in the instruction.

**On-screen revision points:**
- Omission 1 → add **multiplexors (data selectors)**.
- Omission 2 → add **control lines** set from the instruction.

---

## Scene 2.7 — Figure 1.2: Adding Multiplexors and Control

**Visual directions:** Redraw notes' Figure 1.2. Control lines drawn in blue.
Highlight each multiplexor in turn.

**Diagram instructions (Figure 1.2):**
- Everything in Figure 1.1, plus:
- **Top Mux**: inputs (PC + 4) and (branch target); output → PC. Its select comes
  from an **AND gate** whose inputs are **Branch** (from Control) and **Zero**
  (from ALU).
- **Middle Mux** (right of data memory): inputs ALU result and Data memory output;
  output → register file "Data" input.
- **Bottom Mux** (before ALU): inputs Register read data 2 and instruction offset
  field; output → ALU second input.
- **Control** ellipse at the bottom, input = instruction, blue outputs:
  **RegWrite**, **ALU operation**, **MemRead**, **MemWrite**, **Branch**, and
  mux selects.

**Narration:**
> Figure 1.2 is the same datapath with three multiplexors added, plus control lines
> for the major functional units.
> A **control unit**, which has the instruction as its input, determines how to set
> the control lines for the functional units and two of the multiplexors.
> The **top multiplexor** controls what value replaces the PC: PC + 4 or the branch
> destination address. It is controlled by a gate that ANDs together the **Zero**
> output of the ALU and a control signal indicating the instruction is a **Branch**.
> The **middle multiplexor** steers either the ALU output — for an arithmetic-
> logical instruction — or the data memory output — for a load — into the register
> file.
> The **bottom multiplexor** decides whether the second ALU input comes from the
> registers — for arithmetic-logical or branch — or from the offset field of the
> instruction — for a load or store.
> The remaining control lines decide the ALU operation, whether data memory reads
> or writes, and whether the registers perform a write.
> Because MIPS is regular and simple, a simple decoding process is enough to set
> these control lines.

**On-screen revision points:**
- Top mux → PC source; select = Branch AND Zero.
- Middle mux → register write data: ALU result or memory data.
- Bottom mux → ALU input 2: register or sign-extended offset.

---

## Scene 2.8 — Control Signals Explained (Clarification beyond the notes)

**Visual directions:** Tag in the corner: "Clarification — beyond the notes
(standard textbook values)". Table builds row by row.

**Diagram instructions:** Table of signals with a one-line meaning each.

**Narration:**
> The notes name the control lines in their figures but do not tabulate their
> values. To explain every instruction fully, I will use the standard names and
> values from the textbook the notes are drawn from, Patterson and Hennessy. I am
> marking this clearly as a clarification.
> **RegDst** — chooses the destination register number: rt when 0, rd when 1.
> **ALUSrc** — chooses the ALU's second input: register read data 2 when 0, the
> sign-extended immediate when 1. This is the notes' "bottom multiplexor".
> **MemtoReg** — chooses what is written into the register: ALU result when 0,
> memory data when 1. This is the "middle multiplexor".
> **RegWrite** — when 1, the register file is written at the clock edge.
> **MemRead** — when 1, data memory is read.
> **MemWrite** — when 1, data memory is written.
> **Branch** — 1 for a beq. Together with Zero it forms **PCSrc**, the select of
> the top multiplexor.
> **ALU operation** — a 4-bit code telling the ALU what to do.
> **Jump** — 1 for j; selects the jump address for the PC.

**On-screen revision points (clarification):**
| Signal | 0 means | 1 means |
|---|---|---|
| RegDst | write reg = rt | write reg = rd |
| ALUSrc | ALU B = Read data 2 | ALU B = sign-extended imm |
| MemtoReg | reg data = ALU result | reg data = memory data |
| RegWrite | no write | write register |
| MemRead | — | read data memory |
| MemWrite | — | write data memory |
| Branch | not beq | beq |
| PCSrc = Branch AND Zero | PC = PC + 4 | PC = branch target |

ALU control codes (4 bits): AND 0000, OR 0001, add 0010, subtract 0110,
set on less than 0111.

---

## Scene 2.9 — Instruction Class 1: R-Type (ADD, SUB, AND, OR, SLT)

**Visual directions:** Complete datapath dims; only the R-type path lights up green.
Step counter 1–5 animates in sync with narration.

**Diagram instructions — highlighted path:**
```
PC → Instruction memory → instruction
  [25:21] rs → Read register 1 → Read data 1 → ALU A
  [20:16] rt → Read register 2 → Read data 2 → ALUSrc mux (0) → ALU B
  [15:11] rd → RegDst mux (1) → Write register
ALU result → MemtoReg mux (0) → Write data → register rd
PC → Add(+4) → PCSrc mux (0) → PC
```
Data memory and sign-extend shown greyed out.

**Narration:**
> Let us execute our first instruction class: R-type, also called arithmetic-
> logical instructions. The notes say they all read two registers, perform an ALU
> operation on the contents, and write the result to a register.
> **Instruction:** `add $t1, $t2, $t3` — the typical example in the notes. It reads
> $t2 and $t3 and writes $t1.
> **Purpose:** $t1 gets $t2 plus $t3.
> **Hardware involved:** PC, instruction memory, the PC + 4 adder, register file,
> ALU, and the multiplexors.
> **Data flow, step by step:**
> One — fetch: the PC addresses instruction memory, and the instruction comes out.
> At the same time, the adder computes PC + 4.
> Two — register read: bits 25 to 21, rs, select $t2 on read register 1. Bits 20 to
> 16, rt, select $t3 on read register 2. Both values appear on read data 1 and 2.
> Three — ALU: ALUSrc is 0, so the ALU's second input is read data 2. The ALU
> operation is "add".
> Four — memory: not used. MemRead and MemWrite are both 0.
> Five — write-back: MemtoReg is 0, so the ALU result goes to write data. RegDst is
> 1, so the write register is rd, bits 15 to 11 — that is $t1. RegWrite is 1, so at
> the clock edge $t1 is written.
> PC update: Branch is 0, so the PC becomes PC + 4.
> **For sub, and, or, slt** the path is identical. Only the ALU operation changes —
> and that is chosen using the funct field.

**Worked example:**
```
PC = 0x00400000, $t2 = 12, $t3 = 5
add $t1,$t2,$t3 → ALU: 12 + 5 = 17 → $t1 = 17
sub $t1,$t2,$t3 → ALU: 12 − 5 = 7  → $t1 = 7
and $t1,$t2,$t3 → 1100 AND 0101 = 0100 → $t1 = 4
or  $t1,$t2,$t3 → 1100 OR  0101 = 1101 → $t1 = 13
slt $t1,$t2,$t3 → is 12 < 5? No → $t1 = 0
slt $t1,$t3,$t2 → is 5 < 12? Yes → $t1 = 1
Next PC = 0x00400000 + 4 = 0x00400004
```

**Control signals (clarification):** RegDst 1, ALUSrc 0, MemtoReg 0, RegWrite 1,
MemRead 0, MemWrite 0, Branch 0, ALU op = add/sub/and/or/slt from funct.

**On-screen revision points:**
- R-type: Reg[rd] ← Reg[rs] op Reg[rt]; PC ← PC + 4.
- slt rd, rs, rt: if (rs < rt) rd = 1 else rd = 0.

---

## Scene 2.10 — Instruction Class 2a: Load Word (LW)

**Visual directions:** Load path lights up in blue — the longest path; a
"longest path" badge appears.

**Diagram instructions — highlighted path:**
```
PC → Instruction memory
  [25:21] rs → Read register 1 → Read data 1 → ALU A
  [15:0] offset → Sign-extend (16→32) → ALUSrc mux (1) → ALU B
ALU result (address) → Data memory Address; MemRead = 1
Data memory Read data → MemtoReg mux (1) → Write data
  [20:16] rt → RegDst mux (0) → Write register
PC → Add(+4) → PC
```

**Narration:**
> **Instruction:** `lw $t0, 32($s3)`.
> **Purpose:** load the word at address $s3 + 32 into $t0. This is base addressing.
> **Hardware involved:** PC, instruction memory, PC adder, register file,
> sign-extension unit, ALU, data memory, and the multiplexors — load uses every major
> unit.
> **Data flow:**
> One — fetch the instruction; compute PC + 4.
> Two — read register rs, $s3. Only one register is needed.
> At the same time, the 16-bit offset, 32, is sign-extended to 32 bits.
> Three — ALUSrc is 1, so the ALU's second input is the sign-extended offset. The ALU
> adds: base plus offset equals the address.
> Four — the address goes to data memory with MemRead equal to 1. The memory outputs
> the word stored there.
> Five — MemtoReg is 1, so the memory data, not the ALU result, goes to the register
> file. RegDst is 0, so the destination is rt — $t0. RegWrite is 1.
> PC becomes PC + 4.
> Because lw passes through instruction memory, register file, ALU, data memory and
> back to the register file, it is the **longest path** — and in a single-cycle
> design, the clock must be long enough for it.

**Worked example:**
```
$s3 = 0x10010000, Memory[0x10010020] = 99
Sign-extend(32) = 0x00000020
ALU: 0x10010000 + 0x00000020 = 0x10010020
Data memory read → 99 → $t0 = 99
```

**Control signals (clarification):** RegDst 0, ALUSrc 1, MemtoReg 1, RegWrite 1,
MemRead 1, MemWrite 0, Branch 0, ALU op = add.

**On-screen revision points:**
- lw: Reg[rt] ← Mem[Reg[rs] + sign-ext(offset)].
- Uses ALL five phases → longest instruction.

---

## Scene 2.11 — Instruction Class 2b: Store Word (SW)

**Visual directions:** Store path lights up in purple. Write-back arrow is crossed
out with a red X.

**Diagram instructions — highlighted path:**
```
  [25:21] rs → Read register 1 → Read data 1 → ALU A
  [20:16] rt → Read register 2 → Read data 2 → Data memory "Write data"
  [15:0]  → Sign-extend → ALUSrc mux (1) → ALU B
ALU result → Data memory Address; MemWrite = 1
No register write (RegWrite = 0)
```

**Narration:**
> **Instruction:** `sw $t0, 48($s3)`.
> **Purpose:** store the value in $t0 into memory at $s3 + 48.
> **Data flow:**
> One — fetch, and PC + 4.
> Two — read **two** registers: rs, $s3, the base; and rt, $t0, the data to store.
> Three — ALUSrc is 1; the ALU adds base and sign-extended offset to form the address.
> Four — the address goes to data memory, read data 2 goes to the "write data"
> input, and MemWrite is 1. The word is written.
> Five — there is **no write-back**. RegWrite is 0. RegDst and MemtoReg do not
> matter — we call them "don't care", shown as X.

**Worked example:**
```
$s3 = 0x10010000, $t0 = 57
Address = 0x10010000 + 48 (0x30) = 0x10010030
Memory[0x10010030] ← 57
```

**Control signals (clarification):** RegDst X, ALUSrc 1, MemtoReg X, RegWrite 0,
MemRead 0, MemWrite 1, Branch 0, ALU op = add.

**On-screen revision points:**
- sw: Mem[Reg[rs] + sign-ext(offset)] ← Reg[rt]. No write-back.

---

## Scene 2.12 — Instruction Class 3: Branch Equal (BEQ)

**Visual directions:** Branch path lights up in orange. Two parallel computations
animate side by side: "compare" (ALU) and "target" (adder).

**Diagram instructions — highlighted path (from notes' Figure 2.5):**
```
  rs → Read data 1 → ALU A
  rt → Read data 2 → ALUSrc mux (0) → ALU B ; ALU op = subtract → Zero
  [15:0] → Sign-extend → Shift left 2 → Add (with PC + 4) → Branch target
PCSrc = Branch AND Zero → top mux → PC
```

**Narration:**
> **Instruction:** `beq $t1, $t2, offset`.
> **Purpose:** if $t1 equals $t2, go to the branch target; otherwise continue.
> The notes say the branch datapath must do **two operations**: compute the branch
> target address, and compare the register contents.
> **Data flow:**
> One — fetch, and compute PC + 4.
> Two — read rs and rt.
> Three — two things happen in parallel. The ALU **subtracts** rt from rs. If they
> are equal, the result is zero and the ALU's **Zero** output becomes 1.
> Meanwhile, a separate adder computes the branch target: PC + 4 plus the sign-
> extended offset shifted left 2.
> Four — no memory access. Five — no register write.
> PC update: the Branch control signal is 1. If Zero is also 1, the AND gate outputs
> 1, and the PC receives the branch target — the **branch is taken**. If Zero is 0,
> the PC receives PC + 4 — the **branch is not taken**.
> Notice that the shift left 2 unit needs no real hardware. As the notes explain,
> it is simply a routing of wires that adds two zero bits to the low end.

**Worked example:**
```
PC = 0x00400010, offset = 3, PC + 4 = 0x00400014
Target = 0x00400014 + (3 << 2) = 0x00400014 + 12 = 0x00400020

Case A: $t1 = 9, $t2 = 9 → ALU 9 − 9 = 0 → Zero = 1
        PCSrc = 1 AND 1 = 1 → PC = 0x00400020 (taken)
Case B: $t1 = 9, $t2 = 4 → ALU 9 − 4 = 5 → Zero = 0
        PCSrc = 1 AND 0 = 0 → PC = 0x00400014 (not taken)
```

**Control signals (clarification):** RegDst X, ALUSrc 0, MemtoReg X, RegWrite 0,
MemRead 0, MemWrite 0, Branch 1, ALU op = subtract.

**On-screen revision points:**
- **Branch taken**: condition satisfied, PC becomes branch target.
- **Branch not taken (untaken)**: condition false, PC = address of next sequential
  instruction.
- Zero flag = 1 when ALU result is 0, i.e. rs = rt.

---

## Scene 2.13 — Instruction Class 4: Jump (J)

**Visual directions:** Tag "Clarification — jump hardware is not drawn in the notes".
A small addition to the datapath: a "Shift left 2" on instruction bits [25:0], a
concatenation with PC+4[31:28], and a "Jump" mux in front of the PC.

**Diagram instructions:**
```
instruction[25:0] (26) → Shift left 2 → 28 bits ─┐
PC+4[31:28] (4) ──────────────────────────────────┴─► Jump address (32)
Jump mux: input 0 = output of branch mux, input 1 = jump address → PC
```

**Narration:**
> **Instruction:** `j L`. **Purpose:** unconditionally go to label L.
> The notes say the jump instruction operates by replacing the lower 28 bits of the
> PC with the lower 26 bits of the instruction shifted left by 2 bits. Simply
> concatenating 00 to the jump offset accomplishes this shift.
> This is pseudodirect addressing from Topic 1.
> **Data flow:** fetch the instruction; take bits 25 to 0; append two zeros to get
> 28 bits; place the upper 4 bits of the PC in front; and send this through a jump
> multiplexor into the PC.
> The ALU, registers and data memory are not used. Jump has no register reads, no
> ALU operation, no memory access and no write-back. RegWrite and MemWrite must be 0
> so that nothing is changed by accident.

**Worked example:** PC = 0x00400018, target field = 0x0100008 →
`0000 ‖ 0x0100008 << 2 = 0x00400020`.

**Control signals (clarification):** Jump 1, RegWrite 0, MemWrite 0, MemRead 0,
Branch 0, others X.

---

## Scene 2.14 — Summary Table of All Instruction Classes

**Visual directions:** Full-screen summary with coloured rows matching the path
colours used earlier.

**On-screen revision points:**
| Instr. | Fetch | Reg read | ALU | Memory | Write-back | Next PC |
|---|---|---|---|---|---|---|
| add/sub/and/or/slt | ✔ | rs, rt | operation | — | rd ← ALU | PC+4 |
| lw | ✔ | rs | rs + offset | read | rt ← Mem | PC+4 |
| sw | ✔ | rs, rt | rs + offset | write | — | PC+4 |
| beq | ✔ | rs, rt | rs − rt (Zero) | — | — | Zero ? target : PC+4 |
| j | ✔ | — | — | — | — | PC[31:28] ‖ addr ‖ 00 |

**Control-signal truth table (clarification, Patterson & Hennessy):**
| Instr. | RegDst | ALUSrc | MemtoReg | RegWrite | MemRead | MemWrite | Branch | ALUOp |
|---|---|---|---|---|---|---|---|---|
| R-type | 1 | 0 | 0 | 1 | 0 | 0 | 0 | 10 |
| lw | 0 | 1 | 1 | 1 | 1 | 0 | 0 | 00 |
| sw | X | 1 | X | 0 | 0 | 1 | 0 | 00 |
| beq | X | 0 | X | 0 | 0 | 0 | 1 | 01 |

**Narration:**
> Here is everything in one table. Look how much is shared: every instruction fetches
> the same way, most use the ALU, and only a few control signals change between
> classes. This is exactly what the notes mean by "the simplicity and regularity of
> the MIPS instruction set simplifies the implementation".
> Finally, a limitation from the notes: this single-cycle design is easy to
> understand but **not practical**, because the clock cycle must be stretched to fit
> the **longest** instruction — the load. Every instruction, even a simple add, must
> take that long. The fix — pipelining — is mentioned in the notes as a later topic.

**Exam points for Topic 2:**
- First two steps identical for all instructions: fetch, read registers.
- ALU used for: address (lw/sw), operation (R), comparison (beq).
- Three multiplexors and their purposes (notes' Figure 1.2).
- Single-cycle design is impractical: clock set by the longest instruction.

---

*End of Part 2. Continue with Part 3 — Hardware Structure.*
