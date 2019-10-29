#include <iostream>
#include <cstdio>
#include <algorithm>
#include <stack>
using namespace std;

const int N = 200007;
int n;
struct _
{
  int kx[N], sz[N], ch[N][2], fa[N];
  bool rev[N];
  inline bool isRoot(int v) {return ch[fa[v]][0] != v && ch[fa[v]][1] != v;}
  inline void Pushup(int v) {sz[v] = sz[ch[v][0]] + sz[ch[v][1]] + 1;}
  inline void Pushdown(int v)
  {
    if (!rev[v]) return;
    int &lch = ch[v][0], &rch = ch[v][1];
    rev[v] = 0; swap(lch, rch);
    rev[lch] ^= 1; rev[rch] ^= 1;
  }
  inline void Access(int v)
  {
    int u = 0;
    while (v) {
      Splay(v);
      ch[v][1] = u;
      u = v; v = fa[v];
    }
  }
  inline void Splay(int x)
  {
    stack<int> s;
    s.push(x);
    for (int y = x; !isRoot(y); y = fa[y]) s.push(fa[y]);
    while (!s.empty()) {Pushdown(s.top()); s.pop();}
    while (!isRoot(x)) {
      int y = fa[x], z = fa[y];
      if (!isRoot(y)) {
	if (ch[y][0] == x ^ ch[z][0] == y) Rotate(x);
	else Rotate(y);
      }
      Rotate(x);
    }
  }
  inline void Rotate(int x)
  {
    int y = fa[x], z = fa[y], l = ch[y][0] == x ? 0 : 1, r = l ^ 1;
    if (!isRoot(y)) {if (ch[z][0] == y) ch[z][0] = x; else ch[z][1] = x;}
    fa[x] = z; fa[y] = x;
    fa[ch[x][r]] = y; ch[y][l] = ch[x][r]; ch[x][r] = y;
    Pushup(y); Pushup(x);
  }
  inline void MakeRoot(int v) {Access(v); Splay(v); rev[v] ^= 1;}
  inline int FindRoot(int v)
  {
    Access(v); Splay(v);
    int u = v;
    while (ch[u][0]) u = ch[u][0];
    return u;
  }
  inline void Link(int v, int u) {MakeRoot(v); fa[v] = u;}
  inline void Cut(int v, int u) {MakeRoot(v); Access(u); Splay(u); fa[v] = ch[u][0] = 0;}
  inline int Query(int v) {MakeRoot(n); Access(v); Splay(v); return sz[ch[v][0]];}
} LCT;

int main()
{
  int q;

  cin >> n; ++n;
  for (int i = 1; i < n; i++) {scanf("%d", &LCT.kx[i]); LCT.sz[i] = 1; LCT.Link(i, min(n, i + LCT.kx[i]));}
  cin >> q;
  int cmd, a, b;
  while (q--) {
    scanf("%d%d", &cmd, &a); ++a;
    if (cmd == 1) {printf("%d\n", LCT.Query(a));}
    else if (cmd == 2) {
      int& kx = LCT.kx[a];
      scanf("%d", &b);
      LCT.Cut(a, min(n, a + kx));
      kx = b;
      LCT.Link(a, min(n, a + kx));
    }
  }

  return 0;
}
