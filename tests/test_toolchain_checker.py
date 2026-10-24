import contextlib
import importlib.util
import io
import unittest
from pathlib import Path
from unittest.mock import patch

MODULE_PATH = Path(__file__).resolve().parents[1] / "tools" / "check_xenon_toolchain.py"
spec = importlib.util.spec_from_file_location("check_xenon_toolchain", MODULE_PATH)
module = importlib.util.module_from_spec(spec)
assert spec.loader is not None
spec.loader.exec_module(module)


class ToolchainCheckerTests(unittest.TestCase):
    def test_returns_success_when_every_expected_tool_is_found(self):
        output = io.StringIO()
        with patch.object(module.shutil, "which", side_effect=lambda name: f"/fake/bin/{name}"), \
             patch.object(module, "run_version", return_value="test compiler 1.0"), \
             contextlib.redirect_stdout(output):
            result = module.main()

        self.assertEqual(result, 0)
        self.assertIn('"available": true', output.getvalue())
        self.assertIn('"version": "test compiler 1.0"', output.getvalue())

    def test_returns_failure_and_names_missing_tools(self):
        missing = {"xenon-gcc", "elf2xex"}
        output = io.StringIO()
        with patch.object(module.shutil, "which", side_effect=lambda name: None if name in missing else f"/fake/bin/{name}"), \
             patch.object(module, "run_version", return_value="test compiler 1.0"), \
             contextlib.redirect_stdout(output):
            result = module.main()

        self.assertEqual(result, 1)
        self.assertIn("Missing tools: xenon-gcc, elf2xex", output.getvalue())
        self.assertIn('"available": false', output.getvalue())


if __name__ == "__main__":
    unittest.main()
