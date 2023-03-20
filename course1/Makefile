#******************************************************************************
# Copyright (C) 2017 by Alex Fosdick - University of Colorado
#
# Redistribution, modification or use of this software in source or binary
# forms is permitted as long as the files maintain this copyright. Users are 
# permitted to modify this and use it to learn about the field of embedded
# software. Alex Fosdick and the University of Colorado are not liable for any
# misuse of this material. 
#
#*****************************************************************************

#------------------------------------------------------------------------------
# makefile for m2 assesment
#
# Use: make [TARGET] [PLATFORM-OVERRIDES]
#
# Build Targets:
#      <FILE>.o - Builds <FILE>.o object file
#      <FILE>.i - Builds <FILE>.i preprocessed file
#      <FILE>.asm - Builds <FILE>.asm assembled file
#      <FILE>.dep - Builds <FILE>.dep dependencies file
#      <FILE>.out - Compile and links all sources to <FILE>.out 
#      build - Builds and links all source files to predefined target and generates *.o, *.dep, c1m2.map files
#	   compile-all - Compiles all objects files
#      clean - removes all generated files
#
# Platform Overrides:
#      CPU - ARM Cortex Architecture (cortex-m4)
#      ARCH - ARM Architecture (arm, thumb)
#      SPECS - Specs file to give the linker (nosys.specs)
#
#------------------------------------------------------------------------------
#include sources.mk

# Platform Overrides
PLATFORM ?= HOST
include sources.mk

#a = $(shell echo $(PLATFORM))
#$(info $(a))
# Architectures Specific Flags
LINKER_FILE = ../msp432p401r.lds
CPU = cortex-m4
ARCH = armv7e-m
SPECS = nosys.specs

# Compiler Flags and Defines
ifeq ($(PLATFORM), HOST)
#	CC = gcc
	CPPFLAGS = -D$(PLATFORM)
	CFLAGS = -Wall -Werror -g -O0 -std=c99
	LDFLAGS = -Wl,-Map=$(TARGET).map
	TOOL_CHAIN =
else
#	CC = arm-none-eabi-gcc
	CPPFLAGS = -D$(PLATFORM)
	LD = arm-none-eabi-ld
	LDFLAGS = -T $(LINKER_FILE) -Wl,-Map=$(TARGET).map
	CFLAGS = -Wall -Werror -g -O0 -std=c99 -mcpu=$(CPU) -march=$(ARCH) --specs=$(SPECS) -mthumb -mfloat-abi=soft -mfpu=fpv4-sp-d16
	TOOL_CHAIN = arm-none-eabi-
#!!!!!!!!!!!!!!!!!!flag -mfloat-abi=hard was changed to -mfloat-abi=soft, becouse armv7e-m is not supported by host machine!!!!!!!!!!!!!!!!!!!!!!!!!!!
endif
CC = $(TOOL_CHAIN)gcc
OBJ=$(SOURCES:.c=.o)
DEPS=$(SOURCES:.c=.dep)
FILES = $(SOURCES:.c=)
TARGET = c1m2
%.i: %.c
	@echo "Generate preprocessed output for $(<) -> $@"
	$(CC)  $(CPPFLAGS) $(INCLUDES) $(CFLAGS) -E -o $@ -c $<
	
%.o : %.c
	@echo "Generate object file for $(<) -> $@"
	$(CC)  $(CPPFLAGS) $(INCLUDES) $(CFLAGS) -o $@ -c $<
	
%.dep: %.c
	$(CC)  $(CPPFLAGS) $(INCLUDES) $(CFLAGS) $(LDFLAGS) -M $< -MMD -MP -MF $@
%.asm: %.o
	@echo "Generate assembly output for $(<) -> $@"
	$(TOOL_CHAIN)objdump -s -S --disassemble $< > $@
$(TARGET).asm: $(TARGET).out
	@echo "Generate assembly output for $(<) -> $@"
	$(TOOL_CHAIN)objdump -s -S --disassemble $< > $@
$(TARGET).out:
	$(CC)  $(CPPFLAGS) -o $(TARGET).out $(SOURCES) $(INCLUDES) $(CFLAGS) $(LDFLAGS)
.PHONY: compile-all
compile-all: $(OBJ)
		@echo "Generate objects output for $(SOURCES)"
.PHONY: build
build: $(DEPS) $(OBJ)
	@echo "Compiling executable $(TARGET).out"
	$(CC)  $(CPPFLAGS) $(LDFLAGS) -o $(TARGET).out $(SOURCES) $(INCLUDES) $(CFLAGS)
	$(TOOL_CHAIN)size -Atd $(TARGET).out
.PHONY: clean
clean:
	rm -f *.i *.out *.map *.asm *.o *.dep
