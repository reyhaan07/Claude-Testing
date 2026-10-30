# PART 1 — Introduction and Topic 1: MIPS Addressing Modes

---

## Scene 0.1 — Welcome and Roadmap

**Visual directions:** Title card: "UNIT III — PROCESSOR AND CONTROL UNIT". Below
it, the syllabus line from the notes scrolls in: *Eight ideas – Functional Units –
Basic Operational Concepts – Performance – Instructions: Language of the Computer –
Operations, Operands – Instruction representation – MIPS addressing modes – A Basic
MIPS implementation – Building a Datapath.*

**Diagram instructions:** A vertical roadmap with 10 numbered boxes. Boxes 1–3
(Addressing Modes, MIPS Implementation, Hardware Structure) are highlighted in gold
with a "PRIORITY" badge. Boxes 4–10 are grey and light up later. A final box
"Final Revision" sits at the bottom.

**Narration:**
> Hello, and welcome to Unit 3 — Processor and Control Unit.
> In this unit we open up the processor and see how it actually works: how an
> instruction is written, how it is stored as bits, how it finds its operands,
> and how the hardware inside the processor executes it.
> We will study this unit in a special order.
> First, three priority topics: MIPS addressing modes, the basic MIPS
> implementation, and the hardware structure of the MIPS processor.
> After those, we cover every remaining topic in the syllabus: the eight great
> ideas, the functional units, basic operational concepts, CPU performance,
> MIPS operations and operands, instruction formats, and building a datapath.
> We will finish with a complete revision section and an exam checklist.
> Because the priority topics come first, I will quickly give you the minimum
> background you need — just enough to understand addressing modes. Every one of
> these background ideas is taught again in full detail later in the video.

**On-screen revision points:**
- Unit 3 = Processor and Control Unit.
- Priority order: Addressing Modes → MIPS Implementation → Hardware Structure.

---

## Scene 0.2 — Minimum Background: Instructions, Registers, Memory

**Visual directions:** Three icons appear one at a time: a "32 registers" cabinet,
a long memory strip with addresses 0, 4, 8, 12 …, and a 32-bit instruction bar.

**Diagram instructions:**
- Register cabinet: 32 drawers labelled `$0 ($zero)`, `$8–$15 ($t0–$t7)`,
  `$16–$23 ($s0–$s7)`, `$24–$25 ($t8–$t9)`, `$31 ($ra)`. Caption: "32 × 32-bit
  register file".
- Memory strip: boxes labelled 0, 4, 8, 12, 16, each 4 bytes wide. Caption:
  "byte addressed; a word = 4 bytes; word addresses are multiples of 4".
- Instruction bar: 32 cells numbered 31 on the left to 0 on the right.

**Narration:**
> Three quick ideas before we start.
> One: an **instruction** is a single command to the processor, such as "add these
> two numbers". In MIPS, every instruction is exactly **32 bits** long.
> Two: a **register** is a very fast storage location inside the processor. MIPS
> has **32 registers**, each 32 bits wide. A 32-bit quantity is called a **word**.
> Registers are numbered 0 to 31, and they also have assembler names. The notes
> tell us: $t0 to $t7 are registers 8 to 15, $s0 to $s7 are registers 16 to 23,
> and $t8, $t9 are registers 24 and 25. Register 0, called $zero, always holds zero.
> Three: **memory** is much larger but slower. MIPS memory is **byte addressed** —
> every address names one 8-bit byte. A word takes 4 bytes, so word addresses are
> multiples of 4: 0, 4, 8, 12 and so on.
> Finally, the **Program Counter**, or PC, is a register that holds the address of
> the instruction currently being executed.

**On-screen revision points:**
- Instruction = 32 bits. Word = 32 bits = 4 bytes.
- 32 registers; $t0–$t7 = 8–15, $s0–$s7 = 16–23, $t8–$t9 = 24–25.
- Memory is byte addressed; word addresses are multiples of 4.
- PC = address of the current instruction.

---

## Scene 0.3 — Minimum Background: The Three Instruction Formats (preview)

