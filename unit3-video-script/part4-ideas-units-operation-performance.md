# PART 4 — Topics 4 to 7: Eight Great Ideas, Functional Units, Basic Operational Concepts, CPU Performance

---

## Scene 4.0 — Computer Architecture: Subcategories, CISC and RISC

**Visual directions:** Heading "Before the Eight Great Ideas — from the opening of
the notes". Three boxes (ISA, Microarchitecture, Systems design), then a CISC vs RISC
two-column comparison.

**Narration:**
> The notes open Unit 3 by saying computer architecture has three main subcategories.
> **Instruction set architecture, or ISA**: the functions and capabilities of the
> central processing unit — the programming language it understands, its data formats
> and the instruction set. MIPS is an ISA.
> **Microarchitecture**, also known as computer organization: how a particular
> processor implements the ISA. The datapath we just built is a microarchitecture.
> **Systems design**: all the hardware components of a computer — data processors,
> multiprocessors, memory controllers and so on.
> The notes also describe two approaches to processor architecture.
> **CISC**, Complex Instruction Set Computer: a small register set and hundreds of
> different instructions, with a single instruction for a task. Fewer lines of code
> and less memory, but instructions can take longer.
> **RISC**, Reduced Instruction Set Computer: a smaller set of instructions with few
> addressing modes; instructions execute faster and take one clock cycle per
> instruction. MIPS is a RISC — which is why it has only five addressing modes and
> three formats.

**On-screen revision points:**
| CISC | RISC |
|---|---|
| Hundreds of instructions, small register set | Small instruction set, few addressing modes |
| Fewer lines of code, less memory | Faster execution, one clock cycle per instruction |

---

## Scene 4.1 — Topic 4: Eight Great Ideas in Computer Architecture (overview)

