#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

const int dx[] = {-1, 0, 0, 1}, dy[] = {0, -1, 1, 0}, N = 407;
int n, m;
char c[47][17];
struct Edge {int t, Next;} e[1607];
int Head[N], Match[N], Belong[N], Next[N], Sign[N], vis[N], Top = 1, ResCnt, t = 1;

inline int Num(int x, int y) {return (x - 1) * m + y;}
inline void AddEdge(int p, int pp) {e[Top].t = pp; e[Top].Next = Head[p]; Head[p] = Top++;}
int Find(int x) {return Belong[x] == x ? x : Belong[x] = Find(Belong[x]);}
inline void Unit(int a, int b) {if (Find(a) != Find(b)) Belong[Find(a)] = Find(b);}
int LCA(int a, int b)
{
  ++t;
  while (true) {
    if (!a) {swap(a, b); continue;}
    a = Find(a);
    if (vis[a] == t) return a;
    vis[a] = t;
    a = Next[Match[a]];
    swap(a, b);
  }
}
void Contract(int a, int p, queue<int>& q)
{
  while (a != p) {
    int ma = Match[a], c = Next[ma];
    if (Find(c) != p) Next[c] = ma;
    Sign[ma] = 1; q.push(ma);
    Unit(a, c); Unit(ma, c);
    a = c;
  }
}
void Augment(int s)
{
  memset(Next, 0, sizeof(Next)); memset(Sign, 0, sizeof(Sign)); memset(vis, 0, sizeof(vis));
  for (int i = n * m; i > 0; i--) Belong[i] = i;

  queue<int> q;
  q.push(s); Sign[s] = 1;
  while (!q.empty()) {
    int v = q.front(); q.pop();
    for (int i = Head[v]; i; i = e[i].Next) {
      int x = e[i].t;
      if (Match[x] == v || Find(x) == Find(v) || Sign[x] == 2) continue;
      if (Sign[x] == 1) {
	int r = LCA(v, x);
	if (Find(v) != r) Next[v] = x;
	if (Find(x) != r) Next[x] = v;
	Contract(v, r, q); Contract(x, r, q);
      }
      else if (!Match[x]) {
	Next[x] = v;
	int a = x, b, mb;
	while (a) {
	  b = Next[a]; mb = Match[b];
	  Match[b] = a; Match[a] = b;
	  a = mb;
	}
	--ResCnt; return;
      }
      else {Sign[x] = 2; Sign[Match[x]] = 1; q.push(Match[x]); Next[x] = v;}
    }
  }
}

int main()
{
  int T;
  cin >> T;
  while (T--) {
    memset(Head, 0, sizeof(Head)); memset(Match, 0, sizeof(Match));
    Top = 1; ResCnt = 0; t = 1;

    cin >> n >> m;
    for (int i = 1; i <= n; i++) scanf("%s", c[i] + 1);

    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= m; j++)
	if (c[i][j] == '*') {
	  ++ResCnt;
	  for (int k = 0; k < 4; k++) {
	    int ti = i + dx[k], tj = j + dy[k];
	    if (ti < 1 || ti > n || tj < 1 || tj > m || c[ti][tj] == 'o') continue;
	    AddEdge(Num(i, j), Num(ti, tj));
	  }
	}

    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= m; j++) {
	if (c[i][j] == 'o') continue;
	int p = Num(i, j);
	if (!Match[p]) Augment(p);
      }

    cout << ResCnt << endl;
  }

  return 0;
}
