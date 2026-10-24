from pathlib import Path
root = Path(__file__).resolve().parents[1]
source = (root / "src/main.c").read_text(encoding="utf-8")
makefile = (root / "Makefile").read_text(encoding="utf-8")
ring = (root / "src/core/ring_buffer.c").read_text(encoding="utf-8")
checker = (root / "tools/check_xenon_toolchain.py").read_text(encoding="utf-8")
inspector = (root / "tools/inspect_elf.py").read_text(encoding="utf-8")
probe = (root / "tools/check_xenon_source.c").read_text(encoding="utf-8")
assert "int main(void)" in source and "return 0;" in source
assert "xenon-elf:" in makefile and "host-check:" in makefile
assert "toolchain-check:" in makefile and "inspector-tests:" in makefile
assert "default.xex" not in source.lower()
assert "buffer->capacity - buffer->size" in ring
assert "xenon-gcc" in checker and "elf2xex" in checker
assert "ELF32" in inspector and "PowerPC" in inspector
assert "sizeof_pointer" in probe and "endianness" in probe
print("PASS: source scaffold, build targets, toolchain checker and ELF probe passed static assertions")
