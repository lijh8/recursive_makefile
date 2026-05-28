# build dynamic library with -fPIC -shared
CXXFLAGS   = -g -fPIC -std=c++23 -fmodules # -O3 # CXXFLAGS for .cpp
CPPFLAGS = -MMD -MP # -I../foo -DNDEBUG
LDFLAGS  = -shared # -L../foo -static
LDLIBS   = # -lfoo
CC      = $(CXX) # link with CXX for .cpp

CPP_OBJECTS = $(patsubst %.cpp,%.o,$(wildcard *.cpp))
CPPM_OBJECTS = $(patsubst %.cppm,%.o,$(wildcard *.cppm))

all: foo libfoo.so
libfoo.so: foo; cp foo libfoo.so

# target name is basename of one of the source files
foo: $(CPP_OBJECTS) $(CPPM_OBJECTS) # .cpp
-include *.d
clean: ; rm -fr *.o *.d foo libfoo.so gcm.cache
.PHONY: clean

%.o :%.cppm ; $(COMPILE.cpp) $(OUTPUT_OPTION) $<
