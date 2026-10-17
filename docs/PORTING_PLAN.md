# Technical porting plan — God of War III to Xbox 360

## Scope and feasibility

The target is an Xbox 360 running RGH homebrew. The first engineering target is a small, independent Xenon ELF smoke test; a game port is a separate and much larger effort.

The original PS3 title targets the Cell Broadband Engine and PS3 system services. Xbox 360 uses a different PowerPC-based Xenon CPU, a different GPU/API environment, and different operating-system services. This means the work cannot be reduced to renaming or repackaging an executable.

## Phase A — Repository and toolchain

- Keep proprietary game code and assets out of this repository.
- Record the exact toolchain source, version, host OS, build command, and compiler output.
- Verify the compiler target and output file format before claiming success.
- Keep build artifacts separate from source and do not commit unverified binaries.

**Exit criteria:** a reproducible build log and ELF format inspection from a known toolchain.

## Phase B — Minimal ELF smoke test

Create an independent homebrew program with only APIs confirmed by the selected toolchain documentation. Avoid guessing libXenon symbols. Validate compilation first, then test startup on compatible hardware or a suitable development environment.

**Exit criteria:** source, exact build command, compiler log, ELF inspection, and runtime test record.

## Phase C — Platform capability map

Document candidate replacements for:
- threads and scheduling;
- memory allocation and address-space assumptions;
- file and optical-media access;
- controller input;
- audio output and mixing;
- graphics command submission, shaders, render targets, and synchronization;
- save data and configuration;
- crash diagnostics.

For each subsystem, record evidence, unknowns, and a small acceptance test. Do not claim a subsystem is implemented merely because it appears in this list.

## Phase D — PS3-specific engine assessment

With legally authorized source and assets available, inventory CPU and SPU jobs, synchronization points, GPU commands/shaders, memory assumptions, and platform API dependencies. Estimate each subsystem only after inspection. If source is unavailable, limit work to independent homebrew scaffolding and feasibility analysis.

## Phase E — XEX packaging

Only after the ELF target and startup behavior are verified, document a supported conversion/linking/packaging workflow for the chosen toolchain. Confirm that the output is actually an Xbox 360 XEX and validate it in the target environment. Do not infer success from a filename extension.

## Progress labels

- **Planned:** described only.
- **Implemented:** source is present.
- **Compiled:** build completed and output was inspected.
- **Runtime-tested:** execution and result were recorded.
