#
# Makefile to build openperf
#

OP_ROOT := $(realpath ../../)
OP_TARGET := openperf
include $(OP_ROOT)/mk/bootstrap.mk

USE_CRASH_HANDLER := 1

BUILD_DIR := $(OP_BUILD_ROOT)/obj
TARGET_DIR := $(OP_BUILD_ROOT)/bin
TARGET_BIN := $(TARGET_DIR)/$(OP_TARGET)

all: $(OP_TARGET)

SOURCES := main.c

BUILD_DEPS := \
	cpu \
	block \
	memory \
	packet_analyzer \
	packet_capture \
	packet_generator \
	socket_server \
	timesync \

OP_PACKETIO_DRIVER ?= dpdk

ifeq ($(USE_CRASH_HANDLER), 1)
BUILD_DEPS += breakpad
OP_CPPFLAGS += -DUSE_CRASH_HANDLER
SOURCES += crash_handler.cpp
$(BUILD_DIR)/crash_handler.o: OP_CPPFLAGS += -Wno-variadic-macros
endif

TARGET_SYM_DIR := $(OP_BUILD_ROOT)/sym/$(OP_TARGET)
TARGET_SYM := $(TARGET_SYM_DIR)/$(OP_TARGET).sym

OBJECTS := $(call op_generate_objects,$(SOURCES),$(BUILD_DIR))

# Pull in dependencies
-include $(OBJECTS:.o=.d)
$(call op_include_dependencies,$(BUILD_DEPS))

OP_CONFIG_OPTS += --enable-static=yes --enable-shared=no
OP_CPPFLAGS += $(addprefix -I,$(sort $(OP_INC_DIRS)))
OP_LDFLAGS += $(addprefix -L,$(sort $(OP_LIB_DIRS)))
OP_LDOPTS += -static-libstdc++ -static-libgcc

# Build rules
$(eval $(call op_generate_build_rules,$(SOURCES),,BUILD_DIR,BUILD_DEPS))

$(TARGET_BIN): $(OBJECTS) $(BUILD_DEPS)
	$(call op_link_binary,$@,$(OBJECTS))
	sudo -n /sbin/setcap CAP_IPC_LOCK,CAP_NET_ADMIN,CAP_NET_RAW=ep $@

$(TARGET_SYM): $(TARGET_BIN)
ifeq ($(USE_CRASH_HANDLER), 1)
	mkdir -p $(TARGET_SYM_DIR)
	# Delete previous symbols
	find $(TARGET_SYM_DIR) -mindepth 2 -name "*.sym" -delete
	find $(TARGET_SYM_DIR) -empty -type d -delete
	$(BREAKPAD_DUMPSYMS) $(TARGET_BIN) > $@
	$(call op_copy_breakpad_sym_to_uuid_dir,$@,$(TARGET_SYM_DIR))
endif

.PHONY: $(OP_TARGET)
$(OP_TARGET): $(TARGET_BIN) $(TARGET_SYM)

.PHONY: clean
clean:
	@rm -rf $(OP_BUILD_ROOT)
