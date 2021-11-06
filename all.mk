# Target definition
TARGET			:= $(BIN_ROOT)/$(notdir $(shell pwd)).elf

# Additional source files
SRCS			:= $(SRCS) \
	$(SRC_ROOT)/main.c

