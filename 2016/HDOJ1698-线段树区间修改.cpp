#include <iostream>
#include <algorithm>
using namespace std;
#define lo o << 1
#define ro o << 1 | 1
#define ls o << 1, l, (l + r) >> 1
#define rs o << 1 | 1, ((l + r) >> 1) + 1, r
#define m (l + r) >> 1

const int N = 100007;
int f[1 << 18 | 1], setv[1 << 18 | 1], Left, Right, Value, Res;

inline void Pushdown(int o)
{
  if (setv[o]) {setv[lo] = setv[ro] = setv[o]; setv[o] = 0;}
}
inline void Maintain(int o, int l, int r)
{
  if (setv[o]) f[o] = setv[o] * (r - l + 1);
  else f[o] = f[lo] + f[ro];
}
void Update(int o, int l, int r)
{
  if (Left <= l && r <= Right) setv[o] = Value;
  else {
    Pushdown(o);
    if (Left <= m) Update(ls);
    else Maintain(ls);
    if (Right > m) Update(rs);
    else Maintain(rs);
  }
  Maintain(o, l, r);
}
void Query(int o, int l, int r)
{
  if (setv[o]) {Res += setv[o] * (min(r, Right) - max(l, Left) + 1); return;}
  if (Left <= l && r <= Right) {Res += f[o]; return;}
  if (Left <= m) Query(ls); if (Right > m) Query(rs);
}

int main()
{
  int T, t, n, q, i;
  char argv;

  ios::sync_with_stdio(false);

  cin >> T;
  for (i = 1; i <= T; ++i)
    {
      cin >> n >> q;
      Left = 1; Right = n; Value = 1; Update(1, 1, n);
      while (q--) {cin >> Left >> Right >> Value; Update(1, 1, n);}
      Res = 0; Left = 1; Right = n; Query(1, 1, n);
      cout << "Case " << i << ": The total value of the hook is " << Res << '.' << endl;
    }

  return 0;
}
