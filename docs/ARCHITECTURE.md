# Architecture map

## Boundary

This repository currently contains only a minimal, original bootstrap program. The following is a design map, not a claim that these systems are implemented.

## Proposed layers

1. **Platform adapter** — Xbox 360 startup, lifecycle, file access, controller input, audio output, and diagnostics using APIs verified for the selected homebrew SDK.
2. **Portable runtime** — bounded allocation interfaces, logging, configuration parsing, and deterministic tests that can run on a host.
3. **Graphics abstraction** — resource lifetime, textures, buffers, shader permutations, render targets, and synchronization. No renderer is implemented.
4. **Audio abstraction** — asset metadata, mixer interface, voice lifetime, and output scheduling. No game audio is included.
5. **Game-specific integration** — only possible after authorized source code and assets are available and the legal and technical feasibility is established.

## PS3-to-Xbox 360 assessment matrix

| Area | Known difference / risk | Evidence required before implementation |
|---|---|---|
| CPU | PS3 Cell PPE/SPUs differ from Xbox 360 Xenon cores/threads | Source-level job inventory and profiling |
| GPU | Different GPU architecture, APIs, shader formats and synchronization | Shader/resource inventory and test scene |
| Memory | Different memory map, allocation assumptions and budgets | Runtime memory map and peak-use measurements |
| OS services | Different threading, files, timing and system APIs | Call-site inventory and adapter tests |
| Audio | Different output APIs, buffering and mixing paths | Format inventory and latency tests |
| Input | Different controller APIs and button mapping | Input mapping and device test |
| Storage | Different package and save-data expectations | Authorized asset-loading prototype |
| Packaging | ELF and Xbox 360 XEX are distinct executable formats | Toolchain documentation, format inspection and hardware test |

## Design rules

- Do not add guessed SDK symbols or unverified compiler flags.
- Keep proprietary game code, executables, keys and extracted assets out of the repository.
- Add one subsystem at a time with a test and a written result.
- Mark each feature as planned, implemented, compiled, or runtime-tested.
