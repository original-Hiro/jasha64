#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;

int M, n, f[1 << 20 | 1];

inline void PushUP(int i) {f[i] = max(f[i << 1], f[i << 1 | 1]);}
void Init()
{
  int i;

  cin >> n;
  M = 1;
  while (M <= n + 1) M <<= 1;

  for (i = M + 1; i <= M + n; ++i) scanf("%d", &f[i]);
  for (i = M - 1; i > 0; --i) PushUP(i);
}
void Query(int a, int b)
{
  int Ans = -2147483647;

  a = a + M - 1; b = b + M + 1;
  while (a ^ b ^ 1)
    {
      if (~a & 1) Ans = max(Ans, f[a ^ 1]);
      if (b & 1) Ans = max(Ans, f[b ^ 1]);
      a >>= 1; b >>= 1;
    }

  printf("%d\n", Ans);
}

int main()
{
  int i, q, a, b;

  Init();

  cin >> q;
  while (q--)
    {
      scanf("%d%d", &a, &b);
      if (a > b) swap(a, b);
      Query(a, b);
    }

  return 0;
}
