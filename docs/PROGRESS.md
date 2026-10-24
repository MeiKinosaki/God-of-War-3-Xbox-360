# Progress log

## Version 0.5b — ELF validation tooling and probe source

### Implemented
- Added a minimal diagnostic C probe for pointer width, integer width, endianness, compiler version and common PowerPC architecture macros.
- Added a dependency-free ELF header inspector.
- Added host unit tests for parsing a synthetic big-endian PowerPC ELF32 header and rejecting invalid input.
- Added automated unit tests for the Xenon toolchain checker, including all-tools-present, missing-tool reporting, version-flag fallback, and timeout handling.
- Documented candidate probe commands and strict acceptance criteria.

### Verified evidence
- GitHub Actions run `40051218623` completed successfully for commit `b96cb51a79aedaeaf59cbf0fc38a5990017eb0ec`.
- GitHub Actions run `40051334928` completed successfully for commit `4ef480a9ea34a1c074b1961d520cc722ebdc252a`.
- GitHub Actions run `40051357983` completed successfully; the `host-checks` job and its “Run host checks and portable unit tests” step both report success.
- Toolchain-checker tests were expanded in commit `5b2c6dd417d53bdef959bd9763043e984cac09c3`; CI for that newest commit still needs confirmation.
- Host-side ELF tests use a synthetic fixture. This validates parser behavior only; it is not a generated Xenon executable.

### Not verified
- The newest toolchain-checker tests have not yet been confirmed by a completed CI run.
- No Xenon compiler execution has been recorded.
- No actual Xenon probe ELF has been generated or inspected.
- No Xbox 360 RGH runtime launch has been performed.
- No game engine, rendering, audio, content loading or gameplay port is implemented.
- No `default.xex` has been generated or tested.

### Parallel workstreams
1. **Portable core:** generic result codes and ring buffer, host CI validated on prior commits.
2. **ELF inspection:** parser and synthetic tests are integrated into CI; the last checked CI run passed.
3. **Xenon toolchain checker:** automated tests now cover success/failure and version-probe edge cases; newest CI pending verification.
4. **Target toolchain:** actual Free60/libXenon environment remains unverified.
5. **Port feasibility:** PS3-to-Xbox 360 dependency inventory remains blocked on authorized source/assets.

### Next gate — do not mark 0.5b target validation complete yet
1. Confirm CI passes with the newest toolchain-checker tests.
2. Run `make toolchain-check` in an environment that actually has the intended Xenon/libXenon toolchain configured.
3. Run the Xenon probe build and preserve its real compiler output.
4. Inspect the resulting ELF and record its architecture, class, endianness and machine fields.
5. Only after those checks pass, begin the 0.6b runtime smoke-test stage.
6. Keep `Xenon.elf`, `default.xex`, and RGH execution marked **unverified** until actual artifacts and logs exist.

Host CI passing is not evidence of a Xenon cross-build or a playable port.
