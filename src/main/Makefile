# sub-makefile
# build dynamic library with -fPIC -shared
# fully static link with archive -static
CFLAGS   = -Wall -Wextra # -g -O3 -std=c11 -fPIC
CXXFLAGS = -Wall -Wextra # -g -O3 -std=c++11 -fPIC
CPPFLAGS = -MMD -MP -I../foo # -DNDEBUG
LDFLAGS  = -L../foo # -static -shared
LDLIBS   = -lfoo
LDFLAGS  += -Wl,-rpath,'$$ORIGIN/../foo:$$ORIGIN/../lib'

# make BUILD_TYPE=SANITIZE
BUILD_TYPE ?= RELEASE
ifeq ($(BUILD_TYPE),SANITIZE)
SANITIZE = -fsanitize=address,undefined
CFLAGS   += -g $(SANITIZE)
CXXFLAGS += -g $(SANITIZE)
LDFLAGS  += $(SANITIZE)
else ifeq ($(BUILD_TYPE),DEBUG)
CFLAGS   += -g
CXXFLAGS += -g
else ifeq ($(BUILD_TYPE),RELEASE)
CFLAGS   += -O3
CXXFLAGS += -O3
else
$(error Unknown BUILD_TYPE: $(BUILD_TYPE). Use SANITIZE, DEBUG, or RELEASE)
endif

# make LINK_TYPE=DYNAMIC
LINK_TYPE ?= DYNAMIC
ifeq ($(LINK_TYPE),STATIC)
LDFLAGS   += -static
else ifneq ($(LINK_TYPE),DYNAMIC)
$(error Unknown LINK_TYPE: $(LINK_TYPE). Use DYNAMIC or STATIC)
endif

ifneq ($(wildcard *.cpp),)
CC        = $(CXX) # link with CXX for .cpp
endif

target    = main

# target name is basename of one of the source files
$(target): $(addsuffix .o,$(basename $(wildcard *.c *.cpp)))

-include *.d
clean: ; rm -f *.o *.d $(target)
.PHONY: clean
