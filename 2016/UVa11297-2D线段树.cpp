#include <iostream>
#include <algorithm>
using namespace std;
#define ls lo, l, m
#define rs ro, m + 1, r

const int N = 1 << 10 | 1;
int fmax[N][N], fmin[N][N], n, xo, sx, tx, sy, ty, v, vmax, vmin;
bool xleaf;

void Modify1D(int o, int l, int r)
{
  if (l == r)
    {
      if (xleaf) {fmax[xo][o] = fmin[xo][o] = v; return;}
      int lo = xo << 1, ro = xo << 1 | 1;
      fmax[xo][o] = max(fmax[lo][o], fmax[ro][o]); fmin[xo][o] = min(fmin[lo][o], fmin[ro][o]);
    }
  else {
    int lo = o << 1, ro = o << 1 | 1, m = (l + r) >> 1;
    if (sy <= m) Modify1D(ls);
    else Modify1D(rs);
    fmax[xo][o] = max(fmax[xo][lo], fmax[xo][ro]); fmin[xo][o] = min(fmin[xo][lo], fmin[xo][ro]);
    }
}
void Modify2D(int o, int l, int r)
{
  if (l == r) {xleaf = true; xo = o; Modify1D(1, 1, n); return;}
  int lo = o << 1, ro = o << 1 | 1, m = (l + r) >> 1;
  if (sx <= m) Modify2D(ls);
  else Modify2D(rs);
  xleaf = false; xo = o; Modify1D(1, 1, n);
}
void Query1D(int o, int l, int r)
{
  if (sy <= l && r <= ty) {vmax = max(vmax, fmax[xo][o]); vmin = min(vmin, fmin[xo][o]); return;}
  int lo = o << 1, ro = o << 1 | 1, m = (l + r) >> 1;
  if (sy <= m) Query1D(ls);
  if (ty >  m) Query1D(rs);
}
void Query2D(int o, int l, int r)
{
  if (sx <= l && r <= tx) {xo = o; Query1D(1, 1, n); return;}
  int lo = o << 1, ro = o << 1 | 1, m = (l + r) >> 1;
  if (sx <= m) Query2D(ls);
  if (tx >  m) Query2D(rs);
}

int main()
{
  int q, i, j;
  char argv;

  ios::sync_with_stdio(false);

  cin >> n;
  for (i = 1; i <= n; ++i)
    for (j = 1; j <= n; ++j) {cin >> v; sx = i; sy = j; Modify2D(1, 1, n);}
  cin >> q;
  while (q--)
    {
      cin >> argv;
      if (argv == 'q') {cin >> sx >> sy >> tx >> ty; vmax = -2147483647; vmin = 2147483647; Query2D(1, 1, n); cout << vmax << ' ' << vmin << endl;}
      else {cin >> sx >> sy >> v; Modify2D(1, 1, n);}
    }

  return 0;
}
