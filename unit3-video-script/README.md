# Unit 3 — Processor and Control Unit: Teaching Video Script

Complete, line-by-line narration script for a teaching video on Unit 3 of
*Digital Principles and Computer Architecture*, built from the St. Joseph's
College of Engineering Unit 3 notes (CS8491, 23 pages).

## Teaching order

| Part | File | Topics |
|---|---|---|
| 1 | [part1-addressing-modes.md](part1-addressing-modes.md) | Intro + **Topic 1: MIPS Addressing Modes** (priority) |
| 2 | [part2-mips-implementation.md](part2-mips-implementation.md) | **Topic 2: A Basic MIPS Implementation** (priority) |
| 3 | [part3-hardware-structure.md](part3-hardware-structure.md) | **Topic 3: Hardware Structure** (priority) |
| 4 | [part4-ideas-units-operation-performance.md](part4-ideas-units-operation-performance.md) | Topics 4–7: Eight Great Ideas, Functional Units, Basic Operational Concepts, CPU Performance |
| 5 | [part5-instructions-formats-datapath-revision.md](part5-instructions-formats-datapath-revision.md) | Topics 8–10: Operations & Operands, Instruction Representation, Building a Datapath + **Final Revision** |

## Scene format

Every scene has: **Scene title**, **Visual directions**, **Diagram
instructions**, **Narration** (exact spoken words), **Worked example** (where
relevant) and **On-screen revision points**.

## Source-accuracy notes (read before recording)

The notes are the primary source. Where the script goes beyond them, it says so
on screen with a **"Clarification — beyond the notes"** tag. Specifically:

1. **Control-signal truth table** (RegDst, ALUSrc, MemtoReg, RegWrite, MemRead,
   MemWrite, Branch, ALUOp) and the 4-bit ALU control codes are *not* tabulated
   in the notes. The notes name the signals in Figures 1.2 and 4.11 only. The
   values used here are the standard ones from Patterson & Hennessy, the
   textbook the notes are drawn from.
2. **RegDst multiplexer**: the notes' Figure 4.11 has no multiplexer choosing
   between `rt` and `rd` for the write register. It is needed for R-format vs.
   LW and is added as a clarification.
3. **Jump datapath**: the notes say "support for jumps will be added later" and
   only give the rule `PC ← PC[31:28] ‖ IR[25:0] ‖ 00`. No jump hardware diagram
   is given; the script adds one as a clarification.
4. **Typos in the notes, corrected on screen**: "−215 to +215 − 1" means
   −2¹⁵ to +2¹⁵ − 1; "sll by i bits multiplies by 2i" means 2ⁱ; Problem 4
   says "Code sequence 1" twice where the second is code sequence 2; Problem 4
   parts (ii) and (iii) are left unsolved in the notes and are solved here;
   the notes list "j L1" under the line "Unconditional jump … Set result to 1"
   — two separate ideas that are separated here.
5. **Pseudodirect addressing**: the notes use the upper 4 bits of the PC. The
   textbook strictly uses the upper 4 bits of PC + 4. These are the same except
   at a 256 MB boundary; the script uses the notes' wording and mentions this.
6. **Not covered in the notes**: pipelining hazards, exceptions, multicycle
   implementation, and the full ALU-control design. The notes mention
   pipelining only as a "great idea" and as future work; the script does not
   pretend these are part of Unit 3.
