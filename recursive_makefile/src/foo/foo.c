#include <stdio.h>
#include <limits.h>
#include <stdbool.h>
#include "foo.h"

bool add(int a, int b, int *result)
{
    // if (b < 0 && a < INT_MIN - b || b > 0 && a > INT_MAX - b)
    //     return false;

    *result = a + b;
    LOG("%s", "add");

    return true;
}
