#include <cstdio>
using namespace std;

const int N = 26214401;
int n;
struct SG2
{
  int r[N], ls[N], rs[N], sumv[N], addv[N], Cnt;

  int Newnode() {return ++Cnt;}
  void Maintain(int o, int l, int r) {sumv[o] = sumv[ls[o]] + sumv[rs[o]] + addv[o] * (r - l + 1);}
  void Insert(int& o, int l, int r, int a, int b)
  {
    if (!o) o = Newnode();
    if (l >= a && r <= b) {++addv[o]; Maintain(o, l, r); return;}
    int m = (l + r) >> 1;
    if (b <= m) Insert(ls[o], l, m, a, b);
    else if (a > m) Insert(rs[o], m + 1, r, a, b);
    else {Insert(ls[o], l, m, a, m); Insert(rs[o], m + 1, r, m + 1, b);}
    Maintain(o, l, r);
  }
  void Query(int& Res, int& o, int l, int r, int a, int b, int delta)
  {
    if (!o) o = Newnode();
    if (l >= a && r <= b) {Res += sumv[o] + delta * (r - l + 1); return;}
    int m = (l + r) >> 1;
    if (b <= m) Query(Res, ls[o], l, m, a, b, delta + addv[o]);
    else if (a > m) Query(Res, rs[o], m + 1, r, a, b, delta + addv[o]);
    else {Query(Res, ls[o], l, m, a, m, delta + addv[o]); Query(Res, rs[o], m + 1, r, m + 1, b, delta + addv[o]);}
  }
} sg2;
struct SG1
{
  int a[131073];

  void Insert(int a, int b, int v)
  {
    int o = 1, l = 1, r = n;
    while (l < r) {
      int m = (l + r) >> 1;
      sg2.Insert(sg2.r[o], 1, n, a, b);
      if (v <= m) {r = m; o <<= 1;}
      else {l = m + 1; o = o << 1 | 1;}
    }
    sg2.Insert(sg2.r[o], 1, n, a, b);
  }
  int Query(int a, int b, int v)
  {
    int l = 1, r = n, o = 1;
    while (l < r) {
      int m = (l + r) >> 1, c = 0;
      sg2.Query(c, sg2.r[o << 1], 1, n, a, b, 0);
      if (c >= v) {r = m; o <<= 1;}
      else {l = m + 1; o = o << 1 | 1; v -= c;}
    }
    return l;
  }
} sg;

int main()
{
  int m, argv, a, b, c;

  scanf("%d%d", &n, &m);
  while (m--) {
    scanf("%d%d%d%d", &argv, &a, &b, &c);
    if (argv == 1) sg.Insert(a, b, n - c + 1);
    else printf("%d\n", n - sg.Query(a, b, c) + 1);
  }

  return 0;
}
