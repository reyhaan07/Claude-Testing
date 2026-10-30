# PART 5 — Topics 8 to 10 and the Final Revision

---

## Scene 8.1 — Topic 8: Instructions — Language of the Computer

**Visual directions:** Heading "TOPIC 8 — OPERATIONS AND OPERANDS". A dictionary
icon labelled "Instruction set" with words inside labelled "instructions".

**Narration:**
> The notes put it simply: the words of a computer's language are called
> **instructions**, and its vocabulary is called an **instruction set**.
> Every instruction has an **operation** — what to do — and **operands** — what to do
> it on. MIPS has three kinds of operands: register operands, memory operands, and
> constant or immediate operands. Then we look at four kinds of operations: arithmetic,
> data transfer, logical, and conditional.

---

## Scene 8.2 — Register Operands

**Visual directions:** The 32-register file with assembler names. Then the C-to-MIPS
example from the notes animated with values.

**Narration:**
> **Register operands.** Arithmetic instructions use register operands. MIPS has a
> **32 × 32-bit register file** — 32 registers, each 32 bits. They are used for
> frequently accessed data, numbered 0 to 31. 32-bit data is called a **word**.
> Assembler names: $t0 to $t9 for **temporary** values, and $s0 to $s7 for **saved**
> variables.
> The notes' example: the C statement f = (g + h) − (i + j), with f, g, h, i, j in $s0
> to $s4.

**Worked example:**
```
f = (g + h) - (i + j);    f→$s0, g→$s1, h→$s2, i→$s3, j→$s4
Given g = 10, h = 20, i = 3, j = 4

add $t0, $s1, $s2   # $t0 = g + h = 10 + 20 = 30    dest $t0, sources $s1,$s2
add $t1, $s3, $s4   # $t1 = i + j = 3 + 4  = 7      dest $t1, sources $s3,$s4
sub $s0, $t0, $t1   # f   = 30 − 7          = 23     dest $s0, sources $t0,$t1
```

**Narration (continued):**
> The compiler uses two temporaries. First $t0 holds g + h, which is 30. Then $t1 holds
> i + j, which is 7. Finally $s0, which is f, gets 30 minus 7, which is 23. In every
> instruction the **first** register is the destination and the next two are sources.

---

## Scene 8.3 — Memory Operands

**Visual directions:** Memory strip showing byte addresses; a word spanning 4 bytes.
Then a Big-Endian vs Little-Endian side-by-side for the word 0x12345678.

**Diagram instructions:**
```
Word 0x12345678 stored at address 100:
Big Endian (MIPS):    100: 12   101: 34   102: 56   103: 78
Little Endian:        100: 78   101: 56   102: 34   103: 12
```

**Narration:**
> **Memory operands.** Main memory is used for composite data — arrays, structures and
> dynamic data. To apply arithmetic operations, we **load** values from memory into
> registers, and **store** results from registers back to memory.
> Memory is **byte addressed** — each address identifies an 8-bit byte.
> Words are **aligned** in memory: a word address must be a multiple of 4.
> MIPS is **Big Endian**: the most-significant byte is at the lowest address of a word.
> Compare **Little Endian**, where the least-significant byte is at the lowest address.
> The data-transfer examples — g = h + A[8] and A[12] = h + A[8] — were worked fully in
> Topic 1, scenes 1.8 and 1.9.

**On-screen revision points:**
- Byte addressed; aligned words (address multiple of 4); MIPS = Big Endian.

---

## Scene 8.4 — Constant or Immediate Operands

**Narration:**
> **Immediate operands** are constant data specified in an instruction, for example
> `addi $s3, $s3, 4`. There is **no subtract-immediate** instruction — just use a
> negative constant: `addi $s2, $s1, -1`. Both were worked in Topic 1, scene 1.4.

---

## Scene 8.5 — Arithmetic and Data-Transfer Operations

**Visual directions:** Two cards.

**Narration:**
> **Arithmetic operations:** add and subtract use **three operands** — two sources and
> one destination. Example: `add $t0, $s1, $s2`.
> **Data-transfer operations** move data between memory and registers: `lw` loads and
> `sw` stores. In `lw $t0, 32($s3)`, 32 is the **offset** and $s3 is the **base
> register** — exactly the labels used in the notes.