**Visual directions:** Three coloured bars stack vertically. Each field slides in
with its bit width. A running total counter on the right adds up to 32.

**Diagram instructions:**
```
R-format:  | op 6 | rs 5 | rt 5 | rd 5 | shamt 5 | funct 6 |   6+5+5+5+5+6 = 32
I-format:  | op 6 | rs 5 | rt 5 |   constant or address 16  |   6+5+5+16   = 32
J-format:  | op 6 |            target address 26            |   6+26       = 32
```
Bit positions printed under each bar: R: 31–26, 25–21, 20–16, 15–11, 10–6, 5–0.
I: 31–26, 25–21, 20–16, 15–0. J: 31–26, 25–0.

**Narration:**
> Addressing modes depend on where each piece of information sits inside the
> 32-bit instruction, so here is a preview of the three MIPS formats. We study
> them field by field in Topic 9.
> **R-format** — "R" for register — has six fields: op, 6 bits; rs, 5 bits; rt,
> 5 bits; rd, 5 bits; shamt, 5 bits; and funct, 6 bits. Six plus five plus five
> plus five plus five plus six is thirty-two.
> **I-format** — "I" for immediate — has op, 6 bits; rs, 5; rt, 5; and a 16-bit
> constant or address. Six plus five plus five plus sixteen is thirty-two.
> **J-format** — "J" for jump — has a 6-bit opcode and a 26-bit target. Six plus
> twenty-six is thirty-two.
> Why are register fields 5 bits? Because 2 to the power 5 is 32, and we have
> exactly 32 registers.

**On-screen revision points:**
- R: 6-5-5-5-5-6. I: 6-5-5-16. J: 6-26. All = 32 bits.
- 5-bit register field because 2⁵ = 32 registers.

---

## Scene 1.1 — What Is an Addressing Mode?

**Visual directions:** Heading "TOPIC 1 — MIPS ADDRESSING MODES". Then the
definition from the notes appears word by word.

**Diagram instructions:** A question mark labelled "operand?" with three arrows
pointing to three possible homes: "inside the instruction", "in a register",
"in memory". A fourth arrow labelled "next instruction?" points to "instruction
memory".

**Narration:**
> Every instruction needs data to work on. That data is called an **operand**.
> The question is: where is the operand, and how does the processor find it?
> The notes define it like this: "Multiple forms of addressing are generically
> called addressing modes. The method used to identify the location of an operand."
> So an **addressing mode** is the rule the processor uses to locate an operand —
> or, for branch and jump instructions, to locate the next instruction.
> The operand could be written directly inside the instruction. It could be in a
> register. Or it could be in memory, and we must calculate its address.
> MIPS has exactly five addressing modes. Let us list them, exactly as the notes do.

**On-screen revision points:**
- **Addressing mode**: the method used to identify the location of an operand.
- MIPS has 5 addressing modes.

---

## Scene 1.2 — The Five MIPS Addressing Modes (overview)

**Visual directions:** The five-mode list from the notes appears, then the notes'
five-part diagram (page 12) is redrawn cleanly.

**Diagram instructions:** Recreate the notes' figure exactly, with the operand box
shaded blue:
1. **Immediate addressing**: `| op | rs | rt | Immediate |` — the Immediate field
   is shaded (operand is inside the instruction).
2. **Register addressing**: `| op | rs | rt | rd | … | funct |` — an arrow from the
   rs/rt/rd field to a box "Registers → Register" (shaded).
3. **Base addressing**: `| op | rs | rt | Address |` — rs selects a "Register" box;
   Register and Address both feed a circle "+"; output arrow to "Memory" with
   cells "Byte | Halfword | Word" (shaded).
4. **PC-relative addressing**: `| op | rs | rt | Address |` — "PC" box and Address
   feed a "+" circle; arrow to "Memory → Word" (shaded).
5. **Pseudodirect addressing**: `| op | Address |` — "PC" box and Address feed a
   circle containing ":" (concatenation); arrow to "Memory → Word" (shaded).

