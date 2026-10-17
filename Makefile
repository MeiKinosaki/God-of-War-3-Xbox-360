# Bootstrap build only. Toolchain flags and startup requirements must be
# confirmed against the selected Free60/libXenon environment before use.
XENON_CC ?= xenon-gcc
HOST_CC ?= cc
BUILD_DIR ?= build
TARGET_ELF ?= $(BUILD_DIR)/GodOfWar3.elf32
SOURCE := src/main.c
CFLAGS ?= -Wall -Wextra -Werror -O2

.PHONY: all host-check xenon-elf clean
all: host-check

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

host-check: | $(BUILD_DIR)
	$(HOST_CC) $(CFLAGS) -o $(BUILD_DIR)/bootstrap-host $(SOURCE)
	./$(BUILD_DIR)/bootstrap-host

# Requires a verified Xenon cross-toolchain. This target has not yet been run.
xenon-elf: | $(BUILD_DIR)
	$(XENON_CC) $(CFLAGS) -o $(TARGET_ELF) $(SOURCE)

clean:
	rm -rf $(BUILD_DIR)
