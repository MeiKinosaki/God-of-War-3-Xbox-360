from pathlib import Path

root = Path(__file__).resolve().parents[1]
source = (root / "src/main.c").read_text(encoding="utf-8")
makefile = (root / "Makefile").read_text(encoding="utf-8")

assert "int main(void)" in source
assert "return 0;" in source
assert "xenon-elf:" in makefile
assert "host-check:" in makefile
assert "default.xex" not in source.lower()
print("PASS: bootstrap source and build targets are present (static checks only)")
