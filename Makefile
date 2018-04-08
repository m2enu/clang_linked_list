MAKEFLAGS       += --no-builtin-rules
CC              := gcc
CFLAGS          := -Wall -Wextra -MMD -MP
LDFLAGS         :=
LIBS            :=
DIR_SRC         := src
DIR_OBJ         := obj
DIR_SRCS        := $(shell find $(DIR_SRC) -type d)
INCLUDE         := $(foreach dir,$(DIR_SRCS),-I$(dir))
SRC_EXCLUDES    :=
SRC_TARGETS     := $(foreach dir,$(DIR_SRCS),$(wildcard $(dir)/*.c))
SRCS            := $(filter-out $(SRC_EXCLUDES),$(SRC_TARGETS))
OBJS            := $(addprefix $(DIR_OBJ)/,$(SRCS:.c=.o))
DEPS            := $(OBJS:.o=.d)
TARGET          := $(notdir $(shell pwd)).o
RM              := rm -rf

all: $(TARGET)

clean:
	$(RM) $(DIR_OBJ)/* $(TARGET)

$(TARGET): $(OBJS)
	$(CC) -o $@ $^ $(LDFLAGS)

$(DIR_OBJ)/%.o: %.c
	@[ -d `dirname $@` ] || mkdir -p `dirname $@`
	$(CC) -o $@ -c $< $(CFLAGS) $(INCLUDE)

ifneq ($(MAKECMDGOALS), clean)
-include $(DEPS)
endif

.PHONY: all clean

# end of file {{{1
# vim:ft=make:noet:ts=4:nowrap:fdm=marker
