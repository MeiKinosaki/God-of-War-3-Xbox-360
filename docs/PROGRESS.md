# Progress log

## Version 0.5b — ELF validation tooling and probe source

### Implemented
- Added a minimal diagnostic C probe for pointer width, integer width, endianness, compiler version and common PowerPC architecture macros.
- Added a dependency-free ELF header inspector.
- Added host unit tests for parsing a synthetic big-endian PowerPC ELF32 header and rejecting invalid input.
- Integrated the inspector's Python unit tests into `make check` through the `inspector-tests` target.
- Documented candidate probe commands and strict acceptance criteria.

### Verified evidence
- GitHub Actions run `40051218623` completed successfully for commit `b96cb51a79aedaeaf59cbf0fc38a5990017eb0ec`.
- GitHub Actions run `40051334928` completed successfully for commit `4ef480a9ea34a1c074b1961d520cc722ebdc252a`.
- GitHub Actions run `40051357983` completed successfully; the `host-checks` job and its “Run host checks and portable unit tests” step both report success.
- Host-side tests use a synthetic ELF fixture. This validates parser behavior only; it is not a generated Xenon executable.

### Not verified
- No Xenon compiler execution has been recorded.
- No actual Xenon probe ELF has been generated or inspected.
- No Xbox 360 RGH runtime launch has been performed.
- No game engine, rendering, audio, content loading or gameplay port is implemented.
- No `default.xex` has been generated or tested.

### Parallel workstreams
1. **Portable core:** generic result codes and ring buffer, host CI validated on prior commits.
2. **ELF inspection:** parser and synthetic tests are integrated into CI and the latest checked run passed.
3. **Xenon toolchain:** tool-discovery utility exists; actual target environment remains unverified.
4. **Port feasibility:** PS3-to-Xbox 360 dependency inventory remains blocked on authorized source/assets.

### Next gate — do not mark 0.5b target validation complete yet
1. Run `make toolchain-check` in an environment that actually has the intended Xenon/libXenon toolchain configured.
2. Run the Xenon probe build and preserve its real compiler output.
3. Inspect the resulting ELF and record its architecture, class, endianness and machine fields.
4. Only after those checks pass, begin the 0.6b runtime smoke-test stage.
5. Keep `Xenon.elf`, `default.xex`, and RGH execution marked **unverified** until actual artifacts and logs exist.

Host CI passing is not evidence of a Xenon cross-build or a playable port.
