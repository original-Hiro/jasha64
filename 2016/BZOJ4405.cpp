#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;

const int N = 407;
struct Edge {int t, Next;} e[160007];
int Head[N], Match[N], Belong[N], Next[N], Sign[N], vis[N], Top = 1, t = 1, n, ResCnt;

int Find(int x) {return Belong[x] == x ? x : Belong[x] = Find(Belong[x]);}
void Unite(int a, int b) {if (Find(a) != Find(b)) Belong[Find(a)] = Find(b);}
int LCA(int a, int b)
{
  ++t;
  while (true) {
    if (!a) continue;
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
    int b = Match[a], c = Next[b];
    if (Find(c) != p) Next[c] = b;
    Sign[b] = 1; q.push(b);
    Unite(b, c); Unite(a, c);
    a = c;
  }
}
void Augment(int s)
{
  fill(Next, Next + N, 0); fill(Sign, Sign + N, 0); fill(vis, vis + N, 0);
  for (int i = 1; i <= n; i++) Belong[i] = i;

  queue<int> q;
  q.push(s); Sign[s] = 1;
  while (!q.empty()) {
    int v = q.front(); q.pop();
    for (int i = Head[v]; i; i = e[i].Next) {
      int x = e[i].t;
      if (Match[x] == v || Sign[x] == 2 || Find(x) == Find(v)) continue;
      if (Sign[x] == 1) {
	int r = LCA(x, v);
	if (Find(x) != r) Next[x] = v;
	if (Find(v) != r) Next[v] = x;
	Contract(x, r, q); Contract(v, r, q);
      }
      else if (!Match[x]) {
	Next[x] = v;
	int a = x, b, mb;
	while (a) {
	  b = Next[a]; mb = Match[b];
	  Match[b] = a; Match[a] = b;
	  a = mb;
	}
	++ResCnt; return;
      }
      else {Sign[x] = 2; Sign[Match[x]] = 1; Next[x] = v; q.push(Match[x]);}
    }
  }
}
inline void AddEdge(int v, int u)
{
  e[Top].t = u; e[Top].Next = Head[v]; Head[v] = Top++;
  e[Top].t = v; e[Top].Next = Head[u]; Head[u] = Top++;
}

int main()
{
  int T;

  scanf("%d", &T);
  while (T--) {
    fill(Head, Head + N, 0); fill(Match, Match + N, 0);
    t = Top = 1; ResCnt = 0;

    int m, e;
    scanf("%d%d%d", &n, &m, &e);
    for (int i = 1; i <= m; i++) AddEdge(n + i * 3 - 2, n + i * 3 - 1);
    for (int i = 0, a, b; i < e; i++) {
      scanf("%d%d", &a, &b);
      for (int k = 0; k < 3; k++) AddEdge(a, n + b * 3 - k);
    }
    n += 3 * m;

    for (int i = 1; i <= n; i++)
      if (!Match[i]) Augment(i);

    n -= 3 * m;
    printf("%d\n", ResCnt - n);
  }

  return 0;
}
