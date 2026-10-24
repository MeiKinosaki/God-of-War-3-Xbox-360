#!/usr/bin/env python3
"""Inspect basic ELF metadata without external Python packages."""
from __future__ import annotations
import json
import struct
import sys
from pathlib import Path

MACHINES = {3: "Intel 80386", 20: "PowerPC", 21: "PowerPC64", 40: "ARM", 62: "x86-64", 183: "AArch64"}
CLASSES = {1: "ELF32", 2: "ELF64"}
DATA = {1: "little-endian", 2: "big-endian"}
TYPES = {1: "relocatable", 2: "executable", 3: "shared-object", 4: "core"}


def inspect(path: Path) -> dict:
    raw = path.read_bytes()
    if len(raw) < 52 or raw[:4] != b"\x7fELF":
        raise ValueError("Input is not a complete ELF header")
    elf_class, encoding = raw[4], raw[5]
    if elf_class not in CLASSES or encoding not in DATA:
        raise ValueError("Unsupported ELF class or byte order")
    prefix = "<" if encoding == 1 else ">"
    e_type, e_machine = struct.unpack_from(prefix + "HH", raw, 16)
    version, entry = struct.unpack_from(prefix + "IQ" if elf_class == 2 else prefix + "II", raw, 20)
    if version != 1:
        raise ValueError(f"Unsupported ELF version {version}")
    return {
        "path": str(path),
        "file_size": len(raw),
        "class": CLASSES[elf_class],
        "endianness": DATA[encoding],
        "type": TYPES.get(e_type, f"unknown({e_type})"),
        "machine_id": e_machine,
        "machine": MACHINES.get(e_machine, f"unknown({e_machine})"),
        "entry_point": hex(entry),
        "program_header_offset": struct.unpack_from(prefix + ("Q" if elf_class == 2 else "I"), raw, 32 if elf_class == 2 else 28)[0],
        "section_header_offset": struct.unpack_from(prefix + ("Q" if elf_class == 2 else "I"), raw, 40 if elf_class == 2 else 32)[0],
        "note": "Basic header inspection only; this does not prove Xbox 360 bootability.",
    }


if __name__ == "__main__":
    if len(sys.argv) != 2:
        raise SystemExit(f"usage: {sys.argv[0]} FILE.elf")
    try:
        print(json.dumps(inspect(Path(sys.argv[1])), indent=2))
    except (OSError, ValueError, struct.error) as exc:
        print(f"ELF inspection failed: {exc}", file=sys.stderr)
        raise SystemExit(1)
