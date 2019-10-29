#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int M, n, f[1 << 20 | 1];

inline void PushUP(int i) {f[i] = f[i << 1] + f[i << 1 | 1];}
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
  int Ans = 0;

  a = a + M - 1; b = b + M + 1;
  while (a ^ b ^ 1)
    {
      if (~a & 1) Ans += f[a ^ 1];
      if ( b & 1) Ans += f[b ^ 1];
      a >>= 1; b >>= 1;
    }

  printf("%d\n", Ans);
}
void Update(int n, int v)
{
  f[n += M] += v; n >>= 1;
  while (n) {PushUP(n); n >>= 1;}
}

int main()
{
  int T, i, q, a, b;
  char argv[7];

  cin >> T;
  for (i = 1; i <= T; ++i)
    {
      Init();

      printf("Case %d:\n", i);

      while (true)
	{
	  scanf(" %s", argv);
	  if (argv[0] == 'E') break;
	  scanf("%d%d", &a, &b);
	  if (argv[0] == 'A') Update(a, b);
	  else if (argv[0] == 'S') Update(a, -b);
	  else Query(a, b);
	}
    }

  return 0;
}
