# Operating Systems Mastery — Handbook

A complete, self-contained **Operating Systems** learning handbook that takes a reader from
"I know almost nothing about OS" to confident mastery for university, software-engineering
interviews, system design, and practical Linux/C systems programming.

**Deliverable:** [`OperatingSystemsMastery.pdf`](OperatingSystemsMastery.pdf) — a professional,
textbook-style PDF (title page, table of contents with page numbers, 23 parts, diagrams, code,
solved numericals, comparison tables, 100+ interview questions, projects, and mastery checkpoints).

## How it is built

The book is authored as modular HTML fragments styled with one CSS design system and rendered to
PDF with [WeasyPrint](https://weasyprint.org/).

```
os-mastery-handbook/
├── styles.css          # the whole design system (typography, boxes, tables, diagrams, @page)
├── build.py            # assembles content/*.html + styles.css → handbook.html → PDF
├── preview.py          # renders the PDF to PNGs for visual QA (dev helper)
├── content/            # one or two HTML fragments per part, sorted by filename = book order
│   ├── 00-cover.html
│   ├── 01-about.html
│   ├── 02-toc.html
│   ├── p01-a-divider.html
│   ├── p01-b-content.html
│   └── ...
└── OperatingSystemsMastery.pdf   # the rendered book
```

## Build it yourself

```bash
pip install weasyprint            # one-time
python3 build.py                  # -> OperatingSystemsMastery.pdf
python3 build.py --html           # assemble HTML only (skip PDF render)
python3 preview.py 1 5 18         # render specific pages to ./_preview for inspection
```

Content order is purely the lexical sort of the filenames in `content/`, so parts can be edited
independently and reassembled.

## What's inside the book

Foundations (OS architecture, processes, threads, CPU scheduling) → coordination & memory
(synchronization, deadlocks, memory management, virtual memory) → systems & devices (file systems,
I/O, IPC, storage, networking) → practical & advanced (Linux internals, virtualization/containers,
"what happens when…" execution flows, hands-on projects) → mastery & revision (interview question
bank, solved numericals, comparison tables, checkpoints, and a final mastery test).
