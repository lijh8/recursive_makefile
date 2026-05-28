module;
#include <iostream>

module bar;

void bar()
{
    std::cout << __func__ << "\n";
}