**Visual directions:** Heading "TOPIC 4 — EIGHT GREAT IDEAS". Eight icon tiles
appear in a 2×4 grid: rocket (Moore's Law), layered cake (Abstraction), sports car
(Common case fast), parallel arrows (Parallelism), pipeline (Pipelining), crystal ball
(Prediction), pyramid (Hierarchy), spare tyre (Redundancy).

**Narration:**
> The notes say these are eight great ideas that computer architects have invented in
> the last 60 years of computer design. Here they are:
> Design for Moore's Law. Use abstraction to simplify design. Make the common case
> fast. Performance via parallelism. Performance via pipelining. Performance via
> prediction. Hierarchy of memories. Dependability via redundancy.
> Let us take them one by one.

---

## Scene 4.2 — Idea 1: Design for Moore's Law

**Visual directions:** Graph of transistor count doubling every two years; a project
timeline bar labelled "design starts" and "design finishes" with an arrow pointing to
the future.

**Narration:**
> **Definition:** Moore's Law says the number of transistors in an integrated circuit
> doubles approximately every two years. It is named after Gordon Moore, one of the
> founders of Intel.
> **Significance:** computer designs can take years. During that time, the resources
> available per chip can easily double or quadruple between the start and the finish of
> the project.
> So, as the notes say, architects must anticipate where the technology will be **when
> the design finishes**, rather than design for where it starts.
> **Example:** a team starting a 4-year chip project designs for about four times
> today's transistor budget, because two doublings will happen before release.

---

## Scene 4.3 — Idea 2: Use Abstraction to Simplify Design

**Visual directions:** Stack of layers; each layer hides the one below.

**Narration:**
> **Definition:** an abstraction level is a generalization of a model or algorithm.
> Lower-level details are hidden to offer a simpler model at higher levels.
> The notes say a computer system is usually represented as five abstraction levels:
> hardware, firmware, assembler, operating system and processes.
> **Significance:** both architects and programmers needed techniques to be more
> productive; otherwise design time would lengthen dramatically as resources grew with
> Moore's Law. A good abstraction layer also allows easy reuse.
> **Example:** a C programmer writes `f = g + h` without thinking about registers; the
> compiler turns it into `add`; the hardware designer builds an ALU without knowing
> which program will run. We used abstraction in Topic 3 too — we drew the register
> file as one box, hiding thousands of gates.

---

## Scene 4.4 — Idea 3: Make the Common Case Fast

**Visual directions:** Pie chart: 90% "common operations", 10% "rare". A speed-up
arrow on the 90% slice.

**Narration:**
> **Definition:** making the common case fast tends to enhance performance better than
> optimizing the rare case.
> **Significance:** it implies you know what the common case is, which the notes say is
> only possible with careful experimentation and measurement.
> **Example:** in MIPS, most instructions use registers, so registers are made very
> fast and plentiful. Most constants are small, so a 16-bit immediate field is enough
> for the common case.

---

## Scene 4.5 — Idea 4: Performance via Parallelism

**Visual directions:** One large job split into four pieces processed by four
workers simultaneously.

**Narration:**
> **Definition:** computer architects offer designs that get more performance by
> performing operations in **parallel**.
> Parallel computing is a form of computation in which many calculations are carried
> out simultaneously, based on the principle that large problems can often be divided
> into smaller ones, which are then solved concurrently.
> **Significance:** the notes say parallelism has been used for many years, mainly in
> high-performance computing.
> **Example:** adding two arrays of a million numbers on four cores — each core adds a
> quarter, so ideally it finishes in a quarter of the time. Even in our datapath, the
> ALU comparison and the branch-target adder work in parallel during a beq.

---

## Scene 4.6 — Idea 5: Performance via Pipelining

**Visual directions:** Laundry analogy (wash, dry, fold) then an instruction pipeline
diagram: 5 instructions × 5 stages, staggered.

**Diagram instructions:**
```
Time →     1    2    3    4    5    6    7
Instr 1:  IF   ID   EX   MEM  WB
Instr 2:       IF   ID   EX   MEM  WB
Instr 3:            IF   ID   EX   MEM  WB
```

**Narration:**
> **Definition from the notes:** pipelining is a technique used to increase the
> instruction **throughput** — the number of instructions that can be executed in a
> unit of time.
> The basic instruction cycle is broken into a series of pipeline stages. Instead of
> finishing one instruction before starting the next, each instruction is split into
> steps, and different steps of different instructions run at the same time on
> different circuitry.
> **Key exam point:** pipelining increases throughput but does **not** reduce
> instruction **latency** — the time to complete a single instruction — because each
> instruction must still go through all the steps.
> **Analogy:** in a laundry, while load 1 is drying, load 2 is washing. Each load still
> takes the same time, but more loads finish per hour.

---

## Scene 4.7 — Idea 6: Performance via Prediction

**Visual directions:** A pipeline reaches a branch "fork in the road". A crystal ball
guesses "taken"; instructions are fetched along the guessed path.

**Narration:**
> **Definition:** to improve flow and throughput in an instruction pipeline, **branch
> predictors** guess the outcome of a branch.
> **Significance:** without branch prediction, the processor would have to wait until
> the conditional jump has passed the execute stage before the next instruction could
> enter the fetch stage. The predictor avoids this waste of time by guessing whether
> the branch is most likely to be taken or not taken.
> **Example:** in a loop that runs 100 times, the branch back to the top is taken 99
> times. Predicting "taken" is right 99% of the time.

---

## Scene 4.8 — Idea 7: Hierarchy of Memories

**Visual directions:** Reproduce the notes' memory pyramid: CPU Register at the top;
Cache (Level 1, Level 2); RAM (Physical RAM, Virtual Memory) — bracket "Temporary
Storage Areas"; Storage Device Types (ROM/BIOS, Removable drives,
Network/Internet storage, Hard drive) — bracket "Permanent Storage Areas"; Input
Sources (Keyboard, Mouse, Removable media, Scanner/Camera/Mic/Video, Remote source,
Other sources) at the base. Side arrows: "faster, smaller, costlier per bit ↑" and
"slower, larger, cheaper per bit ↓".

