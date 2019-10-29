#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;

const int N = 50007;
int a[N], p[N];
struct Q
{
  int l, r, q;
  friend bool operator < (const Q& a, const Q& b)
  {
    if (p[a.l] == p[b.l]) return a.r < b.r;
    return a.l < b.l;
  }
} q[N];
long long cache, ax[N], ay[N], s[N];

inline long long sqr(long long x) {return x * x;}
inline void Update(int p, int delta)
{
  cache -= sqr(s[a[p]]);
  s[a[p]] += delta;
  cache += sqr(s[a[p]]);
}
inline long long gcd(long long a, long long b)
{
  if (a < b) swap(a, b);
  if (!b) return a;
  long long c = a % b;
  while (c) {a = b; b = c; c = a % b;}
  return b;
}

int main()
{
  int n, m;

  cin >> n >> m;
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  for (int i = 0; i < m; i++) {scanf("%d%d", &q[i].l, &q[i].r); q[i].q = i;}

  const int SIZE = sqrt(n);
  for (int i = 1; i <= n; i++) p[i] = (i - 1) / SIZE + 1;
  sort(q, q + m);
  for (int i = 0, l = 1, r = 0; i < m; i++) {
    const int &id = q[i].q, &R = q[i].r, &L = q[i].l;
    for (; r < R; r++) Update(r + 1, 1);
    for (; r > R; r--) Update(r, -1);
    for (; l < L; l++) Update(l, -1);
    for (; l > L; l--) Update(l - 1, 1);
    if (L == R) {ax[id] = 0; ay[id] = 1; continue;}
    ax[id] = cache - (R - L + 1); ay[id] = (long long)(R - L) * (R - L + 1);
    long long c = gcd(ax[id], ay[id]); ax[id] /= c; ay[id] /= c;
  }

  for (int i = 0; i < m; i++) printf("%lld/%lld\n", ax[i], ay[i]); 

  return 0;
}
