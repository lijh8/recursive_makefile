# sub-makefile
# build dynamic library with -fPIC -shared
# fully static link with archive -static
CFLAGS   = -Wall -Wextra -fPIC # -g -O3 -std=c11
CXXFLAGS = -Wall -Wextra -fPIC # -g -O3 -std=c++11
CPPFLAGS = -MMD -MP # -I../foo -DNDEBUG
LDFLAGS  = -shared # -L../foo -static
LDLIBS   = # -lfoo
ARFLAGS  = rv

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

ext = .c
ifneq ($(wildcard *.cpp),)
ext = .cpp
CC  = $(CXX)
endif

target  = foo
semver  = 1.2.3
soname  = lib$(target).so.$(firstword $(subst ., ,$(semver)))
LDFLAGS += -Wl,-soname,$(soname)

all: $(target) lib$(target).so $(soname) lib$(target).so.$(semver) lib$(target).a

# target name is basename of one of the source files
$(target): $(patsubst %$(ext),%.o,$(wildcard *$(ext)))

lib$(target).so $(soname) lib$(target).so.$(semver): $(target)
	cp $(target) lib$(target).so.$(semver)
	ln -fs lib$(target).so.$(semver) $(soname)
	ln -fs $(soname) lib$(target).so

# archive
(%): % ;
%.a:
	rm -f $@
	$(AR) $(ARFLAGS) $@ $^
lib$(target).a: lib$(target).a($(patsubst %$(ext),%.o,$(wildcard *$(ext))))
.SECONDARY: $(patsubst %$(ext),%.o,$(wildcard *$(ext)))

-include *.d
clean: ; rm -f *.o *.d $(target) lib*.so* lib*.a
.PHONY: all clean
