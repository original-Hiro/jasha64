#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;
const int N = 1 << 18 | 1;
int n;
ll a[N], b[N], c[N];

inline int Lowbit(ll x) {return x & -x;}
inline void Add(ll* f, ll x, ll v) {while (x <= n) {f[x] += v; x += Lowbit(x);}}
inline ll Sum(ll* f, ll x)
{
  ll r = 0;
  while (x) {r += f[x]; x -= Lowbit(x);}
  return r;
}
void Update(ll l, ll r, ll v)
{
  Add(b, l, v); Add(c, l, l * v);
  Add(b, r + 1, -v); Add(c, r + 1, (r + 1) * (-v));
}
ll Query(ll l, ll r)
{
  ll Res = 0;
  Res += (r + 1) * Sum(b, r); Res -= Sum(c, r);
  Res -= l * Sum(b, l - 1); Res += Sum(c, l - 1);
  return Res;
}

int main()
{
  int q, i;
  ll l, r, v;
  char argv;

  ios::sync_with_stdio(false);

  cin >> n >> q;
  for (i = 1; i <= n; ++i) {cin >> v; Update(i, i, v);}
  while (q--)
    {
      cin >> argv >> l >> r;
      if (argv == 'Q') cout << Query(l, r) << endl;
      else {cin >> v; Update(l, r, v);}
    }

  return 0;
}
