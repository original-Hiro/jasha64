#include <iostream>
#include <algorithm>
using namespace std;
#define lo o << 1
#define ro o << 1 | 1
#define ls o << 1, l, (l + r) >> 1
#define rs o << 1 | 1, ((l + r) >> 1) + 1, r
#define m (l + r) >> 1

typedef long long ll;
ll f[1 << 18 | 1], addv[1 << 18 | 1], Left, Right, Value, Res;

inline void Maintain(ll o, ll l, ll r)
{
  f[o] = 0;
  if (r > l) f[o] = f[lo] + f[ro];
  f[o] += addv[o] * (r - l + 1);
}
void Update(ll o, ll l, ll r)
{
  if (Left <= l && r <= Right) addv[o] += Value;
  else {if (Left <= m) Update(ls); if (Right > m) Update(rs);}
  Maintain(o, l, r);
}
void Query(ll o, ll l, ll r, ll delta)
{
  if (Left <= l && r <= Right) {Res += f[o] + delta * (r - l + 1); return;}
  if (Left <= m) Query(ls, delta + addv[o]);
  if (Right > m) Query(rs, delta + addv[o]);
}

int main()
{
  int n, q, i;
  char argv;

  ios::sync_with_stdio(false);

  cin >> n >> q;
  for (i = 1; i <= n; ++i) {cin >> Value; Left = Right = i; Update(1, 1, n);}
  while (q--)
    {
      cin >> argv >> Left >> Right;
      if (argv == 'C') {cin >> Value; Update(1, 1, n);}
      else {Res = 0; Query(1, 1, n, 0); cout << Res << endl;}
    }

  return 0;
}
