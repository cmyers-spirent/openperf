#
# Makefile component for breakpad
#

BREAKPAD_REQ_VARS := \
	OP_ROOT \
	OP_BUILD_ROOT
$(call op_check_vars,$(BREAKPAD_REQ_VARS))


BREAKPAD_SRC_DIR := $(OP_ROOT)/deps/breakpad
BREAKPAD_OBJ_DIR := $(OP_BUILD_ROOT)/obj/breakpad
BREAKPAD_BLD_DIR := $(OP_BUILD_ROOT)/breakpad
BREAKPAD_INC_DIR := $(BREAKPAD_BLD_DIR)/include/breakpad
BREAKPAD_LIB_DIR := $(BREAKPAD_BLD_DIR)/lib
BREAKPAD_BIN_DIR := $(BREAKPAD_BLD_DIR)/bin

LSS_SRC_DIR := $(OP_ROOT)/deps/google-linux-syscall-support

BREAKPAD_DUMPSYMS := $(BREAKPAD_BIN_DIR)/dump_syms

# Function to copy breakpad syms to UUID directory
# $(call op_copy_breakpad_sym_to_uuid_dir,$(SYM_FILE),$(SYN_DIR))
define op_copy_breakpad_sym_to_uuid_dir
	@TARGET_UUID=`head -1 $1  | awk '{ print $$4 }'` && \
    TARGET_UUID_DIR=$2/$${TARGET_UUID} && \
	mkdir -p $${TARGET_UUID_DIR} && \
	cp -f $1 $${TARGET_UUID_DIR}/ && \
	echo "Coppied breakpad symbols to $${TARGET_UUID_DIR}"
endef


# Update global variables
OP_INC_DIRS += $(BREAKPAD_INC_DIR)
OP_LIB_DIRS += $(BREAKPAD_LIB_DIR)
OP_LDLIBS += -lbreakpad_client

BREAKPAD_CONFIG_OPTS := 

###
# Build rules
###
$(BREAKPAD_SRC_DIR)/configure:
	cd $(BREAKPAD_SRC_DIR) && autoconf

# Breakpad is normally built with google depot-tools so it doesn't use
# git submodules.  To avoid using depot-tools, the linux-syscall-support
# repo is added to openperf repo as a submodule and symlinked into
# breakpad
$(BREAKPAD_SRC_DIR)/src/third_party/lss:
	ln -sf $(LSS_SRC_DIR) $@

$(BREAKPAD_OBJ_DIR)/Makefile: $(BREAKPAD_SRC_DIR)/configure $(BREAKPAD_SRC_DIR)/src/third_party/lss
	@mkdir -p $(BREAKPAD_OBJ_DIR)
	cd $(BREAKPAD_OBJ_DIR) && $(BREAKPAD_SRC_DIR)/configure $(OP_CONFIG_OPTS) \
		$(BREAKPAD_CONFIG_OPTS) --prefix="$(BREAKPAD_BLD_DIR)" \
		CC="$(CC)" CFLAGS="$(OP_COPTS)" \
		CXX="$(CXX)" CXXFLAGS="$(OP_CXXOPTS)"

$(BREAKPAD_LIB_DIR)/libbreakpad.a: $(BREAKPAD_OBJ_DIR)/Makefile
	cd $(BREAKPAD_OBJ_DIR) && $(MAKE) install

.PHONY: breakpad
breakpad: $(BREAKPAD_LIB_DIR)/libbreakpad.a

.PHONY: breakpad_clean
breakpad_clean:
	@rm -rf $(BREAKPAD_OBJ_DIR) $(BREAKPAD_BLD_DIR)
	@rm -f $(BREAKPAD_SRC_DIR)/src/third_party/lss
clean: breakpad_clean

