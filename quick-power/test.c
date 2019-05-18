#include <stdio.h>

long long int qPow(long long int A, long long int n)
{
  if (n == 0) return 1;
  long long result = 1;
  while (n)
  {
    if (n & 1) // 若幂为奇数
      result *= A;
    A *= A;
    n >>= 1; // 右位移等价于除以2
  }
  return result;
}

int main()
{
  printf("%lld\n", qPow(2, 4));
  printf("%lld\n", qPow(2, 30));
  printf("%lld\n", qPow(2, 31));
  printf("%lld\n", qPow(2, 32));
  return 1;
}