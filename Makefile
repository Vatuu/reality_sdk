VERSION ?= POINT-1.0
TARGET_OUT ?= librsdk_core_$(VERSION).a

BUILD_DIR := ./build

SOURCE := $(shell find ./src -name *.cpp -or -name *.c -or -name *.s)

INCLUDE_DIRS := ./include ./include/rcp
INCLUDE_FLAGS := $(addprefix -I,$(INCLUDE_DIRS))

O_FILES := $(subst ./src, $(BUILD_DIR), $(SOURCE:.cpp=.cpp.o))

DEPENDENCIES := $(O_FILES:.o=.d)

###################################################################################

GCC := ../bin/mips64-elf-

AS := $(GCC)as
CC := $(GCC)gcc
C+++ := $(GCC)g++
CPP := $(GCC)cpp
LD := $(GCC)ld
AR := $(GCC)ar
OBJDUMP := $(GCC)objdump
OBJCOPY := $(GCC)objcopy

INSTRUCTIONS := -mips2 -32
OPTIMIZATION := -O1


CPPFLAGS := $(INCLUDE_FLAGS) -MMD -MP
CXXFLAGS := -fno-builtin -G 0 $(INCLUDE_FLAGS) $(OPTIMIZATION)
ASFLAGS = -v -Wab,-r4300_mul -non_shared -G 0 $(INCLUDE_FLAGS) $(INSTRUCTIONS) $(OPTIMIZATION)
CC_CHECK := $(CXX) -fsyntax-only $(CPPFLAGS) -std=gnu++20 -Wall -Wextra -Wno-format-security

####################################################################################

$(BUILD_DIR)/$(TARGET_OUT): $(O_FILES)
	echo $< $@
	$(CC) $(O_FILES) -o $@ 

%.cpp.o: src/%.cpp
	mkdir -p $(dir $@)
	echo $< $@
	$(CC_CHECK) -MT $@
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $< -o $@

.PHONY: clean

clean:
	$(RM) -r $(BUILD_DIR)

toutput:
	echo "OFiles $(O_FILES)"
	echo "Deps $(DEPENDENCIES)"	
	echo "Sources $(SOURCE)"

-include $(DEPENDENCIES)
