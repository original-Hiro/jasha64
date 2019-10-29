#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
#define ls lo, l, m
#define rs ro, m + 1, r

typedef long long ll;
int L, R;
int a[500007];

struct Struct {ll r, p, s, sum; int f, b, pb, sf;} f[1 << 20 | 1];
inline void Make(Struct& a, Struct b, Struct c)
{
  a.sum = b.sum + c.sum;
  a.r = b.s + c.p;  a.f = b.sf; a.b = c.pb;
  if (b.r > a.r || ((b.f < a.f || (b.f == a.f && b.b < a.b)) && b.r == a.r)) {a.r = b.r; a.f = b.f; a.b = b.b;}
  if (c.r > a.r || ((c.f < a.f || (c.f == a.f && c.b < a.b)) && c.r == a.r)) {a.r = c.r; a.f = c.f; a.b = c.b;}
  a.p = b.sum + c.p; a.pb = c.pb;
  if (b.p > a.p || (b.pb < a.pb && b.p == a.p)) {a.p = b.p; a.pb = b.pb;}
  a.s = b.s + c.sum; a.sf = b.sf;
  if (c.s > a.s || (c.sf < a.sf && c.s == a.s)) {a.s = c.s; a.sf = c.sf;}
}
void Init(int o, int l, int r)
{
  if (l == r) {f[o].sum = f[o].r = f[o].p = f[o].s = a[f[o].f = f[o].b = f[o].pb = f[o].sf = l]; return;}
  int lo = o << 1, ro = o << 1 | 1, m = (l + r) >> 1;
  Init(ls); Init(rs);
  Make(f[o], f[lo], f[ro]);
}
Struct Query(int o, int l, int r)
{
  if (L <= l && r <= R) return f[o];
  int lo = o << 1, ro = o << 1 | 1, m = (l + r) >> 1;
  if (R <= m) return Query(ls);
  if (L >  m) return Query(rs);
  Struct c;
  Make(c, Query(ls), Query(rs));
  return c;
}

int main()
{
  int n, q, i, T = 0;
  Struct c;

  ios::sync_with_stdio(false);

  while (cin >> n >> q)
    {
      cout << "Case " << ++T << ':' << endl;
      
      for (i = 1; i <= n; ++i) cin >> a[i];
      Init(1, 1, n);
      while (q--)
	{
	  cin >> L >> R;
	  c = Query(1, 1, n);
	  cout << c.f << ' ' << c.b << endl;
	}
    }

  return 0;
}
