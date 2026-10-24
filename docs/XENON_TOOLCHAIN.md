# Xenon toolchain validation

## Purpose

Record which Free60/libXenon tools are available in the current build environment before attempting a target build. The checker does not install tools, download SDKs, or infer that a compiler is valid just because a command exists.

## Run locally

```sh
python3 tools/check_xenon_toolchain.py
```

The command prints a JSON report containing the `DEVKITXENON` environment variable, PATH, tool availability, resolved paths and version strings where available. It returns exit code 1 if any expected tool is missing.

Expected command names:
- `xenon-gcc`
- `xenon-ld`
- `xenon-ar`
- `xenon-objcopy`
- `xenon-objdump`
- `elf2xex`

A tool being present is only the first check. Follow-up acceptance gates are a compiler target/ABI check, a minimal compile, ELF inspection, unresolved-symbol review and an actual launch test in a compatible environment. Do not rename an ELF file to `default.xex`; XEX generation requires a valid supported packaging tool and procedure.

## CI policy

Generic host CI does not require a proprietary or locally installed Xenon SDK. Run the target checker only in an environment where the user has configured an authorized toolchain. Keep its raw output in the build log and mark absent tools as blockers, not as completed steps.
