#include <iostream>
#include "bar.h"

import foo;

int main()
{
    foo();
    std::cout << "main\n";
    bar();
}
