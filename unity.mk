MAKEFLAGS		+= --no-builtin-rules

UNITY_VERSION	:= 2.5.2
UNITY_URL		:= https://github.com/ThrowTheSwitch/Unity/archive/refs/tags
UNITY_ZIP		:= v$(UNITY_VERSION).zip

# Directory name
TST_DIR			:= test
TMP_DIR			:= tmp
UNITY_DIR		:= unity
SRC_DIR			:= Unity-$(UNITY_VERSION)

# Directory path
SRC_PATH		:= $(TMP_DIR)/$(SRC_DIR)/src
DST_PATH		:= $(TST_DIR)/$(UNITY_DIR)

# Dependency
UNITY_DEPS		:= \
	$(SRC_PATH)/unity.c \
	$(SRC_PATH)/unity.h \
	$(SRC_PATH)/unity_internals.h \

# Toolchain
CP				:= \cp -f
RM				:= rm -rf
MKDIR			:= mkdir -p
WGET			:= wget -q
UNZIP			:= unzip -q

.PHONY: all
all: copy

.PHONY: copy
copy: $(DST_PATH) $(UNITY_DEPS)
	$(CP) $(UNITY_DEPS) $(DST_PATH)

.PHONY: clean
clean:
	$(RM) $(TMP_DIR) $(UNITY_ZIP)

$(TMP_DIR):
	$(MKDIR) $@

$(TST_DIR):
	$(MKDIR) $@

$(DST_PATH): $(TST_DIR)
	$(MKDIR) $@

$(UNITY_ZIP): $(TMP_DIR)
	$(WGET) $(UNITY_URL)/$(UNITY_ZIP)

$(SRC_PATH)/unity.c: $(UNITY_ZIP)
	$(UNZIP) -d $(TMP_DIR) $<