**Narration:**
> **Definition:** programmers want memory to be fast, large and cheap. Speed shapes
> performance, capacity limits the problem size, and memory cost is often the majority
> of computer cost. These demands conflict.
> Architects solve this with a **hierarchy of memories**: the fastest, smallest and most
> expensive memory per bit at the top, and the slowest, largest and cheapest per bit at
> the bottom.
> **Significance:** caches give the programmer the illusion that main memory is nearly
> as fast as the top of the hierarchy, and nearly as big and cheap as the bottom.
> **Example:** registers → cache → RAM → hard disk.

---

## Scene 4.9 — Idea 8: Dependability via Redundancy

**Visual directions:** Two servers, one fails (red X), the other takes over (green
check). Label "failover / high availability".

**Narration:**
> **Definition:** computers need to be not only fast but **dependable**. Since any
> physical device can fail, we include **redundant** components that can take over when
> a failure occurs and help detect failures.
> **Example from the notes:** system designers provide **failover** capability in
> servers, systems or networks requiring continuous availability. This is called **high
> availability** — a high degree of reliability. Another everyday example: RAID disk
> arrays keep duplicate copies of data.

**On-screen revision points (Topic 4):**
| # | Idea | One-line meaning |
|---|---|---|
| 1 | Design for Moore's Law | Transistors double ~2 years; design for the finish date |
| 2 | Abstraction | Hide lower-level detail; 5 levels |
| 3 | Common case fast | Optimize the frequent case (measure it) |
| 4 | Parallelism | Many operations at the same time |
| 5 | Pipelining | Overlap stages; ↑ throughput, not ↓ latency |
| 6 | Prediction | Guess branch outcome instead of waiting |
| 7 | Hierarchy of memories | Fast/small/costly on top, slow/large/cheap below |
| 8 | Redundancy | Spare components → failover, high availability |

---

## Scene 5.1 — Topic 5: Functional Units of a Computer System

**Visual directions:** Heading "TOPIC 5 — FUNCTIONAL UNITS". Reproduce the notes'
block diagram: left box "I/O" containing "Input" and "Output"; centre box "Memory";
right box "Processor" containing "ALU" and "Control Unit". Then animated arrows show
information flow.

**Diagram instructions:**
```
 [Input] ──► [Memory] ◄──► [ALU]
                │  ▲          ▲
                ▼  │          │
 [Output] ◄─────┘  └── [Control Unit] (dashed control lines to all units)
```

**Narration:**
> The notes say a computer consists of five functionally independent main parts:
> **Input**, **Memory**, **Arithmetic and Logic Unit**, **Output** and **Control unit**.
> Here is how information flows. The input device accepts coded information — a source
> program in a high-level language, or data. This is either stored in memory or used
> immediately by the processor. The program stored in memory determines the processing
> steps. Basically, the computer converts a source program into an object program — that
> is, machine language. Finally, the results go to the outside world through an output
> device. All of these actions are coordinated by the control unit.

---

## Scene 5.2 — Input Unit and Output Unit

**Visual directions:** Keyboard key pressed → binary code travels along a cable →
memory/processor. Then printer, speaker and monitor icons for output.

**Narration:**
> **Input unit:** the program or data is fed into the computer through input devices.
> The keyboard is the most common. Whenever a key is pressed, the corresponding word or
> number is translated into its equivalent binary code over a cable and fed either to
> memory or to the processor. Other input devices: joysticks, trackballs, mouse,
> scanners.
> **Output unit:** the counterpart of the input unit. Its basic function is to send the
> processed results to the outside world. Examples: printer, speakers, monitor.

---

## Scene 5.3 — Memory Unit: Primary Memory

**Visual directions:** A grid of memory cells grouped into words, each word with an
address on the left (0, 1, 2 …). Labels for "word length", "address", "RAM", "ROM",
"Cache".

