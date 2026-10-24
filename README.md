# God of War III — Xbox 360 RGH Port

> **Status: bootstrap / host-side core validated.** This repository does not contain a playable port, a verified Xenon ELF, or a verified Xbox 360 XEX.

## Goal

Investigate a native Xbox 360 RGH porting path for *God of War III* (originally released for PlayStation 3), starting with a minimal homebrew **Xenon.elf** test program and only later evaluating a **default.xex** build.

This is not an executable converter. The PS3 Cell processor/SPU workload, platform APIs, graphics pipeline, audio, storage, and game engine require substantial porting or reimplementation. Feasibility depends on lawful access to the necessary source code and assets.

## Current verified state

- Minimal original C bootstrap exists.
- Portable result-code and fixed-capacity ring-buffer modules exist.
- GitHub Actions passed host compilation, portable-core tests and static checks for commit `b96cb51a79aedaeaf59cbf0fc38a5990017eb0ec`.
- A local Xenon toolchain discovery checker, diagnostic C probe source and ELF header inspector are present.
- Host-side tests for the ELF inspector have been added; current CI result must be checked before calling them passed.
- No Xenon target build or actual ELF inspection has been recorded.
- No Xbox 360 hardware test or game-engine implementation has been completed.

## Sequential milestones

1. **0.1b — Planning:** scope, constraints, and acceptance tests documented.
2. **0.2b — Bootstrap:** initial C entry point, build scaffolding and CI added.
3. **0.3b — Portable core:** generic modules and host-side tests; CI passed.
4. **0.4b — Toolchain discovery:** checker added; actual toolchain/ELF remain pending.
5. **0.5b — ELF validation:** probe source and inspector/tests added; actual Xenon output pending.
6. **0.6b — Runtime smoke test:** test startup on compatible hardware or environment.
7. **0.7b — Portability assessment:** map PS3 subsystems and blockers from available authorized source.
8. **Later — Native game work:** only after source/assets, permissions, and feasibility are established.
9. **XEX milestone:** produce and validate `default.xex` only after the ELF workflow and packaging path are confirmed.

## Useful commands

```sh
make check
make toolchain-check
make xenon-probe
python3 tools/inspect_elf.py build/xenon-probe.elf
```

The Xenon target commands are attempts only; they must not be treated as successful unless the compiler runs, the output exists, and ELF inspection confirms the expected target.

## Evidence policy

Every feature must be labeled **planned**, **implemented**, **compiled**, or **runtime-tested** as appropriate. Never describe planned features as implemented or claim a target build without a checked artifact and recorded evidence.

## Legal and asset policy

Do not commit proprietary game executables, game data, extracted assets, keys, or copyrighted source code. Use only material you are authorized to use.
