# Progress log

## Version 0.2b — bootstrap scaffolding

### Added
- Project README with honest status and staged roadmap.
- Technical porting plan.
- Minimal original C entry point in `src/main.c`.
- Makefile with distinct host-check and Xenon-ELF targets.
- Static scaffold checks in `tests/check_source.py`.
- Build and validation instructions.
- Architecture risk matrix and test acceptance matrix.
- GitHub Actions workflow for host-side checks.

### Not yet verified
- The CI workflow has not been observed completing successfully in this record.
- No Xenon cross-compiler version or target configuration has been verified.
- No Xenon ELF has been built or inspected.
- No Xbox 360 hardware test has been performed.
- No game engine, renderer, audio engine, or gameplay code has been ported.
- No `default.xex` exists as a verified artifact.

### Next milestone: 0.3b
Run and record the host checks, inspect the GitHub Actions result, then verify the actual Xenon toolchain and compiler target before attempting an ELF build.
