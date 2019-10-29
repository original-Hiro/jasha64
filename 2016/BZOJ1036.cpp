#include <cstdio>
#include <algorithm>
using namespace std;

const int N = 30007, INF = 30007;
struct Edge {int t, Next;} e[N << 1];
struct Node {int dep, siz, fa, son, top, tid;} f[N];
struct SegmentTree {int Sum, Max;} SG[N << 2];
int n, Head[N], DFN, M = 1;

void DFS1(int x, int fa, int d)
{
  f[x].fa = fa; f[x].dep = d; f[x].siz = 1;
  for (int i = Head[x]; i; i = e[i].Next)
    {
      int v = e[i].t;
      if (v == fa) continue;
      DFS1(v, x, d + 1);
      f[x].siz += f[v].siz;
      if (f[v].siz > f[f[x].son].siz) f[x].son = v;
    }
}
void DFS2(int x, int top)
{
  f[x].top = top; f[x].tid = ++DFN;
  if (!f[x].son) return;
  DFS2(f[x].son, top);
  for (int i = Head[x]; i; i = e[i].Next)
    if (e[i].t != f[x].fa && e[i].t != f[x].son) DFS2(e[i].t, e[i].t);
}
int SG_Query_Max(int a, int b)
{
  int r = -INF;
  a += M - 1; b += M + 1;
  while (a ^ b ^ 1)
    {
      if (~a & 1) r = max(r, SG[a ^ 1].Max);
      if ( b & 1) r = max(r, SG[b ^ 1].Max);
      a >>= 1; b >>= 1;
    }
  return r;
}
int SG_Query_Sum(int a, int b)
{
  int r = 0;
  a += M - 1; b += M + 1;
  while (a ^ b ^ 1)
    {
      if (~a & 1) r += SG[a ^ 1].Sum;
      if ( b & 1) r += SG[b ^ 1].Sum;
      a >>= 1; b >>= 1;
    }
  return r;
}
inline void PushUP(int x) {SG[x].Sum = SG[x << 1].Sum + SG[x << 1 | 1].Sum; SG[x].Max = max(SG[x << 1].Max, SG[x << 1 | 1].Max);}
void SG_Modify(int x, int v)
{
  x += M;
  SG[x].Sum = SG[x].Max = v;
  while (x > 1) PushUP(x >>= 1);
}
int Query_Sum(int x, int y)
{
  int r = 0;
  while (f[x].top != f[y].top)
    {
      if (f[f[x].top].dep < f[f[y].top].dep) swap(x, y);
      int F = f[x].top;
      r += SG_Query_Sum(f[F].tid, f[x].tid);
      x = f[F].fa;
    }
  if (x == y) return r += SG_Query_Sum(f[x].tid, f[x].tid);
  if (f[x].dep > f[y].dep) swap(x, y);
  return r += SG_Query_Sum(f[x].tid, f[y].tid);
}
int Query_Max(int x, int y)
{
  int r = -INF;
  while (f[x].top != f[y].top)
    {
      if (f[f[x].top].dep < f[f[y].top].dep) swap(x, y);
      int F = f[x].top;
      r = max(r, SG_Query_Max(f[F].tid, f[x].tid));
      x = f[F].fa;
    }
  if (x == y) return r = max(r, SG_Query_Max(f[x].tid, f[y].tid));
  if (f[x].dep > f[y].dep) swap(x, y);
  return r = max(r, SG_Query_Max(f[x].tid, f[y].tid));
}
inline void Modify(int x, int v) {SG_Modify(f[x].tid, v);}

int main()
{
  scanf("%d", &n);
  while (M <= (n + 1)) M <<= 1;
  for (int i = 1, j = 2, a, b; i < n; i++)
    {
      scanf("%d%d", &a, &b);
      e[j].t = b; e[j].Next = Head[a]; Head[a] = j++;
      e[j].t = a; e[j].Next = Head[b]; Head[b] = j++;
    }

  DFS1(1, 0, 1); DFS2(1, 1);

  for (int i = 1, c; i <= n; i++) {scanf("%d", &c); Modify(i, c);}
  int q, a, b;
  char argv[7];
  scanf("%d", &q);
  while (q--)
    {
      scanf("%s%d%d", argv, &a, &b);
      if (argv[0] == 'C') Modify(a, b);
      else if (argv[1] == 'M') printf("%d\n", Query_Max(a, b));
      else printf("%d\n", Query_Sum(a, b));
    }

  return 0;
}

