#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
  char yw[] = {"大风起兮云飞扬，威加海内兮归故乡，安得猛士兮守四方？"};
  char my = '高';
  printf("原文是:%s\n", yw);

  for (int i = 0; i < strlen(yw); i++)
  {
    yw[i] = yw[i] + my;
  }
  printf("密文是:%s\n", yw);
  for (int i = 0; i < strlen(yw); i++)
  {
    yw[i] = yw[i] - my;
  }
  printf("解密后是:%s\n", yw);
  system("pause");
}