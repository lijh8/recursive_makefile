module;
#include <iostream>
#include "bar.h"

export module foo;

export void foo()
{
    std::cout << "foo" << "\n";
    bar();
}