**Narration:**
> Here are the five modes, in the order of the notes.
> One — **Immediate addressing**, where the operand is a constant within the
> instruction itself.
> Two — **Register addressing**, where the operand is a register.
> Three — **Base or displacement addressing**, where the operand is at the memory
> location whose address is the sum of a register and a constant in the instruction.
> Four — **PC-relative addressing**, where the branch address is the sum of the PC
> and a constant in the instruction.
> Five — **Pseudodirect addressing**, where the jump address is the 26 bits of the
> instruction concatenated with the upper bits of the PC.
> Look at the diagram. The shaded box in each row is where the operand lives.
> In mode 1, the operand is 16 bits of the instruction itself. In mode 2, it is a
> register. In mode 3, it is in memory — and it can be a byte, a halfword or a word.
> Modes 4 and 5 are different: they do not find data. They find **instructions** in
> memory — they tell the processor where to go next.
> Now let us study each one in detail with actual numbers.

**On-screen revision points:**
| # | Mode | Operand is… | Used by |
|---|---|---|---|
| 1 | Immediate | 16-bit constant inside instruction | addi, slti, andi, ori |
| 2 | Register | a register | add, sub, and, or, slt |
| 3 | Base / displacement | memory at [register + constant] | lw, sw |
| 4 | PC-relative | instruction at [PC + 4 + offset×4] | beq, bne |
| 5 | Pseudodirect | instruction at [PC upper 4 bits ‖ 26 bits ‖ 00] | j, jal |

---

## Scene 1.3 — Mode 1: Immediate Addressing — Definition and Format

**Visual directions:** Heading "1. Immediate Addressing". The I-format bar
appears; the 16-bit field glows blue with the label "the operand itself".

**Diagram instructions:**
```
addi  $s3, $s3, 4
| op = 8 | rs = 19 ($s3) | rt = 19 ($s3) | immediate = 4 |
|  6     |      5        |      5        |      16       |
```
Arrows: rs → "Register file read" → ALU input A. Immediate → "Sign-extend 16→32"
→ ALU input B. ALU output → back to register rt.

**Narration:**
> Immediate addressing. **Definition:** the operand is a constant within the
> instruction itself.
> "Immediate" means "immediately available" — the processor does not need to go
> to a register or to memory to fetch it. It is already sitting inside the
> instruction that was just fetched.
> Immediate instructions use the **I-format**. The 16-bit field at the right holds
> the constant. The rs field names the source register, and the rt field names the
> destination register.
> The notes give the example: `addi $s3, $s3, 4`. This means: $s3 gets $s3 plus 4.
> The "i" in addi stands for "immediate".
> Step by step:
> Step one — the instruction is fetched.
> Step two — the processor reads register rs, which is $s3.
> Step three — the 16-bit constant 4 is taken straight from the instruction and
> sign-extended to 32 bits so the ALU can use it.
> Step four — the ALU adds them.
> Step five — the result is written back into register rt, which is again $s3.

**On-screen revision points:**
- Immediate: operand = constant inside the instruction. Format: I.
- Constant is 16 bits, range −2¹⁵ to +2¹⁵ − 1, i.e. −32768 to +32767.
  (*Notes print "−215 to +215 − 1"; it means 2¹⁵.*)

---

## Scene 1.4 — Immediate Addressing — Worked Example with Encoding

**Visual directions:** Calculator-style panel. Values appear line by line.

**Diagram instructions:** A two-row register table "before / after" for $s3, and
the 32-bit binary encoding split into coloured fields.

**Worked example:**
```
Instruction:  addi $s3, $s3, 4
Given:        $s3 = 20 before execution

Operand calculation:
  Operand 1 = contents of rs = $s3 = 20        (register addressing)
  Operand 2 = immediate field = 4               (immediate addressing)
  Result    = 20 + 4 = 24  →  $s3 = 24

Encoding:
  op = 8   → 001000
  rs = 19  → 10011
  rt = 19  → 10011
  imm = 4  → 0000 0000 0000 0100
  32 bits: 001000 10011 10011 0000000000000100
  Group in 4s: 0010 0010 0111 0011 0000 0000 0000 0100
  Hex:         0x22730004
```

