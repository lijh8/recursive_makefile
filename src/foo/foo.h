#ifndef foo_h
#define foo_h

#include <stdbool.h>

#define LOG(fmt, ...) printf("%s:%d: " fmt "\n", __FILE__, __LINE__, ##__VA_ARGS__)

bool add(int a, int b, int *result);

#endif
