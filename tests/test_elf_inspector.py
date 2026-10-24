import importlib.util
import struct
import tempfile
import unittest
from pathlib import Path

MODULE_PATH = Path(__file__).resolve().parents[1] / "tools" / "inspect_elf.py"
spec = importlib.util.spec_from_file_location("inspect_elf", MODULE_PATH)
module = importlib.util.module_from_spec(spec)
assert spec.loader is not None
spec.loader.exec_module(module)


def minimal_elf32() -> bytes:
    data = bytearray(52)
    data[:4] = b"\x7fELF"
    data[4] = 1  # ELF32
    data[5] = 2  # big-endian
    data[6] = 1  # ELF version
    struct.pack_into(">HHI", data, 16, 2, 20, 1)  # executable, PowerPC, version
    struct.pack_into(">I", data, 24, 0x1000)
    return bytes(data)


class ElfInspectorTests(unittest.TestCase):
    def test_recognizes_big_endian_powerpc_elf32(self):
        with tempfile.TemporaryDirectory() as directory:
            path = Path(directory) / "probe.elf"
            path.write_bytes(minimal_elf32())
            report = module.inspect(path)
            self.assertEqual(report["class"], "ELF32")
            self.assertEqual(report["endianness"], "big-endian")
            self.assertEqual(report["machine"], "PowerPC")
            self.assertEqual(report["entry_point"], "0x1000")

    def test_rejects_non_elf(self):
        with tempfile.TemporaryDirectory() as directory:
            path = Path(directory) / "not-elf.bin"
            path.write_bytes(b"not an elf file")
            with self.assertRaises(ValueError):
                module.inspect(path)


if __name__ == "__main__":
    unittest.main()
