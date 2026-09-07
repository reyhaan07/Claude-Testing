#!/usr/bin/env python3
"""Render the built PDF to PNGs for visual inspection.
Usage: python3 preview.py [page ...]   (no args = all pages)
Outputs to ./_preview (gitignored)."""
import sys, pathlib, pypdfium2 as pdfium
ROOT = pathlib.Path(__file__).resolve().parent
PDF = ROOT / "OperatingSystemsMastery.pdf"
OUT = ROOT / "_preview"
OUT.mkdir(exist_ok=True)
pdf = pdfium.PdfDocument(str(PDF))
n = len(pdf)
pages = [int(x) for x in sys.argv[1:]] or list(range(1, n + 1))
for p in pages:
    if 1 <= p <= n:
        pdf[p-1].render(scale=1.4).to_pil().save(OUT / f"pg{p:03d}.png")
print(f"PDF has {n} pages; rendered {len(pages)} to {OUT}")
