# Portable core modules

These generic original modules are not derived from the proprietary game engine.

## Result codes

`src/core/result.h` defines status values. `gow3_result_name` maps known codes to stable diagnostic strings and returns `unknown_error` for unrecognized values.

## Fixed-capacity ring buffer

`src/core/ring_buffer.h` defines a caller-owned byte buffer. It performs no allocation and has no platform SDK dependency. The caller must keep storage valid for the buffer's lifetime.

- Initialization rejects null storage and zero capacity.
- Writes reject requests larger than remaining free space.
- Reads reject requests larger than the current size.
- Read/write operations support wraparound.
- This implementation is single-threaded and not safe for concurrent access without external synchronization.

## Unit test coverage

`tests/test_core.c` covers status-name mapping, byte round-trip, wraparound, overflow rejection and invalid initialization. Passing host tests does not establish Xenon ABI compatibility or Xbox 360 runtime behavior.
