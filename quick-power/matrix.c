#include "matrix.h"
#include <stdio.h>
#include <string.h>
// 构造函数
void Matrix_ctor(Matrix *const me, int N)
{
  me->N = N;
}
// 将矩阵设定为单位矩阵
void unit(Matrix *const me)
{
  printf("%p\n", me);
  clear(me);
  for (int i = 0; i < me->N; ++i)
  {
    printf("%d\n", i);
    me->m[i][i] = 1;
  }
}

// 将矩阵清空为零矩阵
void clear(Matrix *const me)
{
  for (int i = 0; i < me->N; ++i)
  {
    printf("%d\n", i);
    memset(me->m[i], 0, sizeof(int) * me->N);
  }
}

void add(Matrix *const me, Matrix *const other)
{
  int n = me->N;
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      me->m[i][j] += other->m[i][j];
    }
  }
}

void display(Matrix *const me)
{
  int n = me->N;
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      printf("%d ", me->m[i][j]);
    }
    printf("\n");
  }
}