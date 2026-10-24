# Xenon ELF validation gate

## Probe source

`tools/check_xenon_source.c` is a tiny diagnostic executable that reports pointer width, integer width, byte order, compiler version and whether common PowerPC compiler macros are defined. It does not use any undocumented console APIs.

Build it only after `make toolchain-check` reports the expected commands:

```sh
xenon-gcc -Wall -Wextra -Werror -O2 -o build/xenon-probe.elf tools/check_xenon_source.c
python3 tools/inspect_elf.py build/xenon-probe.elf
```

These are candidate commands, not a guarantee that a particular toolchain's startup files or link flags are correct. If linking fails, record the exact diagnostic and consult the configured toolchain's own examples; do not suppress errors or fabricate an output file.

## ELF inspector

`tools/inspect_elf.py FILE.elf` reports basic ELF class, byte order, machine ID, file type, entry point and header offsets. Its host tests validate the parser against a synthetic ELF header and malformed input. Synthetic test success is not evidence that an actual Xenon ELF has been built.

## Acceptance criteria

1. The target compiler is found and its version and target are recorded.
2. Probe compiles and links without errors.
3. The actual output file exists and is non-empty.
4. ELF inspector reports the expected class, byte order and PowerPC machine type for the selected toolchain.
5. Undefined symbols and required runtime libraries are reviewed.
6. Runtime launch is tested separately in a compatible Xbox 360 RGH environment.

Until these conditions have evidence, target ELF and XEX remain **not verified**.
