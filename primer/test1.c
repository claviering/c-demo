#include <stdio.h>
#include <math.h>

// 遍历法
unsigned char is_primer1(int num)
{
  if (num == 2) return 1;
  if (!num || num == 1 || !(num%2)) return 0;
  for (int i = 2; i < num; i++)
  {
    if (!(num % i))
      return 0;
  }
  return 1;
}

// 改进的遍历法
unsigned char is_primer2(int num)
{
  if (num == 2) return 1;
  if (!num || num == 1 || !(num%2)) return 0;
  const int upper = sqrt(num);
  for (int i = 2; i <= upper; i++)
  {
    if (!(num % i)) {
      return 0;
    }
  }
  return 1;
}

// 筛选法, 建表
unsigned char is_primer3(int num)
{
  unsigned char table[num+1]; // 初始化 num + 1个空间
  for (int i = 0; i <= num; i++)
  {
    table[i] = is_primer2(i);
  }
  return table[num];
}

// 筛选法, 建表, 只保存奇数, 空间减少一半
unsigned char is_primer4(int num)
{
  if (num == 2) return 1;
  if (!num || num == 1 || !(num%2)) return 0;
  unsigned char table[num/2+1]; // 初始化 num + 1个空间
  for (int i = 0; i <= num; i++)
  {
    if(!(i%2)) continue;
    table[i/2] = is_primer2(i);
  }
  return table[num/2];
}

int main()
{
  for (int a = 0; a <= 20; a++) {
    if (is_primer4(a)) printf("%d\n", a);
  }
  printf("\n");
  return 1;
}