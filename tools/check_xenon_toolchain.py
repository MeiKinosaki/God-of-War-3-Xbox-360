#!/usr/bin/env python3
"""Report local Xenon tool availability without installing or guessing SDK files."""
from __future__ import annotations

import json
import os
import shutil
import subprocess
from pathlib import Path

TOOLS = ("xenon-gcc", "xenon-ld", "xenon-ar", "xenon-objcopy", "xenon-objdump", "elf2xex")


def run_version(executable: str) -> str:
    for args in (("--version",), ("-v",)):
        try:
            result = subprocess.run(
                [executable, *args],
                check=False,
                capture_output=True,
                text=True,
                timeout=5,
            )
        except (OSError, subprocess.TimeoutExpired):
            continue
        output = (result.stdout or result.stderr).strip()
        if output:
            return output.splitlines()[0][:300]
    return "version output unavailable"


def main() -> int:
    found = {}
    for name in TOOLS:
        path = shutil.which(name)
        found[name] = {
            "available": path is not None,
            "path": str(Path(path).resolve()) if path else None,
            "version": run_version(path) if path else None,
        }

    report = {
        "devkitxenon": os.environ.get("DEVKITXENON"),
        "path": os.environ.get("PATH", ""),
        "tools": found,
        "note": "Availability is not proof of a working Xenon build or a valid XEX.",
    }
    print(json.dumps(report, indent=2))
    missing = [name for name, info in found.items() if not info["available"]]
    if missing:
        print("Missing tools: " + ", ".join(missing))
        return 1
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