**Narration:**
> Let us put numbers in. Suppose $s3 holds 20.
> The first operand comes from register $s3 — that is 20.
> The second operand is written inside the instruction — that is 4.
> The ALU computes 20 plus 4 equals 24, and $s3 now holds 24.
> Now let us see how this instruction is stored as bits. The opcode for addi is 8,
> which in 6 bits is 0 0 1 0 0 0. $s3 is register 19, which in 5 bits is
> 1 0 0 1 1. It goes in both rs and rt. The constant 4 in 16 bits is
> thirteen zeros followed by 1 0 0.
> Put all the fields together and group them in fours, and the instruction in
> hexadecimal is 2 2 7 3 0 0 0 4.
> Now, a special point from the notes: MIPS has **no subtract-immediate
> instruction**. To subtract a constant, you just use a negative constant.
> The notes give `addi $s2, $s1, -1`. If $s1 = 10, then $s2 = 10 + (−1) = 9.
> The 16-bit field holds −1 in two's complement, which is 1111 1111 1111 1111,
> hex FFFF. When sign-extended to 32 bits it becomes FFFF FFFF, which is still −1.

**On-screen revision points:**
- `addi $s3,$s3,4` → 0x22730004.
- No `subi`: use `addi $s2,$s1,-1`. −1 in 16 bits = 0xFFFF.
- Exam tip: be able to identify which field holds the immediate (bits 15–0).

---

## Scene 1.5 — Mode 2: Register Addressing — Definition and Format

**Visual directions:** Heading "2. Register Addressing". R-format bar appears;
the rs, rt, rd fields each shoot an arrow into the register file.

**Diagram instructions:**
```
add $t0, $s1, $s2
| op=0 | rs=17 ($s1) | rt=18 ($s2) | rd=8 ($t0) | shamt=0 | funct=32 |
```
Register file drawn with Read register 1 ← rs, Read register 2 ← rt,
Write register ← rd. Read data 1 and Read data 2 → ALU. ALU result → Write data.

**Narration:**
> Register addressing. **Definition:** the operand is a register.
> All the operands — both sources and the destination — are registers. The
> instruction does not contain the data; it contains the **register numbers**,
> 5 bits each.
> This mode is used by the arithmetic and logical R-format instructions: add, sub,
> and, or, and slt.
> Take `add $t0, $s1, $s2`. In words: $t0 gets $s1 plus $s2.
> rs, the first source, is $s1, which is register 17.
> rt, the second source, is $s2, register 18.
> rd, the destination, is $t0, register 8.
> Step by step: the processor uses rs and rt to read two registers, the ALU adds
> the two values, and the result is written to the register named by rd.
> Register addressing is the fastest mode, because registers are inside the
> processor. That is why the notes say registers are "used for frequently accessed
> data".

**On-screen revision points:**
- Register addressing: operand is in a register. Format: R.
- rs = 1st source, rt = 2nd source, rd = destination.

---

## Scene 1.6 — Register Addressing — Worked Example with Encoding

**Visual directions:** Register table before/after; the notes' encoding table for
`add $t0,$s1,$s2` reproduced exactly.

**Worked example:**
```
Given: $s1 = 15, $s2 = 27
add $t0, $s1, $s2
  rs = $s1 = 15,  rt = $s2 = 27
  $t0 = 15 + 27 = 42

Encoding (from the notes):
  field:   op      rs     rt     rd     shamt  funct
  name:    special $s1    $s2    $t0    0      add
  decimal: 0       17     18     8      0      32
  binary:  000000  10001  10010  01000  00000  100000

  32 bits: 0000 0010 0011 0010 0100 0000 0010 0000 = 0x02324020
```

**Narration:**
> Suppose $s1 holds 15 and $s2 holds 27. Then $t0 receives 15 plus 27, which is 42.
> Here is the encoding exactly as in the notes. The op field is 0 — all R-format
> instructions have opcode 0, which the notes call "special". rs is 17, rt is 18,
> rd is 8, shamt is 0, and funct is 32, which means "add".
> In binary: 000000, 10001, 10010, 01000, 00000, 100000.
> Grouping in fours gives hexadecimal 0 2 3 2 4 0 2 0.
> Important exam point: add and sub have the **same opcode**, 0. The hardware uses
> the **funct** field to tell them apart: funct 32 is add, funct 34 is subtract.

