#ifndef MATRIX_H
#define MATRIX_H

#include <stdint.h>

// matrix 的属性
typedef struct
{
  int N;   // 矩阵维数
  int **m; // 存储矩阵的二维数组
} Matrix;

// Matrix 的操作函数，接口函数
void Matrix_ctor(Matrix *const me, int N);
void unit(Matrix *const me);                     // 初始化为单元矩阵
void clear(Matrix *const me);                    // 删除矩阵
void add(Matrix *const me, Matrix *const other); // 矩阵相加
void display(Matrix *const me);                  // 打印矩阵
// int16_t Matrix_getX(Matrix const *const me);
// int16_t Matrix_getY(Matrix const *const me);

#endif /* MATRIX_H */