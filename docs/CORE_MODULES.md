# Portable core modules

These generic original modules are scaffolding, not code from the proprietary game engine.

## Result codes
`src/core/result.h` defines stable result values; `gow3_result_name` returns a diagnostic name.

## Fixed-capacity ring buffer
The buffer uses caller-owned storage, performs no allocation, checks capacity and supports wraparound. It is single-threaded and requires external synchronization if shared.

## Tests
`tests/test_core.c` covers result mapping, wraparound, overflow rejection and invalid initialization. Host test success does not establish Xenon ABI compatibility or Xbox 360 runtime behavior.
