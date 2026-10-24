from pathlib import Path
root = Path(__file__).resolve().parents[1]
source = (root / "src/main.c").read_text(encoding="utf-8")
makefile = (root / "Makefile").read_text(encoding="utf-8")
ring = (root / "src/core/ring_buffer.c").read_text(encoding="utf-8")
assert "int main(void)" in source and "return 0;" in source
assert "xenon-elf:" in makefile and "host-check:" in makefile
assert "default.xex" not in source.lower()
assert "buffer->capacity - buffer->size" in ring
print("PASS: source scaffold and build targets passed static assertions")