**On-screen revision points:**
- `add $t0,$s1,$s2` = 0x02324020.
- R-format op = 0; funct: add = 32, sub = 34.

---

## Scene 1.7 — Mode 3: Base or Displacement Addressing — Definition

**Visual directions:** Heading "3. Base or Displacement Addressing". Notes'
diagram row 3 is animated: register value and 16-bit address slide into the "+"
circle; the sum shoots an arrow into memory.

**Diagram instructions:**
```
lw $t0, 32($s3)
| op=35 | rs=19 ($s3) base | rt=8 ($t0) dest | address/offset = 32 |
     $s3 contents ──┐
                    (+) ──► Effective Address ──► Data Memory ──► $t0
 sign-extend(32) ───┘
```
Label the two inputs of the "+" as "base register" and "offset/displacement",
matching the notes' labels in the data-transfer example.

**Narration:**
> Base or displacement addressing. **Definition from the notes:** the operand is
> at the memory location whose address is the sum of a register and a constant in
> the instruction.
> The register is called the **base register**. The constant is called the
> **offset** or **displacement**. Their sum is the **effective address** — the
> actual memory address of the operand.
> This is the mode used by the load and store instructions, lw and sw, which use
> the I-format.
> In `lw $t0, 32($s3)`, the number outside the brackets, 32, is the offset. The
> register inside the brackets, $s3, is the base register.
> Step by step:
> Step one — read the base register, rs, which is $s3.
> Step two — take the 16-bit offset and sign-extend it to 32 bits.
> Step three — the ALU adds them. This sum is the effective address.
> Step four — read memory at that address.
> Step five — write the loaded word into rt, which is $t0.
> Notice something important: for lw, the **rt field is the destination**, not a
> source. The notes point this out specifically.

**On-screen revision points:**
- **Effective Address = Base register (rs) + sign-extended 16-bit offset.**
- Used by lw, sw (and byte/halfword loads and stores). Format: I.
- In lw, rt = destination register.

---

## Scene 1.8 — Base Addressing — Worked Example: Array Access

**Visual directions:** A memory strip showing array A starting at address 1000:
A[0] at 1000, A[1] at 1004, … A[8] at 1032. A[8] is highlighted.

