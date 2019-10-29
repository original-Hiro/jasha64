#include <iostream>
#include <algorithm>
using namespace std;

const int N = 100007, MAXN = 2000007;
int n, m, tot;
int a[N], a_[N], c[MAXN], t[N], r[MAXN], ls[MAXN], rs[MAXN];

inline void Init_Hash()
{
  copy(a + 1, a + n + 1, a_ + 1);
  sort(a_ + 1, a_ + n + 1);
  m = unique(a_ + 1, a_ + n + 1) - a_ - 1;
}
int Build(int l, int r)
{
  int o = ++tot;

  c[o] = 0;
  if (l < r) {
    int m = (l + r) >> 1;
    ls[o] = Build(l, m);
    rs[o] = Build(m + 1, r);
  }

  return o;
}
inline int Hash(int x) {return lower_bound(a_ + 1, a_ + m + 1, x) - a_;}
int Update(int o, int p, int v)
{
  int Newnode = ++tot, Ret = Newnode;

  c[Newnode] = c[o] + v;
  int l = 1, r = m;
  while (l < r) {
    int mid = (l + r) >> 1;
    if (p <= mid) {ls[Newnode] = ++tot; rs[Newnode] = rs[o]; Newnode = ls[Newnode]; o = ls[o]; r = mid;}
    else {ls[Newnode] = ls[o]; rs[Newnode] = ++tot; Newnode = rs[Newnode]; o = rs[o]; l = mid + 1;}
    c[Newnode] = c[o] + v;
  }

  return Ret;
}
int Query(int lo, int ro, int v)
{
  int l = 1, r = m;

  while (l < r) {
    int mid = (l + r) >> 1;
    if (c[ls[lo]] - c[ls[ro]] >= v) {r = mid; lo = ls[lo]; ro = ls[ro];}
    else {l = mid + 1; v -= c[ls[lo]] - c[ls[ro]]; lo = rs[lo]; ro = rs[ro];}
  }

  return l;
}

int main()
{
  ios::sync_with_stdio(false);
  int q;

  while (cin >> n >> q) {
    tot = 0;
    for (int i = 1; i <= n; i++) cin >> a[i];

    Init_Hash();
    t[n + 1] = Build(1, m);
    for (int i = n; i > 0; i--) t[i] = Update(t[i + 1], Hash(a[i]), 1);

    while (q--) {
      int l, r, v;
      cin >> l >> r >> v;
      cout << a_[Query(t[l], t[r + 1], v)] << endl;
    }
  }

  return 0;
}
