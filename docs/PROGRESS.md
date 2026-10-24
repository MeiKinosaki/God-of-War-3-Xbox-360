# Progress log

## Version 0.4b — toolchain discovery gate added

### Implemented
- Added `tools/check_xenon_toolchain.py` to report whether expected Xenon commands are available, their resolved paths and version output.
- Added `docs/XENON_TOOLCHAIN.md` with repeatable validation commands and explicit acceptance gates.
- Kept host CI independent from any locally installed Xenon SDK.

### Host validation evidence
- GitHub Actions run `40051061687` completed successfully for commit `fd0c48d9e7f6868d4c42e57c068148d0e298f94d`; the `host-checks` job passed the combined `make check` step.
- The new toolchain checker has been committed, but no Xenon toolchain run is claimed by this log. It must be run in the configured target environment.

### Not yet verified
- Xenon compiler availability, target triple, ABI, startup objects and libraries.
- Xenon ELF output or ELF metadata.
- Xbox 360 hardware/emulator startup.
- Any port of the original game's engine, graphics, audio, assets or gameplay.
- `default.xex` generation or execution.

### Parallel workstreams
1. **Portable core:** host-tested result codes and ring buffer.
2. **Build/CI:** host checks pass on the recorded commit; rerun CI after this milestone commit.
3. **Toolchain discovery:** checker and instructions now exist; actual target environment is still unverified.
4. **Port feasibility:** identify PS3-only APIs, SPU work, rendering, audio and content dependencies from authorized source material.

### Exit criteria for 0.4b
- Run the checker in the intended Xenon environment.
- Capture tool paths, version output and compiler target.
- Compile a minimal target program.
- Inspect the resulting ELF architecture and dependencies.
- Keep the milestone open until the evidence exists.
