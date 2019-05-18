#include "matrix.h" /* Shape class interface */
#include <stdio.h>  /* for printf() */

int main()
{
  Matrix m1;
  Matrix_ctor(&m1, 4);
  unit(&m1);
  display(&m1);
  return 0;
}