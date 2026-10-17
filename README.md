# God of War III — Xbox 360 RGH Port

> **Status: planning / bootstrap.** This repository does not currently contain a playable port, a verified Xenon ELF, or a verified Xbox 360 XEX.

## Goal

Investigate a native Xbox 360 RGH porting path for *God of War III* (originally released for PlayStation 3), starting with a minimal homebrew **Xenon.elf** test program and only later evaluating a **default.xex** build.

This project is not an executable converter. The PS3 Cell processor/SPU workload, platform APIs, graphics pipeline, audio, storage, and game engine would require substantial porting or reimplementation. Feasibility depends on lawful access to the necessary source code and assets.

## Current verified repository state

- Repository bootstrap and planning documentation only.
- No game engine implementation is present.
- No toolchain installation has been verified here.
- No ELF/XEX build or Xbox 360 hardware test has been completed.

## Milestones

1. **0.1b — Repository audit and technical plan:** document scope, dependencies, constraints, and acceptance tests.
2. **0.2b — Toolchain verification:** identify a reproducible Free60/libXenon environment and capture compiler/version output.
3. **0.3b — Minimal ELF prototype:** implement a small independent homebrew entry point and confirm its build output is actually an ELF for the expected PowerPC target.
4. **0.4b — Runtime smoke test:** test startup and basic diagnostics on compatible hardware/emulation; record logs and limitations.
5. **0.5b — Portability assessment:** map the required PS3 subsystems to Xbox 360 equivalents and identify blockers before game-engine work.
6. **Later — Native engine work:** only proceed when code/assets and legal permissions are available; implement and test subsystems incrementally.
7. **XEX milestone:** produce and validate `default.xex` only after the ELF workflow and target-specific packaging path are confirmed.

## Proposed layout

```
docs/       architecture, roadmap, test records
src/        original port scaffolding (no proprietary game code/assets)
tests/      host-side tests for portable components
tools/      reproducible build/validation scripts
.github/    CI for checks that can run in a hosted environment
```

## Reporting rules

Every progress report must distinguish:
- **Planned** — documented but not implemented.
- **Implemented** — source code exists.
- **Compiled** — a build completed and logs/artifacts were checked.
- **Tested** — behavior was executed and the test result recorded.

Never describe a planned feature as implemented, or a build as tested without evidence.

## Legal and asset policy

Do not commit proprietary game executables, game data, extracted assets, keys, or copyrighted source code. Use only material you are authorized to use.
