# build dynamic library with -fPIC -shared
CFLAGS   = -g -fPIC # -O3
CXXFLAGS = -g -fPIC # -O3
CPPFLAGS = -MMD -MP # -I../foo -DNDEBUG
LDFLAGS  = -shared # -L../foo -static
LDLIBS   = # -lfoo

CXXFLAGS += -std=c++23 -fmodules
CPPFLAGS += -Mno-modules

ifneq ($(wildcard *.cpp),)
CC       = $(CXX) # link with CXX for .cpp
endif

libfoo.so: foo; cp foo libfoo.so
foo.o: bar.o      # foo imports bar, so bar.gcm should be created first;
foo_impl.o: foo.o # build its own interface first, foo.gcm is created alongside foo.o;
bar_impl.o: bar.o # build its own interface first, bar.gcm is created alongside bar.o;

# target name is basename of one of the source files
foo: $(addsuffix .o,$(basename $(wildcard *.c *.cpp *.cppm)))
-include *.d
clean: ; rm -fr *.o *.d foo libfoo.so gcm.cache
.PHONY: clean

%.o: %.cppm; $(COMPILE.cpp) $(OUTPUT_OPTION) $<
