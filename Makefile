MAKEFLAGS   += --no-builtin-rules
CC          := gcc
CFLAGS      := -Wall -Wextra -MMD -MP
LDFLAGS     :=
LIBS        :=
INCLUDE     := -Isrc
DIR_SRC     := src
DIR_OBJ     := obj
SRCS        := $(wildcard $(DIR_SRC)/*.c)
OBJS        := $(addprefix $(DIR_OBJ)/, $(notdir $(SRCS:.c=.o)))
DEPS        := $(OBJS:.o=.d)
TARGET      := $(notdir $(shell pwd)).o

$(TARGET): $(OBJS) $(LIBS)
	$(CC) -o $@ $^ $(LDFLAGS)

$(DIR_OBJ)/%.o: $(DIR_SRC)/%.c
	@[ -d $(DIR_OBJ) ] || mkdir -p $(DIR_OBJ)
	$(CC) -o $@ -c $< $(CFLAGS) $(INCLUDE)

all: $(TARGET)

clean:
	$(RM) $(OBJS) $(DEPS) $(TARGET)

ifneq ($(MAKECMDGOALS), clean)
-include $(DEPS)
endif

.PHONY: all clean

# end of file {{{1
# vim:ft=make:noet:ts=4:nowrap:fdm=marker