**Narration:**
> **Memory unit:** its function is to store programs and data. There are two types:
> primary memory and secondary memory.
> **Primary memory** is the one exclusively associated with the processor and operates
> at electronic speeds. Programs must be stored in this memory while they are being
> executed.
> It contains a large number of semiconductor storage cells, each capable of storing
> one bit. These are processed in groups of fixed size called **words**.
> To provide easy access to a word, a distinct **address** is associated with each word
> location. Addresses are numbers that identify memory locations.
> The number of bits in each word is called the **word length** of the computer.
> Memory in which any location can be reached in a short and fixed amount of time after
> specifying its address is called **random-access memory, RAM**.
> The time required to access one word is called the **memory access time**.
> Memory that is only readable by the user, whose contents cannot be altered, is called
> **read-only memory, ROM**. The notes say it contains the operating system.
> **Caches** are small, fast RAM units coupled with the processor, often on the same IC
> chip, to achieve high performance.
> Primary storage is essential, but it tends to be expensive.

**On-screen revision points:**
- Word: fixed-size group of bits. Word length: bits per word.
- Address: number identifying a memory location.
- RAM: any location reachable in short, fixed time. Access time: time to access one word.
- ROM: read-only. Cache: small fast RAM near/on the processor.

---

## Scene 5.4 — Memory Unit: Secondary Memory

**Visual directions:** Icons: magnetic disk, tape, CD-ROM, floppy.

**Narration:**
> **Secondary memory** is used where large amounts of data and programs must be stored,
> particularly information that is accessed infrequently.
> Examples: magnetic disks and tapes, optical disks such as CD-ROMs, and floppies.
> It is cheaper and larger than primary memory, but slower.

**On-screen revision points:**
| Primary | Secondary |
|---|---|
| Directly used by processor, electronic speed | Large, infrequently accessed data |
| RAM, ROM, cache | Magnetic disks/tapes, CD-ROM, floppy |
| Expensive per bit | Cheap per bit |

---

## Scene 5.5 — ALU and Control Unit

**Visual directions:** Operands travel memory → registers → ALU → result. Then the
control unit drawn as a "nerve centre" with timing pulses going to each unit.

**Narration:**
> **Arithmetic and logic unit:** most computer operations — addition, subtraction,
> multiplication, division and so on — are executed in the ALU. Operands are brought
> into the ALU from memory and stored in high-speed storage elements called
> **registers**. Then the operation is performed according to the instructions.
> The control unit and the ALU are many times faster than other devices connected to
> the computer. This lets a single processor control many external devices — keyboards,
> displays, magnetic and optical disks, sensors and mechanical controllers.
> **Control unit:** it is effectively the **nerve centre** that sends signals to other
> units and senses their states. The actual **timing signals** that govern the transfer
> of data between the input unit, processor, memory and output unit are generated by the
> control unit.

**On-screen revision points:**
- 5 units: Input, Memory, ALU, Output, Control. ALU + Control = Processor.
- Control unit = nerve centre; generates timing signals.

---

## Scene 6.1 — Topic 6: Basic Operational Concepts — Stored Program

**Visual directions:** Heading "TOPIC 6 — BASIC OPERATIONAL CONCEPTS". Memory shows a
list of instructions and some data words.

**Narration:**
> To perform a task, an appropriate program — a list of instructions — is stored in
> memory. Individual instructions are brought from memory into the processor, which
> executes them. Data are also stored in memory.
> The notes' example is `Add LOCA, R0`.
> This instruction adds the operand at memory location LOCA to the operand in register
> R0 and places the sum into register R0.
> It needs several steps:
> One — the instruction is fetched from memory into the processor.
> Two — the operand at LOCA is fetched and added to the contents of R0.
> Three — the resulting sum is stored in register R0.
> This instruction combines a memory access with an ALU operation. In some other
> computers — like MIPS, which is a load-store machine — these are done by separate
> instructions for performance reasons:
> `Load LOCA, R1` then `Add R1, R0`.
> Note: this example uses a generic textbook notation, not MIPS syntax. Here, the
> destination is written last.

---

## Scene 6.2 — Processor Registers: PC, IR, MAR, MDR

**Visual directions:** Processor block diagram: Memory on the left connected via two
lines to MAR and MDR inside the processor; inside also PC, IR, Control, ALU, and
general-purpose registers R0 … Rn−1.

**Diagram instructions:**
```
          ┌──────────────── Processor ────────────────┐
Memory ◄──┤ MAR                 PC                    │
Memory ◄─►┤ MDR                 IR ──► Control        │
          │ R0, R1, … Rn−1  ──► ALU                   │
          └───────────────────────────────────────────┘
```