**Worked example (from the notes' data-transfer example, with values added):**
```
C code:   g = h + A[8];
          g in $s1, h in $s2, base address of A in $s3

Why offset 32?  Index 8 × 4 bytes per word = 32

Given: $s3 = 1000 (base address of A), A[8] = 50, $s2 (h) = 7

lw  $t0, 32($s3)
    Effective address = $s3 + 32 = 1000 + 32 = 1032
    $t0 = Memory[1032] = A[8] = 50
add $s1, $s2, $t0
    $s1 = 7 + 50 = 57   →  g = 57

Encoding of lw $t0, 32($s3):
  op=35   100011
  rs=19   10011
  rt=8    01000
  imm=32  0000 0000 0010 0000
  → 1000 1110 0110 1000 0000 0000 0010 0000 = 0x8E680020
```

**Narration:**
> This is the example from the notes. In C, we have g equals h plus A of 8. g is in
> $s1, h is in $s2, and the starting address of array A is in $s3.
> Why is the offset 32 and not 8? Because memory is byte addressed and each array
> element is a 4-byte word. Element 8 is 8 times 4, which is 32 bytes from the
> start. The notes say: "Index 8 requires offset of 32."
> Now numbers: let $s3 be 1000. The effective address is 1000 plus 32 equals 1032.
> Memory at 1032 holds A of 8, which is 50, so $t0 gets 50.
> Then `add $s1, $s2, $t0` gives 7 plus 50 equals 57.
> The encoding: opcode 35 for lw, rs 19 for $s3, rt 8 for $t0, and 32 in the
> address field. The notes say exactly this: "19 for $s3 is placed in the rs field,
> 8 for $t0 is placed in the rt field, and 32 is placed in the address field."
> In hex the instruction is 8 E 6 8 0 0 2 0.

**On-screen revision points:**
- Byte offset = index × 4.
- `lw $t0,32($s3)` → op 35, rs 19, rt 8, address 32 → 0x8E680020.

---

## Scene 1.9 — Base Addressing — Store Word Example

**Visual directions:** Same memory strip; now A[12] at 1048 is highlighted and an
arrow goes from register to memory (opposite direction to lw).

**Worked example (notes' Example 2):**
```
C code:   A[12] = h + A[8];
          h in $s2, base address of A in $s3

lw  $t0, 32($s3)     # $t0 = A[8]
add $t0, $s2, $t0    # $t0 = h + A[8]
sw  $t0, 48($s3)     # A[12] = $t0      (12 × 4 = 48)

Given $s3 = 1000, A[8] = 50, h = 7:
  lw : EA = 1000 + 32 = 1032 → $t0 = 50
  add: $t0 = 7 + 50 = 57
  sw : EA = 1000 + 48 = 1048 → Memory[1048] = 57  (A[12] = 57)

Encoding of sw $t0, 48($s3):
  op=43 101011 | rs=19 10011 | rt=8 01000 | imm=48 0000 0000 0011 0000
  → 1010 1110 0110 1000 0000 0000 0011 0000 = 0xAE680030
```

**Narration:**
> Store word uses exactly the same addressing mode, but the data flows the other
> way — from a register into memory.
> The notes' second example is: A of 12 equals h plus A of 8.
> We load A of 8, add h, and then store the result into A of 12. The offset for
> element 12 is 12 times 4, which is 48.
> With our values, the store's effective address is 1000 plus 48, which is 1048,
> and the value 57 is written there.
> For sw, the rt field names the register whose value is **stored** — so here rt
> is a source, not a destination.
> Exam point: the opcode for lw is 35 and for sw is 43, as given in the notes'
> instruction table.

**On-screen revision points:**
- sw: Memory[rs + offset] ← rt. lw: rt ← Memory[rs + offset].
- Opcodes: lw = 35, sw = 43, addi = 8, R-type = 0.

---

## Scene 1.10 — Mode 4: PC-Relative Addressing — Definition

**Visual directions:** Heading "4. PC-Relative Addressing". Animated program
listing with the PC arrow moving down instruction by instruction, then jumping.

**Diagram instructions:**
```
beq rs, rt, offset
| op=4 | rs | rt | 16-bit offset (in words) |

PC ──► [+4] ──► PC+4 ──┐
                       (+) ──► Branch target address
offset ─► sign-extend ─► shift left 2 ─┘
```

**Narration:**
> PC-relative addressing. **Definition from the notes:** the branch address is the
> sum of the PC and a constant in the instruction.
> This mode is used by conditional branches — beq, "branch if equal", and bne,
> "branch if not equal". They use the I-format.
> Why "relative"? Because the target is not given as a full address. It is given
> as a distance from where we are now. Most branches go to nearby instructions —
> in loops and if statements — so a 16-bit distance is enough.
> There are two details the notes emphasise, and both are exam favourites.
> Detail one: the base for the calculation is **the address of the instruction
> following the branch**, that is, **PC + 4**, not the PC of the branch itself.
> Detail two: the offset is a **word offset**. It is **shifted left by 2 bits**,
> which multiplies it by 4, turning a count of instructions into a count of bytes.
> This increases the range of the branch by a factor of 4.
> So the formula is:
> branch target address equals PC plus 4, plus the sign-extended offset shifted
> left by 2.

**On-screen revision points:**
- **Branch target = (PC + 4) + (sign-extend(offset) << 2)**
- Offset counts **instructions (words)**, not bytes.
- Branch taken → PC = target. Not taken → PC = PC + 4.

---

## Scene 1.11 — PC-Relative Addressing — Worked Examples

**Visual directions:** Program listing with addresses in hex on the left. Arrow
animation shows the branch jumping forward, then a second example jumping back.

**Worked example 1 — forward branch:**
```
Address       Instruction
0x00400010    beq $s3, $s4, Else       # offset field = 3
0x00400014    add $s0, $s1, $s2
0x00400018    j   Exit
0x0040001C    ...
0x00400020    Else: sub $s0, $s1, $s2

PC of beq          = 0x00400010
PC + 4             = 0x00400014
offset field       = 3  (0000 0000 0000 0011)
sign-extend        = 0x00000003
shift left 2       = 3 × 4 = 12 = 0x0000000C
Target             = 0x00400014 + 0x0000000C = 0x00400020  ✔ (Else)

If $s3 = $s4  → branch taken  → PC = 0x00400020
If $s3 ≠ $s4  → not taken     → PC = 0x00400014
```

**Worked example 2 — backward branch (a loop):**
```
offset field = −2 → 16 bits: 1111 1111 1111 1110 (0xFFFE)
sign-extend  → 0xFFFFFFFE  (= −2)
shift left 2 → −8
PC of branch = 0x00400010, PC + 4 = 0x00400014
Target = 0x00400014 − 8 = 0x0040000C
```

**Narration:**
> Example one. The beq is at address hex 0040 0010. PC plus 4 is 0040 0014.
> The offset field holds 3. Sign-extending keeps it as 3. Shifting left by 2
> multiplies by 4, giving 12, which is hex C.
> Hex 0040 0014 plus C is 0040 0020 — exactly the address of the label Else.
> Notice: counting from the instruction **after** the branch, Else is 3
> instructions away — 0014, 0018, 001C, then 0020. That is why the offset is 3.
> Example two, a backward branch, as in a loop. The offset is −2, stored in two's
> complement as hex FFFE. Sign extension copies the 1 sign bit into the upper 16
> bits, giving FFFF FFFE, which is still −2. Shift left 2 gives −8. 0040 0014 minus
> 8 is 0040 000C. Sign extension is what makes backward branches possible.
> One more note: the notes mention that in the real MIPS instruction set,
> **branches are delayed** — the instruction right after the branch is always
> executed. For simplicity, the notes and this video ignore delayed branches.

**On-screen revision points:**
- Offset = number of instructions from (PC + 4) to the target.
- Negative offset → backward branch (loops); sign extension is essential.
- Delayed branch: following instruction always executes (ignored in this design).

---

## Scene 1.12 — Mode 5: Pseudodirect Addressing — Definition

**Visual directions:** Heading "5. Pseudodirect Addressing". J-format bar. Then a
32-bit address bar assembled from three coloured pieces.

**Diagram instructions:**
```
j target
| op = 2 (6 bits) | target (26 bits) |

New PC (32 bits) = | PC[31:28] (4 bits) | target (26 bits) | 00 (2 bits) |
                         4      +      26      +      2       = 32
```
The ":" circle from the notes' diagram is labelled "concatenation (join side by
side) — NOT addition".

**Narration:**
> Pseudodirect addressing. **Definition from the notes:** the jump address is the
> 26 bits of the instruction concatenated with the upper bits of the PC.
> This mode is used by the jump instruction, j, and jump-and-link, jal. They use the
> **J-format**: a 6-bit opcode and a 26-bit target.
> The notes give the exact rule:
> PC gets PC bits 31 to 28, followed by IR bits 25 to 0, followed by 0 0.
> "IR" is the instruction register — the instruction being executed — so IR bits
> 25 to 0 are the 26-bit target field.
> Let us count the bits: 4 bits from the PC, plus 26 bits from the instruction,
> plus 2 zero bits — 32 bits, a complete address.
> Very important: this is **concatenation**, not addition. The pieces are placed
> side by side. That is why the notes' diagram shows a colon, not a plus sign.
> Why "pseudo" direct? A direct address would be a full 32-bit address in the
> instruction. We cannot fit 32 bits, because 6 bits are used by the opcode. So we
> get "almost" direct — 26 bits from the instruction and the rest borrowed from the PC.
> Why append two zeros? Because every instruction address is a multiple of 4, its
> lowest two bits are always 0 0. There is no need to store them. Appending 0 0 is
> the same as shifting left by 2.

**On-screen revision points:**
- **Jump address = PC[31:28] ‖ target[25:0] ‖ 00** (‖ = concatenation).
- 4 + 26 + 2 = 32 bits. Jump range: within the same 256 MB (2²⁸ bytes) region.
- *Clarification beyond the notes: the textbook strictly uses the upper 4 bits of
  PC + 4; the notes write PC[31:28]. The result differs only at a 256 MB boundary.*

---

## Scene 1.13 — Pseudodirect Addressing — Worked Example

**Visual directions:** Three-row binary assembly animation.

**Worked example:**
```
j instruction at PC = 0x00400018, target field = 0x0100008

target (26 bits)  = 00 0001 0000 0000 0000 0000 1000
shift left 2      = 0000 0100 0000 0000 0000 0010 0000  (28 bits) = 0x0400020
PC[31:28]         = 0000  (from 0x0...)
Concatenate       = 0000 | 0000 0100 0000 0000 0000 0010 0000
New PC            = 0x00400020
```

**Narration:**
> Suppose a jump at address hex 0040 0018 has the target field hex 010 0008.
> Write the 26 bits out. Shift left by 2 — that is, append two zeros — and we get
> the 28-bit value hex 040 0020.
> The upper 4 bits of the PC are 0 0 0 0.
> Placing them in front gives hex 0040 0020. The processor loads this into the PC
> and continues execution there.
> Quick check: hex 0040 0020 divided by 4 is hex 0010 0008 — exactly our target
> field. So the target field is simply the word address of the destination.

**On-screen revision points:**
- Target field = (destination address ÷ 4), lower 26 bits.
- `j` opcode = 2 (J-format).

---

## Scene 1.14 — Comparing the Five Addressing Modes

**Visual directions:** Full-screen comparison table builds row by row; then a
"How to identify the mode" decision flow chart.

**Diagram instructions:** Decision flowchart:
```
Is it a branch (beq/bne)?        → PC-relative
Is it a jump (j/jal)?            → Pseudodirect
Is there "number(register)"?     → Base/displacement
Is there a plain constant?       → Immediate (+ register for the other operand)
Only registers?                  → Register
```

**Narration:**
> Let us compare all five.
> Immediate and register addressing find **data** that is immediately available —
> inside the instruction, or in a register. No memory access is needed.
> Base addressing finds **data in memory** using register plus offset.
> PC-relative and pseudodirect find **instructions** — the next place to execute.
> PC-relative **adds** an offset to PC + 4. Pseudodirect **concatenates** bits.
> PC-relative uses a 16-bit offset; pseudodirect uses a 26-bit target, so jumps
> reach much further than branches.
> One more subtle point: a single instruction can use **more than one** mode.
> `addi $s3, $s3, 4` uses register addressing for $s3 and immediate addressing for
> 4. `beq $s1, $s2, L` uses register addressing to compare and PC-relative
> addressing for the target. And `lw` uses register addressing for the destination
> and base addressing for the memory operand.
> Here is a simple way to identify the mode: look at the instruction. Branch? PC-
> relative. Jump? Pseudodirect. A number followed by a register in brackets? Base.
> A plain constant? Immediate. Only registers? Register addressing.

**On-screen revision points:**
| Mode | Format | Address / operand calculation | Memory access? |
|---|---|---|---|
| Immediate | I | operand = sign-extend(imm16) | No |
| Register | R | operand = Reg[rs], Reg[rt] | No |
| Base | I | EA = Reg[rs] + sign-extend(offset16) | Yes (data) |
| PC-relative | I | target = PC + 4 + (sign-extend(offset16) << 2) | Fetches instruction |
| Pseudodirect | J | target = PC[31:28] ‖ addr26 ‖ 00 | Fetches instruction |

**Exam points for Topic 1:**
- List and define all 5 modes in the notes' words; draw the notes' 5-part diagram.
- PC-relative uses PC + 4 and a word offset (shift left 2).
- Pseudodirect = concatenation, not addition.
- lw/sw: rt is destination (lw) or source (sw).

---

*End of Part 1. Continue with Part 2 — A Basic MIPS Implementation.*
