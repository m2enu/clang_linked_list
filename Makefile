MAKEFLAGS		+= --no-builtin-rules

# Target definition
TARGET			 = $(BIN_ROOT)/$(notdir $(shell pwd)).o

# Directory name
SRC_DIR			:= src
OBJ_DIR			:= obj
BIN_DIR			:= bin

# Directory root
PRJ_ROOT		:= $(abspath .)
SRC_ROOT		:= $(PRJ_ROOT)/$(SRC_DIR)
OBJ_ROOT		:= $(PRJ_ROOT)/$(OBJ_DIR)
BIN_ROOT		:= $(PRJ_ROOT)/$(BIN_DIR)

# Source files
SRCS			:= \
	$(SRC_ROOT)/main.c \

# Include directories
INC_DIRS        := \
	$(SRC_ROOT) \

# Toolchain
CC				:= gcc
RM				:= rm -rf
MKDIR			:= mkdir -p

# Compiler option
CFLAGS			:= \
	-Wall \
	-Wextra \
	-MMD \
	-MP \

# Linker option
LDFLAGS         := \

# Definition
INCLUDE			:= $(foreach dir,$(INC_DIRS),-I$(dir))
OBJS			:= $(subst $(SRC_ROOT),$(OBJ_ROOT),$(SRCS:.c=.o))
DEPS			:= $(OBJS:.o=.d)

# Quiet
ifeq ($(VERBOSE),1)
Q				:=
else
Q				:= @
endif

.PHONY: all
all: $(TARGET)

.PHONY: clean
clean:
	$(Q)$(RM) $(OBJS) $(DEPS) $(TARGET)

$(TARGET): $(OBJS)
	@[ -d `dirname $@` ] || $(MKDIR) `dirname $@`
	$(info Generating $(notdir $@))
	$(Q)$(CC) $(LDFLAGS) -o $@ $^

$(OBJ_ROOT)/%.o: $(SRC_ROOT)/%.c
	@[ -d `dirname $@` ] || $(MKDIR) `dirname $@`
	$(info Compiling $(notdir $<))
	$(Q)$(CC) $(CFLAGS) $(INCLUDE) -o $@ -c $<

ifneq ($(MAKECMDGOALS), clean)
-include $(DEPS)
endif

# end of file {{{1
# vim:ft=make:noet:ts=4:nowrap:fdm=marker
