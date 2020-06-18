/*
 * 01 背包问题，原始版本，空间优化
 * 由上述状态转移方程可知，dp[i][j]的值只与dp[i-1][0,...,j-1]有关，
 * 所以我们可以采用动态规划常用的方法（滚动数组）对空间进行优化（即去掉dp的第一维）。
 * 需要注意的是，为了防止上一层循环的dp[0,...,j-1]被覆盖，循环的时候 j 只能逆向枚举
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

int main()
{
  cin >> n >> m;
  for (int i = 1; i <= n; i++)
    cin >> w[i] >> v[i];
  for (int i = 1; i <= n; i++)
  {
    for (int j = m; j >= w[i]; j--)
    {
      f[j] = max(f[j], f[j - w[i]] + v[i]);
    }
  }
  cout << f[m];
  return 0;
}
