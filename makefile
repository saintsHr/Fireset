# ====================================================
# Project
# ====================================================
TARGET := fireset

# ====================================================
# Tools
# ====================================================
CC := gcc
AR := ar
RM := rm -rf

# ====================================================
# Sources
# ====================================================
SRC := $(shell find src -name "*.c")
LIB_SRC := $(filter-out src/main.c,$(SRC))

# ====================================================
# Build dirs
# ====================================================
BUILD_DIR := build/debug
OBJ := $(patsubst src/%.c,$(BUILD_DIR)/%.o,$(SRC))
LIB_OBJ := $(patsubst src/%.c,$(BUILD_DIR)/%.o,$(LIB_SRC))
DEP := $(OBJ:.o=.d)

# ====================================================
# Flags
# ====================================================
DEPFLAGS := -MMD -MP
CFLAGS := -g -O0 -Wall -Wextra -Iinclude $(DEPFLAGS)
LDFLAGS := -lglfw -lGL -lm

# ====================================================
# Outputs
# ====================================================
# BIN := bin/$(TARGET)  <-- removido
LIB := lib/lib$(TARGET).a

# ====================================================
# Phony targets
# ====================================================
.PHONY: all debug release clean doc deb

all: debug
debug: $(LIB)  # só gera a biblioteca agora

release: BUILD_DIR := build/release
release: CFLAGS := -O3 -Wall -Wextra -Iinclude $(DEPFLAGS)
release: $(LIB)

# ====================================================
# Static library (sem main.c)
# ====================================================
$(LIB): $(LIB_OBJ)
	@mkdir -p $(dir $@)
	$(AR) rcs $@ $^

# ====================================================
# Object compilation
# ====================================================
$(BUILD_DIR)/%.o: src/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

# ====================================================
# Dependencies
# ====================================================
-include $(DEP)

# ====================================================
# Documentation
# ====================================================
doc:
	doxygen Doxyfile

# ====================================================
# Debian package
# ====================================================
STAGE      := fireset-dev
PKGNAME    := fireset-dev
VERSION    := 0.1.0
DEBIANDIR  := $(STAGE)/DEBIAN
USRDIR     := $(STAGE)/usr
LIBDIR     := $(USRDIR)/lib
INCDIR     := $(USRDIR)/include/fireset
DOCDIR     := $(USRDIR)/share/doc/$(PKGNAME)
PCDIR      := $(LIBDIR)/pkgconfig
OVERRIDEDIR := $(USRDIR)/share/lintian/overrides

deb:
	@set -e
	$(RM) $(STAGE)
	mkdir -p $(DEBIANDIR) $(LIBDIR) $(INCDIR) $(DOCDIR) $(PCDIR)
	cp $(LIB) $(LIBDIR)/
	cp include/fireset/*.h $(INCDIR)/
	cp debian/control $(DEBIANDIR)/
	cp debian/copyright $(DOCDIR)/
	cp debian/changelog $(DOCDIR)/changelog
	cp LICENSE $(DOCDIR)/
	mkdir -p $(OVERRIDEDIR)
	cp debian/fireset-dev.lintian-overrides $(OVERRIDEDIR)/fireset-dev
	cp debian/fireset.pc $(PCDIR)/
	gzip -n -9 $(DOCDIR)/changelog
	find $(STAGE) -type d -exec chmod 755 {} +
	find $(STAGE) -type f -exec chmod 644 {} +
	dpkg-deb --build --root-owner-group $(STAGE)
	lintian $(STAGE).deb

# ====================================================
# Cleaning
# ====================================================
clean:
	$(RM) build lib docs fireset-dev.deb fireset-dev