**Narration:**
> Transfers between memory and the processor start by sending the address of the
> location to the memory unit and issuing the appropriate control signals. Then the
> data are transferred to or from memory.
> Four special registers are involved:
> **PC — Program Counter**: holds the address of the next instruction to be fetched.
> **IR — Instruction Register**: holds the instruction currently being executed.
> **MAR — Memory Address Register**: holds the address of the location to be accessed.
> **MDR — Memory Data Register**: contains the data to be written into, or read out of,
> the addressed location.

**On-screen revision points:**
- MAR: address of location to access. MDR: data read from / written to memory.
- PC: address of next instruction. IR: current instruction.

---

## Scene 6.3 — The 12 Operating Steps, Animated with ADD LOCA, R0

**Visual directions:** The block diagram from 6.2 with values flowing. Each numbered
step appears on the right as it happens.

**Worked example (values added for illustration):**
```
Memory: address 100: "Add LOCA, R0"   LOCA = 500, Memory[500] = 25
R0 = 10 before execution
```

**Narration (the notes' operating steps, with the example):**
> 1. Programs reside in memory, usually arriving through the input unit.
> 2. Execution starts when the PC is set to point at the first instruction. PC = 100.
> 3. The contents of the PC are transferred to the MAR, and a **Read** control signal
>    is sent to memory. MAR = 100.
> 4. After the memory access time elapses, the addressed word is read out of memory
>    and loaded into the MDR. MDR = "Add LOCA, R0".
> 5. The contents of MDR are transferred to the IR. Now the instruction is ready to be
>    decoded and executed.
> 6. The instruction involves an ALU operation, so the required operands must be
>    obtained. R0 is already in the processor: 10.
> 7. The operand in memory is fetched by sending its address to MAR and initiating a
>    read cycle. MAR = 500.
> 8. When the operand has been read into the MDR, it is transferred from MDR to the
>    ALU. MDR = 25.
> 9. After one or two such cycles, the ALU performs the operation: 25 + 10 = 35.
> 10. If the result were to be stored in memory, it would be sent to the MDR.
> 11. And the address of that location would be sent to MAR and a write cycle started.
>     In our example, the result goes into R0 instead, so R0 = 35.
> 12. The contents of the PC are incremented to point to the next instruction.
>     PC = 104 for a 4-byte instruction.

**On-screen revision points:**
- Fetch: PC → MAR → Read → MDR → IR.
- Operand fetch: address → MAR → Read → MDR → ALU.
- Store: result → MDR, address → MAR → Write.
- PC incremented to next instruction.

---

## Scene 6.4 — Interrupts and Interrupt Service Routines

**Visual directions:** A program running; a printer icon raises a red "INT" flag;
the processor saves its state into memory, jumps to an ISR, returns, restores state.

**Narration:**
> Normal execution of a program may be **preempted** — temporarily interrupted — if
> some device needs urgent servicing. To do this, the device raises an **interrupt**
> signal.
> An **interrupt** is a request signal from an I/O device for service by the processor.
> The processor provides the service by executing an appropriate **interrupt service
> routine**, ISR.
> Because this diversion may change the internal state of the processor, its state must
> be saved in memory before servicing the interrupt. When the ISR is completed, the
> state is restored so the interrupted program can continue.

**On-screen revision points:**
- Interrupt: request from an I/O device for service.
- ISR: routine that services it. Save state → run ISR → restore state → resume.

---

## Scene 7.1 — Topic 7: Performance — Response Time and Throughput

**Visual directions:** Heading "TOPIC 7 — CPU PERFORMANCE". Split screen: one user at
a desktop with a stopwatch ("response time"); a datacenter with a counter of jobs per
day ("throughput").

**Narration:**
> What does "faster" mean? The notes give two views.
> If you run a program on two desktop computers, the faster one gets the job done
> first. As an individual user, you care about **response time** — the time between the
> start and completion of a task, also called **execution time**.
> A datacenter manager running many users' jobs calls the faster computer the one that
> completes the most jobs in a day. They care about **throughput**, or **bandwidth** —
> the total amount of work done in a given time.

---

## Scene 7.2 — Performance = 1 / Execution Time

**Visual directions:** Formula builds step by step.

**On-screen formulas:**
```
Performance_X = 1 / Execution time_X

Performance_X > Performance_Y
⇔ 1/Execution time_X > 1/Execution time_Y
⇔ Execution time_Y > Execution time_X

"X is n times as fast as Y":
Performance_X / Performance_Y = Execution time_Y / Execution time_X = n
```

**Narration:**
> To maximize performance, we minimize execution time. So performance is the
> reciprocal of execution time.
> If X performs better than Y, then 1 over X's time is larger than 1 over Y's time, so
> Y's execution time is longer.
> "X is n times as fast as Y" means performance of X divided by performance of Y equals
> n — which equals execution time of **Y** divided by execution time of **X**. Notice
> the swap: the slower machine's time goes on top.

---

## Scene 7.3 — Measuring Performance: CPU Time, User and System Time

**Visual directions:** A timeline bar for one program: segments "user CPU", "system
CPU", "waiting for I/O", "other programs". Brackets show which count as CPU time.

**Narration:**
> **CPU execution time**, or **CPU time**: the actual time the CPU spends computing for
> a specific task. It does not count I/O waiting or time spent running other programs.
> It splits into:
> **User CPU time** — CPU time spent in the program itself.
> **System CPU time** — CPU time spent in the operating system performing tasks on behalf
> of the program.

**Worked example (beyond the notes, for practice):**
```
User CPU time = 90 s, System CPU time = 12 s, elapsed (wall-clock) time = 159 s
CPU time = 90 + 12 = 102 s
Fraction of elapsed time on CPU = 102 / 159 = 0.6415 ≈ 64%
The remaining 57 s (36%) was I/O or other programs.
```

---

## Scene 7.4 — The CPU Performance Equations

**Visual directions:** Each formula appears; every variable is underlined and labelled.

**On-screen formulas:**
```
(1) CPU time = CPU clock cycles × Clock cycle time
(2) CPU time = CPU clock cycles / Clock rate          (Clock rate = 1 / Clock cycle time)
(3) CPU clock cycles = Instruction count × CPI
(4) CPU time = Instruction count × CPI × Clock cycle time
(5) CPU time = (Instruction count × CPI) / Clock rate

seconds/program = instructions/program × cycles/instruction × seconds/cycle
```

**Narration:**
> The bottom-line measure is CPU execution time.
> The processor runs on a clock. One **clock cycle** is one tick; **clock cycle time**
> is its duration, in seconds — for example 250 picoseconds. **Clock rate** is ticks per
> second, in hertz — for example 4 gigahertz. They are inverses: 1 over 250 picoseconds
> is 4 gigahertz.
> So CPU time equals the number of clock cycles times the clock cycle time — or the
> number of clock cycles divided by the clock rate.
> How many clock cycles? The program executes a number of instructions — the
> **instruction count**, IC. Each takes some clock cycles; the average is **CPI**,
> **clock cycles per instruction**. So CPU clock cycles equal IC times CPI.
> Putting it together — the classic performance equation:
> **CPU time = Instruction count × CPI × Clock cycle time.**
> Check the units: instructions per program, times cycles per instruction, times seconds
> per cycle — instructions and cycles cancel, giving seconds per program.
> The notes say CPI is an average over all instructions executed, because different
> instructions take different times. And CPI is a good way to compare two
> implementations of the same ISA, because their instruction counts are the same.

**On-screen revision points — what affects each factor (notes' table):**
| Component | Affects |
|---|---|
| Algorithm | Instruction count, possibly CPI |
| Programming language | Instruction count, CPI |
| Compiler | Instruction count, CPI |
| Instruction set architecture | Instruction count, clock rate, CPI |

Unit reminders: 1 GHz = 10⁹ Hz; 1 ns = 10⁻⁹ s; 1 ps = 10⁻¹² s.

---

## Scene 7.5 — Problem 1 (from the notes): How Much Faster?

**Visual directions:** Problem text, then calculation lines appear one at a time.

**Worked example:**
```
Computer A runs a program in 10 s; computer B runs it in 15 s. How much faster is A?

Performance_A / Performance_B = Execution time_B / Execution time_A = n
n = 15 s / 10 s = 1.5          (seconds cancel → n has no unit)
Answer: A is 1.5 times as fast as B.
```

**Narration:**
> Performance A over performance B equals time B over time A. 15 seconds over 10
> seconds is 1.5. The seconds cancel, so the answer is a pure ratio. A is 1.5 times as
> fast as B.

---

## Scene 7.6 — Simple Practice: Using CPU Time = IC × CPI × Cycle Time

**Worked example (beyond the notes):**
```
A program executes 2 × 10⁶ instructions, average CPI = 2, clock rate = 1 GHz.

Step 1: Clock cycle time = 1 / clock rate = 1 / (1 × 10⁹ Hz) = 1 × 10⁻⁹ s = 1 ns
Step 2: CPU clock cycles = IC × CPI = 2 × 10⁶ × 2 = 4 × 10⁶ cycles
Step 3: CPU time = cycles × cycle time = 4 × 10⁶ × 1 × 10⁻⁹ s = 4 × 10⁻³ s = 4 ms
Check:  CPU time = cycles / clock rate = 4 × 10⁶ / 10⁹ = 0.004 s ✔
```

**Narration:**
> First the cycle time: one over one gigahertz is one nanosecond. Then cycles: two
> million instructions times two cycles each is four million cycles. Then time: four
> million times one nanosecond is four milliseconds. We check with the clock-rate form
> and get 0.004 seconds — the same answer.

---

## Scene 7.7 — Problem 2 (from the notes): Target Clock Rate

**Worked example:**
```
Program runs 10 s on computer A with a 2 GHz clock. Designer wants computer B to run
it in 6 s, but B will need 1.2 × as many clock cycles as A. What clock rate for B?

Given: Clock rate_A = 2 GHz = 2 × 10⁹ cycles/s; CPU time_A = 10 s;
       CPU time_B = 6 s; CPU clock cycles_B = 1.2 × CPU clock cycles_A

Step 1: CPU time_A = CPU clock cycles_A / Clock rate_A
        10 s = CPU clock cycles_A / (2 × 10⁹ cycles/s)
        CPU clock cycles_A = 10 s × 2 × 10⁹ cycles/s = 20 × 10⁹ cycles

Step 2: CPU time_B = 1.2 × CPU clock cycles_A / Clock rate_B
        6 s = 1.2 × 20 × 10⁹ cycles / Clock rate_B

Step 3: Clock rate_B = (1.2 × 20 × 10⁹ cycles) / 6 s
                     = 24 × 10⁹ / 6 = 4 × 10⁹ cycles/s = 4 GHz

Answer: B needs 4 GHz — twice the clock rate of A.
```

**Narration:**
> First find A's cycles: time times rate, 10 seconds times 2 times 10 to the 9 cycles
> per second gives 20 times 10 to the 9 cycles. B needs 1.2 times that: 24 times 10 to
> the 9 cycles. To do it in 6 seconds, B's rate is 24 times 10 to the 9 divided by 6,
> which is 4 times 10 to the 9 cycles per second — 4 gigahertz. Twice A's clock rate.

---

## Scene 7.8 — Problem 3 (from the notes): Same ISA, Different CPI and Cycle Time

**Worked example:**
```
A: cycle time 250 ps, CPI 2.0.  B: cycle time 500 ps, CPI 1.2. Same ISA → same IC = I.

Step 1: CPU clock cycles_A = I × 2.0 ; CPU clock cycles_B = I × 1.2
Step 2: CPU time_A = I × 2.0 × 250 ps = 500 × I ps
        CPU time_B = I × 1.2 × 500 ps = 600 × I ps
Step 3: A is faster (smaller time).
        Performance_A / Performance_B = 600 I ps / 500 I ps = 1.2
Answer: A is 1.2 times as fast as B for this program.
```

**Narration:**
> We do not know the instruction count, but it is the same, so we call it I and it
> cancels at the end. A: I times 2 times 250 picoseconds is 500 I picoseconds. B: I
> times 1.2 times 500 is 600 I picoseconds. Ratio: 600 over 500 is 1.2. A has the worse
> CPI but the much faster clock, and wins by a factor of 1.2.

---

## Scene 7.9 — Problem 4 (from the notes): Comparing Code Sequences — fully solved

**Visual directions:** Tag "Notes solve only part (i); parts (ii) and (iii) completed
here. Notes print 'Code sequence 1' twice — the second line refers to sequence 2."

**Worked example:**
```
CPI per class:        A = 1, B = 2, C = 3
Instruction counts:   Seq 1: A=2, B=1, C=2      Seq 2: A=4, B=1, C=1

(i) Instruction count
    Seq 1 = 2 + 1 + 2 = 5 instructions
    Seq 2 = 4 + 1 + 1 = 6 instructions
    → Sequence 2 executes more instructions.

(ii) CPU clock cycles = Σ (CPI_i × C_i)
    Seq 1 = (2×1) + (1×2) + (2×3) = 2 + 2 + 6 = 10 cycles
    Seq 2 = (4×1) + (1×2) + (1×3) = 4 + 2 + 3 = 9 cycles
    → Sequence 2 is faster (9 < 10), even though it executes more instructions.

(iii) CPI = CPU clock cycles / Instruction count
    CPI_1 = 10 / 5 = 2.0
    CPI_2 = 9 / 6  = 1.5
```

**Narration:**
> Part one: sequence 1 has 5 instructions and sequence 2 has 6. So sequence 2 executes
> more instructions.
> Part two: count cycles by multiplying each class's count by its CPI and adding.
> Sequence 1: 2 times 1, plus 1 times 2, plus 2 times 3, is 10 cycles. Sequence 2: 4
> plus 2 plus 3 is 9 cycles. Sequence 2 is faster.
> Part three: CPI is cycles divided by instructions. 10 over 5 is 2.0; 9 over 6 is 1.5.
> The lesson: **instruction count alone does not decide performance** — you must use all
> three factors.

---

## Scene 7.10 — Exam-Level Problem: Two Compilers

**Worked example (beyond the notes):**
```
A 2 GHz machine. CPI: class A = 1, B = 2, C = 3.
Compiler 1: A = 5 × 10⁹, B = 1 × 10⁹, C = 1 × 10⁹ instructions
Compiler 2: A = 10 × 10⁹, B = 1 × 10⁹, C = 1 × 10⁹ instructions

IC_1 = 7 × 10⁹ ; IC_2 = 12 × 10⁹
Cycles_1 = 5×1 + 1×2 + 1×3 = 10 × 10⁹ cycles
Cycles_2 = 10×1 + 1×2 + 1×3 = 15 × 10⁹ cycles
CPU time_1 = 10 × 10⁹ / 2 × 10⁹ Hz = 5 s
CPU time_2 = 15 × 10⁹ / 2 × 10⁹ Hz = 7.5 s
CPI_1 = 10/7 = 1.43 ; CPI_2 = 15/12 = 1.25
Compiler 1 is faster by 7.5 / 5 = 1.5 times — even though compiler 2 has the lower CPI.
```

**Narration:**
> This is the trap examiners like: compiler 2 has a better CPI, 1.25 against 1.43, but
> it produces many more instructions. Total time is what matters — compiler 1 takes 5
> seconds, compiler 2 takes 7.5 seconds. Compiler 1 is 1.5 times as fast. Never judge
> performance by CPI alone or by clock rate alone.

**On-screen revision points (Topic 7):**
- Performance = 1 / Execution time; n = Time_slow / Time_fast.
- CPU time = IC × CPI × Clock cycle time = IC × CPI / Clock rate.
- CPU clock cycles = IC × CPI = Σ CPIᵢ × Cᵢ.
- CPU time = user CPU time + system CPU time (excludes I/O and other programs).

---

*End of Part 4. Continue with Part 5.*