---

## Scene 8.6 — Logical Operations: Shift, AND, OR, NOR

**Visual directions:** The notes' table, then 32-bit registers with the highlighted
bit columns from the notes' figures.

**On-screen table (from notes):**
| Operation | C | Java | MIPS |
|---|---|---|---|
| Shift left | << | << | sll |
| Shift right | >> | >>> | srl |
| Bitwise AND | & | & | and, andi |
| Bitwise OR | \| | \| | or, ori |
| Bitwise NOT | ~ | ~ | nor |

**Worked examples (values from the notes' figures):**
```
$t2 = 0000 0000 0000 0000 0000 1101 1100 0000  (0x00000DC0)
$t1 = 0000 0000 0000 0000 0011 1100 0000 0000  (0x00003C00)

and $t0, $t1, $t2 → 0000 0000 0000 0000 0000 1100 0000 0000  (0x00000C00)
or  $t0, $t1, $t2 → 0000 0000 0000 0000 0011 1101 1100 0000  (0x00003DC0)
NOT $t1 (nor $t0, $t1, $zero)
                  → 1111 1111 1111 1111 1100 0011 1111 1111  (0xFFFFC3FF)

sll $t2, $s0, 4 with $s0 = 9 (0000 1001) → 1001 0000 = 144 = 9 × 2⁴
srl $t2, $s0, 2 with $s0 = 36           → 9           = 36 ÷ 2²
```

**Narration:**
> Logical instructions manipulate individual bits — useful for extracting and inserting
> groups of bits in a word.
> **Shifts** use the R-format, and the **shamt** field says how many positions to shift.
> **Shift left logical** shifts left and fills with zeros; shifting left by i bits
> multiplies by 2 to the power i. **Shift right logical** fills with zeros; shifting
> right by i bits divides by 2 to the power i — unsigned numbers only. (The notes write
> "2i"; it means 2 to the power i.) So 9 shifted left by 4 is 144, which is 9 times 16.
> **AND** is useful to **mask** bits: it selects some bits and clears the others to 0.
> Look at the shaded column: only where both $t1 and $t2 have a 1 do we get a 1.
> **OR** is used to **include** bits: it sets some bits to 1 and leaves the others
> unchanged.
> **NOT** inverts every bit. MIPS has no NOT instruction; it uses **NOR** with $zero,
> because A NOR 0 equals NOT A.

---

## Scene 8.7 — Conditional Operations and Decision Making

**Visual directions:** The notes' if-else flowchart: diamond "i == j?", left box
"f = g + h", right box "Else: f = g − h", both merging to "Exit".

**Narration:**
> Based on input data and computed values, different instructions execute. MIPS has two
> decision-making instructions, similar to an if statement with a go-to.
> `beq register1, register2, L1` — **branch if equal**: go to L1 if the two registers
> are equal.
> `bne register1, register2, L1` — **branch if not equal**: go to L1 if they differ.
> These are called **conditional branches**. And `j L1` is an **unconditional jump** to
> L1. (The notes list `j L1` on the same line as `slt`; they are separate instructions.)

**Worked example — compiling IF (from the notes):**
```
if (i == j) f = g + h; else f = g - h;     f,g,h,i,j in $s0..$s4

      bne $s3, $s4, Else    # if i ≠ j go to Else
      add $s0, $s1, $s2     # f = g + h   (skipped if i ≠ j)
      j   Exit              # skip the else part
Else: sub $s0, $s1, $s2     # f = g − h
Exit: ...

Trace 1: i = 5, j = 5 → bne not taken → f = g + h → j Exit
Trace 2: i = 5, j = 7 → bne taken → Else: f = g − h
(The assembler calculates the addresses of Else and Exit.)
```

**Narration (continued):**
> Notice the compiler tests the **opposite** condition — bne — so it can skip the
> then-part. The `j Exit` jumps over the else-part.

**Worked example — compiling a loop (from the notes):**
```
while (save[i] == k) i += 1;     i in $s3, k in $s5, base of save in $s6

Loop: sll  $t1, $s3, 2      # $t1 = i × 4 (byte offset)
      add  $t1, $t1, $s6    # $t1 = address of save[i]
      lw   $t0, 0($t1)      # $t0 = save[i]
      bne  $t0, $s5, Exit   # exit if save[i] ≠ k
      addi $s3, $s3, 1      # i = i + 1
      j    Loop
Exit: ...

Trace: $s6 = 2000, k = 7, save[0] = 7, save[1] = 7, save[2] = 3, i = 0
 i=0: $t1 = 0 → 2000 → save[0]=7 = k → i = 1
 i=1: $t1 = 4 → 2004 → save[1]=7 = k → i = 2
 i=2: $t1 = 8 → 2008 → save[2]=3 ≠ k → Exit.  Final i = 2
```

**Narration (continued):**
> sll by 2 multiplies i by 4 to get the byte offset. Adding the base gives the address.
> lw reads save[i]. bne exits when it differs from k. Otherwise i is incremented and we
> jump back. This loop uses four addressing modes at once: register (add), immediate
> (addi), base (lw), PC-relative (bne) — and pseudodirect for j.

---

## Scene 8.8 — More Conditional Operations: slt, slti, Signed vs Unsigned

**Worked example (from the notes):**
```
slt  rd, rs, rt        if (rs < rt) rd = 1; else rd = 0;
slti rt, rs, constant  if (rs < constant) rt = 1; else rt = 0;

Used with beq/bne:
slt $t0, $s1, $s2      # $t0 = 1 if $s1 < $s2
bne $t0, $zero, L      # branch to L if it was less

Signed vs unsigned:
$s0 = 1111 1111 1111 1111 1111 1111 1111 1111
$s1 = 0000 0000 0000 0000 0000 0000 0000 0001
slt  $t0, $s0, $s1  # signed:   −1 < +1             → $t0 = 1
sltu $t0, $s0, $s1  # unsigned: 4,294,967,295 > +1  → $t0 = 0
```

**Narration:**
> slt — set on less than — sets the destination to 1 if the first source is less than
> the second, otherwise 0. slti compares with a constant. Combined with bne and $zero,
> they make "branch if less than".
> The same bit pattern means different things signed and unsigned. All ones is −1 as a
> signed number, so slt says −1 is less than +1, giving 1. As an unsigned number it is
> about 4.29 billion, so sltu gives 0.

---

## Scene 8.9 — Jump and Link, Jump Register (procedures)

**Narration:**
> For procedures, the notes give two more instructions.
> `jal ProcedureLabel` — **jump and link**: the address of the following instruction is
> put in register **$ra**, the return address, and then it jumps to the target.
> `jr $ra` — **jump register**: copies $ra into the program counter, returning from the
> procedure. jr can also be used for computed jumps, for example case/switch statements.

**On-screen revision points (Topic 8):**
- Instruction set = vocabulary; instruction = word.
- Operands: register (32 × 32-bit), memory (byte addressed, aligned, Big Endian),
  immediate (no subi).
- Operations: arithmetic, data transfer, logical (sll, srl, and, or, nor),
  conditional (beq, bne, slt, slti, j, jal, jr).

---

## Scene 9.1 — Topic 9: Instruction Representation

**Visual directions:** Heading "TOPIC 9 — REPRESENTING INSTRUCTIONS". A line of
assembly turns into a row of 0s and 1s.

**Narration:**
> Instructions are encoded in binary, called **machine code**. MIPS instructions are
> encoded as **32-bit instruction words**, using a small number of formats that encode
> the operation code — **opcode** — and register numbers.
> Register numbers from the notes: $t0 to $t7 are registers 8 to 15; $t8 and $t9 are 24
> and 25; $s0 to $s7 are 16 to 23.

---

## Scene 9.2 — R-Format Field by Field

**Diagram instructions:**
```
| op     | rs     | rt     | rd     | shamt  | funct  |
| 31–26  | 25–21  | 20–16  | 15–11  | 10–6   | 5–0    |
| 6 bits | 5 bits | 5 bits | 5 bits | 5 bits | 6 bits |   total = 32
```

**Narration:**
> **op** — the operation code, 6 bits.
> **rs** — the first source register number, 5 bits.
> **rt** — the second source register number, 5 bits.
> **rd** — the destination register number, 5 bits.
> **shamt** — shift amount, 5 bits; zero for non-shift instructions.
> **funct** — function code, 6 bits, which extends the opcode and selects the variant.
> 6 + 5 + 5 + 5 + 5 + 6 = 32.

**Worked example — `add $t0, $s1, $s2` (notes):** 0 | 17 | 18 | 8 | 0 | 32 →
`000000 10001 10010 01000 00000 100000` = **0x02324020**.

**Worked example — `sub $s0, $t0, $t1`:**
```
op=0 000000 | rs=$t0=8 01000 | rt=$t1=9 01001 | rd=$s0=16 10000 | shamt 00000 | funct=34 100010
= 0000 0001 0000 1001 1000 0000 0010 0010 = 0x01098022
```

**Worked example — `sll $t2, $s0, 4`:** op 0, rs 0 (unused), rt = $s0 = 16, rd =
$t2 = 10, shamt = 4, funct = 0.

---

## Scene 9.3 — I-Format Field by Field

**Diagram instructions:**
```
| op     | rs     | rt     | constant or address |
| 31–26  | 25–21  | 20–16  | 15–0                |
| 6 bits | 5 bits | 5 bits | 16 bits             |   total = 32
```

**Narration:**
> The I-format is used for **immediate arithmetic** and **load/store** instructions.
> **rt** is the destination or source register number.
> The **constant** ranges from −2 to the 15 up to 2 to the 15 minus 1 — that is −32,768
> to +32,767.
> The **address** is an offset added to the base address in **rs**.
> Example from the notes: `lw $t0, 32($s3)` — temporary register $t0 gets A[8]. 19 for
> $s3 goes in rs, 8 for $t0 goes in rt, 32 goes in the address field. The notes stress:
> in a load, rt is the **destination**.
> Why have more than one format? A compromise: keeping all instructions 32 bits long,
> while allowing both three-register instructions and instructions with useful 16-bit
> constants.

**Worked examples:** `lw $t0,32($s3)` = 0x8E680020; `sw $t0,48($s3)` = 0xAE680030;
`addi $s3,$s3,4` = 0x22730004 (all derived in Part 1).

**On-screen table (from notes):**
| Instruction | Format | op | rs | rt | rd | shamt | funct | address |
|---|---|---|---|---|---|---|---|---|
| add | R | 0 | reg | reg | reg | 0 | 32 | n.a. |
| sub | R | 0 | reg | reg | reg | 0 | 34 | n.a. |
| addi | I | 8 | reg | reg | n.a. | n.a. | n.a. | constant |
| lw | I | 35 | reg | reg | n.a. | n.a. | n.a. | address |
| sw | I | 43 | reg | reg | n.a. | n.a. | n.a. | address |

> "reg" means a register number 0–31; "address" means a 16-bit address; "n.a." means
> the field does not appear in that format. add and sub share op 0; the hardware uses
> funct to decide: 32 for add, 34 for subtract.

---

## Scene 9.4 — J-Format Field by Field

**Diagram instructions:**
```
| opcode  | target  |
| 31–26   | 25–0    |
| 6 bits  | 26 bits |   total = 32

PC ← PC[31:28] ‖ IR[25:0] ‖ 00
```

**Narration:**
> J-type is short for "jump type". It has a 6-bit opcode in bits 31 to 26 and a 26-bit
> target in bits 25 to 0. The semantics: PC gets the upper 4 bits of the program counter,
> followed by the 26 target bits — the lower 26 bits of the instruction register —
> followed by two zeros, creating a 32-bit address. Worked in Topic 1, scene 1.13.

**On-screen revision points (Topic 9):**
| Format | Fields (bits) | Examples |
|---|---|---|
| R | op 6, rs 5, rt 5, rd 5, shamt 5, funct 6 | add, sub, and, or, slt, sll, srl, jr |
| I | op 6, rs 5, rt 5, constant/address 16 | addi, lw, sw, beq, bne, slti, andi, ori |
| J | op 6, target 26 | j, jal |

---

## Scene 10.1 — Topic 10: Building a Datapath — The Approach

**Visual directions:** Heading "TOPIC 10 — BUILDING A DATAPATH". An empty canvas;
pieces will be added in five stages, each stage shown with a stage number.

**Narration:**
> The notes say a reasonable way to start a datapath design is to examine the major
> components required to execute each class of MIPS instruction. We look at which
> **datapath elements** each instruction needs, working down through the levels of
> **abstraction**, and showing the control signals as we go.
> We already met every element in Topic 3. Now we build the datapath in stages, the way a
> designer would.

---

## Scene 10.2 — Stage 1: Instruction Fetch and PC + 4

**Visual directions:** Draw notes' Figure 2.2: PC, instruction memory, adder with 4.

**Narration:**
> To execute any instruction, we start by fetching it from memory. To prepare for the
> next instruction, we increment the PC so it points to the next instruction, 4 bytes
> later. Three elements — PC, instruction memory and an adder — form the fetch datapath.

---

## Scene 10.3 — Stage 2: R-Format — Register File and ALU

**Visual directions:** Add the register file and ALU (Figure 2.3) to the right of the
fetch datapath. Wire instruction fields to the register-number inputs.

**Narration:**
> R-format instructions read two registers, perform an ALU operation, and write the
> result. So we add the register file — two read ports, one write port — and the ALU.
> Instruction bits 25–21 and 20–16 go to the read register inputs; the read data go to
> the ALU; the ALU result goes back to write data; RegWrite controls the write.

---

## Scene 10.4 — Stage 3: Loads and Stores — Data Memory and Sign Extension

**Visual directions:** Add data memory and sign-extend unit (Figure 2.4).

**Narration:**
> For lw and sw we also need to **sign-extend** the 16-bit offset to 32 bits, and a
> **data memory** to read from or write to. The data memory is written on stores, so it
> has read and write controls, an address input, and a write-data input.
> The ALU computes base plus offset as the address.

---

## Scene 10.5 — Stage 4: Branches — Shift Left 2 and Branch Adder

**Visual directions:** Draw notes' Figure 2.5: "PC+4 from instruction datapath" →
Add; Sign-extend → Shift left 2 → Add → "Branch target"; Registers → ALU → Zero →
"To branch control logic".

**Narration:**
> For beq we add a sign-extension path, a **shift left 2**, and a separate **adder** to
> compute the branch target from PC + 4. The ALU does the comparison and its Zero output
> goes to the branch control logic, which decides whether PC + 4 or the branch target
> replaces the PC.
> Two definitions from the notes:
> **Branch target address**: the address specified in a branch, which becomes the new
> PC if the branch is taken — the sum of the offset field and the address of the
> instruction following the branch.
> **Delayed branch**: a branch where the instruction immediately following it is always
> executed, whether or not the condition is true. MIPS uses delayed branches because of
> pipelining, but our simple design ignores them.

---

## Scene 10.6 — Stage 5: Creating a Single Datapath — Sharing with Multiplexors

**Visual directions:** The R-type and memory datapaths overlap; the two conflict
points glow red; multiplexors drop in to resolve them.

**Narration:**
> The notes say R-type and memory datapaths are quite similar. The key differences:
> One — arithmetic-logical instructions use the ALU with **both inputs from registers**;
> memory instructions use the ALU for the address, with the second input the
> **sign-extended 16-bit offset**. Fix: a multiplexor — ALUSrc — at the ALU's second input.
> Two — the value stored into the destination register comes from the **ALU** for R-type
> or from **memory** for a load. Fix: a multiplexor — MemtoReg — at the write-data input.
> This simplest datapath executes every instruction in **one clock cycle**. So no
> datapath resource can be used more than once per instruction, and any element needed
> more than once must be **duplicated**. That is why we have separate **instruction and
> data memories**, and separate adders besides the ALU.
> But many elements can be **shared** by different instruction flows. To share an element
> between instruction classes, we allow multiple connections to its input, using a
> **multiplexor** and a **control signal** to select among them.
> Adding the PCSrc multiplexor to integrate branches completes Figure 4.11 — the complete
> datapath from Topic 3. Adding the jump path and the RegDst multiplexor (clarifications
> from Topic 2) completes support for our whole subset.

**On-screen revision points (Topic 10):**
- Stage order: fetch → R-type (registers + ALU) → load/store (data memory +
  sign-extend) → branch (shift left 2 + adder) → combine with muxes + control.
- Single cycle → no resource used twice → separate instruction and data memories.
- Sharing → multiplexors + control signals.

---

# FINAL REVISION SECTION

---

## Scene R.1 — Complete Unit 3 Recap

**Visual directions:** The roadmap from Scene 0.1 returns; every box is now ticked.

**Narration:**
> We have covered all of Unit 3. Let us revise everything, quickly and clearly.
> We began with the five MIPS addressing modes, saw how a basic MIPS implementation
> executes lw, sw, add, sub, and, or, slt, beq and j, and studied each hardware component.
> Then we learned the eight great ideas, the five functional units, how a stored program
> is executed step by step, how performance is measured, the MIPS operations and operands,
> the three instruction formats, and how the datapath is built.

---

## Scene R.2 — Revision: Five Functional Units

**On-screen:** Input → Memory (primary: RAM, ROM, cache; secondary: disks, tapes, CD-ROM)
→ ALU → Output; Control unit = nerve centre generating timing signals.

**Narration:**
> Input accepts coded information. Memory stores programs and data. The ALU performs
> operations using registers. Output sends results out. Control coordinates everything.

---

## Scene R.3 — Revision: Eight Great Ideas

**On-screen:** Moore's Law · Abstraction · Common case fast · Parallelism · Pipelining ·
Prediction · Hierarchy of memories · Dependability via redundancy.

**Narration:**
> Remember them as a story: plan for **Moore's Law**; tame complexity with
> **abstraction**; speed up the **common case**; do things in **parallel**; overlap them
> with **pipelining**; don't wait — **predict**; use a **hierarchy** of memories; and
> survive failures with **redundancy**.

---

## Scene R.4 — Revision: CPU Performance Equations

**On-screen:**
```
Performance = 1 / Execution time
Performance_X / Performance_Y = Execution time_Y / Execution time_X = n
CPU time = CPU clock cycles × Clock cycle time = CPU clock cycles / Clock rate
CPU clock cycles = Instruction count × CPI
CPU time = Instruction count × CPI × Clock cycle time
CPU time = User CPU time + System CPU time
```

**Narration:**
> Performance is one over execution time. To say X is n times as fast as Y, divide
> the slower time by the faster time.
> CPU time is clock cycles times clock cycle time, or clock cycles divided by clock
> rate.
> Clock cycles are instruction count times CPI.
> So the master equation is: CPU time equals instruction count, times CPI, times clock
> cycle time.
> And CPU time is user CPU time plus system CPU time. Always convert units first, and
> show every step.

---

## Scene R.5 — Revision: Instruction Formats

**On-screen:**
```
R: op6 | rs5 | rt5 | rd5 | shamt5 | funct6   = 32
I: op6 | rs5 | rt5 | constant/address16     = 32
J: op6 | target26                           = 32
Opcodes: R-type 0 (add funct 32, sub funct 34), addi 8, lw 35, sw 43
```

**Narration:**
> Three formats, all exactly 32 bits.
> R-format: op 6, rs 5, rt 5, rd 5, shamt 5, funct 6. Used by add, sub, and, or and slt.
> I-format: op 6, rs 5, rt 5, and a 16-bit constant or address. Used by addi, lw, sw and
> beq.
> J-format: op 6 and a 26-bit target. Used by j and jal.
> Remember the opcodes: R-type 0, with funct 32 for add and 34 for subtract; addi 8;
> lw 35; sw 43.

---

## Scene R.6 — Revision: Addressing Modes

**On-screen:**
```
1 Immediate     operand = 16-bit constant in instruction         addi
2 Register      operand = register                                 add
3 Base          EA = Reg[rs] + sign-ext(offset)                    lw, sw
4 PC-relative   target = PC + 4 + (sign-ext(offset) << 2)          beq, bne
5 Pseudodirect  target = PC[31:28] ‖ address26 ‖ 00                j, jal
```

**Narration:**
> The five addressing modes.
> Immediate: the operand is a 16-bit constant inside the instruction, as in addi.
> Register: the operand is a register, as in add.
> Base or displacement: the effective address is the base register plus the
> sign-extended offset, as in lw and sw.
> PC-relative: the branch target is PC plus 4, plus the offset shifted left by 2, as in
> beq and bne.
> Pseudodirect: the jump address is the upper 4 bits of the PC, joined to the 26-bit
> address, joined to two zeros, as in j and jal.

---

## Scene R.7 — Revision: Instruction Execution Sequence

**On-screen (two views):**
```
Basic operational concepts:
PC → MAR → Read → MDR → IR → decode → operands (MAR/MDR) → ALU → result (MDR/MAR, write) → PC + 1 word

MIPS datapath:
Fetch (PC → instruction memory; PC + 4) → Read registers → ALU → Memory (lw/sw) → Write-back (R, lw) → PC update
```

**Narration:**
> Two views of the same idea.
> In the basic operational concepts, the PC goes to the MAR, memory is read, the word
> arrives in the MDR, and moves to the IR. The instruction is decoded, operands are
> fetched through the MAR and MDR, the ALU operates, the result is stored, and the PC
> moves to the next instruction.
> In the MIPS datapath: fetch the instruction and compute PC plus 4, read the registers,
> use the ALU, access memory for loads and stores, write back for R-type and loads, and
> update the PC.

---

## Scene R.8 — Revision: Complete Datapath and Component Functions

**Visual directions:** Full labelled datapath (Scene 3.12) one final time; each
component flashes as named.

**Narration:**
> PC — address of the current instruction. Instruction memory — supplies the instruction.
> Adder — PC + 4. Register file — two reads, one write. Sign-extend — 16 to 32 bits.
> ALUSrc mux — register or immediate. ALU — operate, compute address, or compare; Zero
> flag. Data memory — load and store. MemtoReg mux — ALU or memory to register. Shift left
> 2 and branch adder — branch target. PCSrc mux — PC + 4 or target, selected by Branch AND
> Zero. Control unit — decodes the opcode and drives every control line.

---

## Scene R.9 — Final Exam-Oriented Checklist

**Visual directions:** A checklist with tick boxes, each ticking as it is read.

**On-screen checklist:**
- [ ] Define ISA, microarchitecture, systems design; compare CISC and RISC.
- [ ] List and explain all eight great ideas with an example each.
- [ ] Draw the five-functional-unit block diagram; define word, word length, address,
      RAM, ROM, cache, access time; primary vs secondary memory.
- [ ] Explain the 12 operating steps for `Add LOCA, R0` using PC, MAR, MDR, IR.
- [ ] Define interrupt and interrupt service routine.
- [ ] Define response time, throughput, CPU time, user and system CPU time, CPI.
- [ ] Write and apply all performance equations; solve the four problems in the notes.
- [ ] Identify register, memory and immediate operands; Big vs Little Endian.
- [ ] Explain logical ops (sll, srl, and, or, nor) and conditional ops (beq, bne, slt,
      sltu, j, jal, jr); compile an if-else and a while loop.
- [ ] Draw R, I and J formats with bit widths; encode `add $t0,$s1,$s2` and
      `lw $t0,32($s3)`.
- [ ] Define and draw all five addressing modes; compute a PC-relative and a
      pseudodirect target.
- [ ] State the first two steps common to all instructions; explain ALU use per class.
- [ ] Explain the three multiplexors and the control lines (notes' Figure 1.2).
- [ ] Describe each datapath element (PC, memories, register file, ALU, adders,
      sign-extend, shift left 2, muxes, control).
- [ ] Build the datapath in stages and draw the complete single-cycle datapath.
- [ ] Trace R-type, lw, sw and beq through the datapath.
- [ ] Define branch taken, branch not taken, branch target address, delayed branch.
- [ ] Explain why the single-cycle design is impractical.

**Narration:**
> Go through this checklist before your exam. If you can do every item — define it,
> draw it, and work an example — you have mastered Unit 3.
> Thank you for watching, and all the best for your examination.

---

*End of the Unit 3 video script.*
