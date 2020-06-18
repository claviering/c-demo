/*
 * 01 背包问题，原始版本，空间优化, 优化代码结构
 * n 个物品
 * 总重量是 m
 */

#include <iostream>
#include <algorithm>
using namespace std;

const int N = 3402 + 1;
const int M = 12880 + 1;
int n, m;
int f[M];
int v[N], w[N];

void ZeroOnePack(int cost, int weight)
{
  for (int j = m; j >= cost; j--)
  {
    f[j] = max(f[j], f[j - cost] + weight);
  }
}

int main()
{
  cin >> n >> m;
  for (int i = 1; i <= n; i++)
    cin >> w[i] >> v[i];
  for (int i = 1; i <= n; i++)
  {
    ZeroOnePack(w[i], v[i]);
  }
  cout << f[m];
  return 0;
}
