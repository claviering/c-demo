#include <stdio.h>
#include "tmp.h"

int main()
{
  int a = 10;
  int b = 10;
  add(a, b);
  function_two();
  function_two();
  printf("%d\n", a);
  return 1;
}