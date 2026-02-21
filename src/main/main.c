#include <stdio.h>
#include <limits.h>
#include <stdbool.h>
#include "foo.h"

int main()
{
    int sum;
    int a = INT_MAX;
    int b = INT_MAX;
    bool ret = add(a, b, &sum);
    LOG("%s", "main");
}
