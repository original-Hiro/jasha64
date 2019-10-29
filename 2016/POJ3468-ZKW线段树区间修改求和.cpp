#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;
const int N = 1 << 18 | 1;
ll f[N], ff[N];
int M = 1;

inline void PushUP(int o)
{
   f[o] =  f[o << 1] +  f[o << 1 | 1];
  ff[o] = ff[o << 1] + ff[o << 1 | 1];
}
void Update(ll s, ll t, ll v)
{
  ll a = s * v, b = (t + 1) * v;
  f[s += M] += v; f[t += M + 1] -= v;
  ff[s] += a; ff[t] -= b;
  while (s > 1) {PushUP(s >>= 1);}
  while (t > 1) {PushUP(t >>= 1);}
}
ll Query(ll s, ll t)
{
  ll c1 = 0, c2 = 0, Res, XS1, XS2;
  XS2 = s; s += M; XS1 = t + 1; t += M + 1;
  while (t ^ 1)
    {
      if (t & 1) {c1 += f[t ^ 1]; c2 += ff[t ^ 1];}
      t >>= 1;
    }
  Res = c1 * XS1 - c2; c1 = c2 = 0;
  while (s ^ 1)
    {
      if (s & 1) {c1 += f[s ^ 1]; c2 += ff[s ^ 1];}
      s >>= 1;
    }
  Res -= c1 * XS2 - c2;
  return Res;
}

int main()
{
  int n, q, i;
  ll c, a, b;
  char argv;

  ios::sync_with_stdio(false);

  cin >> n >> q;
  while (M <= (n + 1)) M <<= 1;
  for (i = 1; i <= n; ++i) {cin >> c; Update(i, i, c);}
  while (q--)
    {
      cin >> argv >> a >> b;
      if (argv == 'C') {cin >> c; Update(a, b, c);}
      else cout << Query(a, b) << endl;
    }

  return 0;
}
