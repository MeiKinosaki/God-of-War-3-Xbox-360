# Bootstrap only. Validate Free60/libXenon startup objects and flags before target use.
XENON_CC ?= xenon-gcc
HOST_CC ?= cc
PYTHON ?= python3
BUILD_DIR ?= build
TARGET_ELF ?= $(BUILD_DIR)/GodOfWar3.elf32
PROBE_ELF ?= $(BUILD_DIR)/xenon-probe.elf
CFLAGS ?= -Wall -Wextra -Werror -O2
CORE_SOURCES := src/core/result.c src/core/ring_buffer.c
.PHONY: all check host-check unit-tests inspector-tests toolchain-check xenon-probe inspect-elf xenon-elf clean
all: check
check: host-check unit-tests inspector-tests
$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)
host-check: | $(BUILD_DIR)
	$(HOST_CC) $(CFLAGS) -o $(BUILD_DIR)/bootstrap-host src/main.c
	./$(BUILD_DIR)/bootstrap-host
unit-tests: | $(BUILD_DIR)
	$(HOST_CC) $(CFLAGS) -Isrc/core -o $(BUILD_DIR)/test-core tests/test_core.c $(CORE_SOURCES)
	./$(BUILD_DIR)/test-core
	$(PYTHON) tests/check_source.py
inspector-tests:
	$(PYTHON) -m unittest discover -s tests -p 'test_*.py' -v
toolchain-check:
	$(PYTHON) tools/check_xenon_toolchain.py
xenon-probe: | $(BUILD_DIR)
	$(XENON_CC) $(CFLAGS) -o $(PROBE_ELF) tools/check_xenon_source.c
inspect-elf:
	$(PYTHON) tools/inspect_elf.py $(TARGET_ELF)
xenon-elf: | $(BUILD_DIR)
	$(XENON_CC) $(CFLAGS) -o $(TARGET_ELF) src/main.c
clean:
	rm -rf $(BUILD_DIR)
