# build dynamic library with -fPIC -shared
CXXFLAGS   = -g -fPIC -std=c++23 -fmodules # -O3 # CXXFLAGS for .cpp
CPPFLAGS = -MMD -MP # -I../foo -DNDEBUG
LDFLAGS  = -shared # -L../foo -static
LDLIBS   = # -lfoo
CC      = $(CXX) # link with CXX for .cpp

all: foo libfoo.so

# target name is basename of one of the source files
foo: $(addsuffix .o,$(basename $(wildcard *.c *.cpp *.cppm))) # .cpp
-include *.d
clean: ; rm -fr *.o *.d foo libfoo.so gcm.cache
.PHONY: clean

CPPFLAGS += -Mno-modules
%.o :%.cppm ; $(COMPILE.cpp) $(OUTPUT_OPTION) $<

libfoo.so: foo; cp foo libfoo.so
foo_impl.o: foo.o
bar_impl.o: bar.o
