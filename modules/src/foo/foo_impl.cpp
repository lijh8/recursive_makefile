module;
#include <iostream>

module foo;
import bar;

void foo()
{
    std::cout << __func__ << "\n";
    bar();
}
