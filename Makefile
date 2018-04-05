MAKEFLAGS   += --no-builtin-rules
CC          := gcc
CFLAGS      := -Wall -Wextra -MMD -MP
LDFLAGS     :=
LIBS        :=
DIR_SRC     := src
DIR_OBJ     := obj
DIR_SRCS    := $(shell find $(DIR_SRC) -type d)
INCLUDE     := $(foreach dir,$(DIR_SRCS),-I$(dir))
SRCS        := $(foreach dir,$(DIR_SRCS),$(wildcard $(dir)/*.c))
OBJS        := $(subst $(DIR_SRC)/,$(DIR_OBJ)/,$(SRCS:.c=.o))
DEPS        := $(OBJS:.o=.d)
TARGET      := $(notdir $(shell pwd)).o
RM          := rm -rf

$(TARGET): $(OBJS) $(LIBS)
	$(CC) -o $@ $^ $(LDFLAGS)

$(DIR_OBJ)/%.o: $(DIR_SRC)/%.c
	@[ -d `dirname $@` ] || mkdir -p `dirname $@`
	$(CC) -o $@ -c $< $(CFLAGS) $(INCLUDE)

all: $(TARGET)

clean:
	$(RM) $(DIR_OBJ)/* $(TARGET)

ifneq ($(MAKECMDGOALS), clean)
-include $(DEPS)
endif

.PHONY: all clean

# end of file {{{1
# vim:ft=make:noet:ts=4:nowrap:fdm=marker
