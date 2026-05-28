# build dynamic library with -fPIC -shared
CXXFLAGS   = -g -std=c++23 -fmodules # -O3 -fPIC # CXXFLAGS for .cpp
CPPFLAGS = -MMD -MP -I../foo # -DNDEBUG
LDFLAGS  = -L../foo # -shared -static
LDLIBS   = -lfoo
CC      = $(CXX) # link with CXX for .cpp

CPP_OBJECTS = $(patsubst %.cpp,%.o,$(wildcard *.cpp))

# target name is basename of one of the source files
main: $(CPP_OBJECTS) # .cpp
-include *.d
clean: ; rm -fr *.o *.d main
.PHONY: clean

CXXFLAGS += '-fmodule-mapper=|@g++-mapper-server -r../foo/gcm.cache'

%.c++-module: ;
