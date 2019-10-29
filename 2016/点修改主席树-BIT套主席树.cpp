#include <iostream>
#include <algorithm>
using namespace std;

const int N = 50007, MAXN = 2000007;
int n;
struct _PSG {
  const int MAXN = 2000007;
  int a[N], c[MAXN], r[MAXN], ls[MAXN], rs[MAXN], Top;

  void Init() {a[0] = Build(1, n);}
  int Build(int l, int r)
  {
    int o = ++Top;
    if (l < r) {
      int m = (l + r) >> 1;
      ls[o] = Build(l, m);
      rs[o] = Build(m + 1, r);
    }
    return o;
  }
  void Update(int p, int v)
  {
    int& o = a[p];
    if (!o) o = ++Top;
    int l = 1, r = n;
    while (l < r) {
      int mid = (l + r) >> 1;
      if (v <= mid) {o = ls[o]; r = mid;}
      else {o = rs[o]; l = mid + 1;}
      ++c[o];
    }
  }
  int Query(int* c1, int* c2, int t1, int t2, int v)
  {
    int l = 1, r = n;
    while (l < r) {
      int mid = (l + r) >> 1, sum = 0;
      for (int i = 0; i < t1; i++) sum -= c[ls[c1[i]]];
      for (int i = 0; i < t2; i++) sum += c[ls[c2[i]]];
      if (sum >= v) {
	r = mid;
	for (int i = 0; i < t1; i++) c1[i] = ls[c1[i]];
	for (int i = 0; i < t2; i++) c2[i] = ls[c2[i]];
      }
      else {
	l = mid + 1; v -= sum;
	for (int i = 0; i < t1; i++) c1[i] = rs[c1[i]];
	for (int i = 0; i < t2; i++) c2[i] = rs[c2[i]];
      }
    }
    return l;
  }
} PSG;
inline int Lowbit(int x) {return x & -x;}
struct _BIT {
  void Add(int x, int v) {for (; x <= n; x += Lowbit(x)) PSG.Update(x, v);}
  int Query(int l, int r, int v)
  {
    int c1[27], t1, c2[27], t2;
    for (int i = l - 1; i > 0; i -= Lowbit(i)) c1[t1++] = PSG.a[i];
    for (int i = r; i > 0; i -= Lowbit(i)) c2[t2++] = PSG.a[i];
    return PSG.Query(c1, c2, t1, t2, v);
  }
} BIT;

int main()
{
  ios::sync_with_stdio(false);
  int q;

  cin >> n >> q;
  PSG.Init();

  while (q--) {
    int s, l, r, v;
    cin >> s;
    if (s == 1) {cin >> l >> v; BIT.Add(l, v);}
    else {cin >> l >> r >> v; cout << PSG.Query(l, r, v) << endl;}
  }

  return 0;
}
