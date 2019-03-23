#include <stdio.h>
#include "tmp.h"

#ifndef ADD
#define ADD
void add(int a, int b)
{
  printf("Added value=%d\n", a + b);
}
#endif