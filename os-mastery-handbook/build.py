#!/usr/bin/env python3
"""
Build the OPERATING SYSTEMS MASTERY handbook PDF.

Assembles every HTML fragment in ./content (sorted by filename) into a single
HTML document, inlines styles.css, and renders to PDF with WeasyPrint.

Usage:
    python3 build.py            # build handbook.html + OperatingSystemsMastery.pdf
    python3 build.py --html     # only assemble the HTML (fast; skips PDF render)
"""
import sys, pathlib, datetime

ROOT = pathlib.Path(__file__).resolve().parent
CONTENT = ROOT / "content"
CSS = ROOT / "styles.css"
HTML_OUT = ROOT / "handbook.html"
PDF_OUT = ROOT / "OperatingSystemsMastery.pdf"

def assemble() -> str:
    css = CSS.read_text(encoding="utf-8")
    frags = sorted(CONTENT.glob("*.html"))
    if not frags:
        sys.exit("No content fragments found in ./content")
    body_parts = []
    for f in frags:
        body_parts.append(f"<!-- ===== {f.name} ===== -->")
        body_parts.append(f.read_text(encoding="utf-8"))
    body = "\n".join(body_parts)
    doc = f"""<!DOCTYPE html>
<html lang="en">
<head>
<meta charset="utf-8">
<title>Operating Systems Mastery</title>
<style>
{css}
</style>
</head>
<body>
{body}
</body>
</html>"""
    HTML_OUT.write_text(doc, encoding="utf-8")
    print(f"[assemble] {len(frags)} fragments -> {HTML_OUT.name} ({len(doc):,} bytes)")
    for f in frags:
        print(f"           - {f.name}")
    return doc

def render(doc: str):
    from weasyprint import HTML
    t0 = datetime.datetime.now()
    HTML(string=doc, base_url=str(ROOT)).write_pdf(str(PDF_OUT))
    dt = (datetime.datetime.now() - t0).total_seconds()
    size = PDF_OUT.stat().st_size
    print(f"[render] {PDF_OUT.name}  ({size:,} bytes)  in {dt:.1f}s")

if __name__ == "__main__":
    doc = assemble()
    if "--html" not in sys.argv:
        render(doc)
    else:
        print("[skip] PDF render (--html)")
