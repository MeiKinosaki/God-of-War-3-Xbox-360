# God of War III — Xbox 360 RGH Port

> **Status: bootstrap / host-side core validated.** This repository does not contain a playable port, a verified Xenon ELF, or a verified Xbox 360 XEX.

## Goal

Investigate a native Xbox 360 RGH porting path for *God of War III* (originally released for PlayStation 3), starting with a minimal homebrew **Xenon.elf** test program and only later evaluating a **default.xex** build.

This is not an executable converter. The PS3 Cell processor/SPU workload, platform APIs, graphics pipeline, audio, storage, and game engine require substantial porting or reimplementation. Feasibility depends on lawful access to the necessary source code and assets.

## Current verified state

- Minimal original C bootstrap exists.
- Portable result-code and fixed-capacity ring-buffer modules exist.
- GitHub Actions successfully ran host compilation and generic core unit tests for commit `fd0c48d9e7f6868d4c42e57c068148d0e298f94d`.
- This does **not** verify Xenon target compatibility.
- No Xenon toolchain has been verified; no Xenon ELF has been inspected.
- No Xbox 360 hardware test or game engine implementation has been completed.

## Sequential milestones

1. **0.1b — Planning:** scope, constraints, and acceptance tests documented.
2. **0.2b — Bootstrap:** initial C entry point, build scaffolding and CI added.
3. **0.3b — Portable core:** generic modules and host-side tests; CI passed.
4. **0.4b — Xenon ELF:** verify compiler/target and build/inspect a real ELF.
5. **0.5b — Runtime smoke test:** test startup on compatible hardware or environment.
6. **0.6b — Portability assessment:** map PS3 subsystems and blockers from available authorized source.
7. **Later — Native game work:** only after source/assets, permissions, and feasibility are established.
8. **XEX milestone:** produce and validate `default.xex` only after the ELF workflow and packaging path are confirmed.

## Repository layout

- `src/` — original bootstrap and portable modules
- `tests/` — host-side checks and unit tests
- `docs/` — architecture, build instructions, progress and 500-step roadmap
- `.github/workflows/` — continuous integration

## Evidence policy

Every feature must be labeled **planned**, **implemented**, **compiled**, or **runtime-tested** as appropriate. Never describe planned features as implemented or claim a target build without a checked artifact and recorded evidence.

## Legal and asset policy

Do not commit proprietary game executables, game data, extracted assets, keys, or copyrighted source code. Use only material you are authorized to use.
