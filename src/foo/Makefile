# sub-makefile
# build dynamic library with -fPIC -shared
# fully static link with archive -static
CFLAGS   = -Wall -Wextra -fPIC # -g -O3 -std=c11
CXXFLAGS = -Wall -Wextra -fPIC # -g -O3 -std=c++11
CPPFLAGS = -MMD -MP # -I../foo -DNDEBUG
LDFLAGS  = -shared # -L../foo -static
LDLIBS   = # -lfoo
ARFLAGS  = rsD

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

ifneq ($(wildcard *.cpp),)
CC       = $(CXX) # link with CXX for .cpp
endif

target   = foo
semver   = 1.2.3
soname   = lib$(target).so.$(firstword $(subst ., ,$(semver)))
LDFLAGS  += -Wl,-soname,$(soname)

all: lib$(target).so $(soname) lib$(target).so.$(semver) lib$(target).a

lib$(target).so $(soname) lib$(target).so.$(semver): $(target)
	cp $(target) lib$(target).so.$(semver)
	ln -fs lib$(target).so.$(semver) $(soname)
	ln -fs $(soname) lib$(target).so

# target name is basename of one of the source files
$(target): $(addsuffix .o,$(basename $(wildcard *.c *.cpp)))

# archive
(%): % ;
%.a:
	rm -f $@ # remove and re-create archive in case object files removed or added
	$(AR) $(ARFLAGS) $@ $^
lib$(target).a: lib$(target).a($(addsuffix .o,$(basename $(wildcard *.c *.cpp))))
.SECONDARY: $(addsuffix .o,$(basename $(wildcard *.c *.cpp)))

-include *.d
clean: ; rm -f *.o *.d $(target) lib*.so* lib*.a
.PHONY: all clean
