#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

const int N = 10007, M = 50007, K = 14;
//initial graph
struct Edge {
  int s, t, w;
  friend bool operator < (const Edge& a, const Edge& b) {return a.w < b.w;}
  friend istream& operator >> (istream& input, Edge& e)
  {
    input >> e.s >> e.t >> e.w;
    return input;
  }
} e[M];

int n;

//make tree
int t[N+N], w[N+N], Head[N], Next[N+N], top; 
inline void AddEdge(int S, int T, int W)
{
  t[top] = T; w[top] = W;
  Next[top] = Head[S]; Head[S] = top; top++;
}
int fa[N], dep[N];
int f[N][K], g[N][K];
void DFS(int u)
{
  for (int i = Head[u]; i; i = Next[i]) {
    int v = t[i];
    if (v == fa[u]) continue;
    fa[v] = u; g[v][0] = w[i]; dep[v] = dep[u]+1;
    DFS(v);
  }
}
inline void Make_Tree() {dep[n] = 1; fa[n] = 0; DFS(n);}

//union find & kruskal
int ff[N];
int Find(int x) {return ff[x] == x ? x : ff[x] = Find(ff[x]);}
void Kruskal()
{
  memset(Head, 0, sizeof(Head)); top = 2;
  for (int i = 1; i <= n; i++) ff[i] = i;
  sort(e, e+n);

  for (int i = 0; i < n; i++) {
    int u = e[i].s, v = e[i].t, w = e[i].w;
    if (Find(u) == Find(v)) continue;
    AddEdge(u, v, w); AddEdge(v, u, w); ff[Find(u)] = Find(v);
  }
}

//queries
void Calc_Table()
{
  memset(f, 0, sizeof(f));
  for (int i = 1; i <= n; i++) f[i][0] = fa[i];
  for (int k = 1; (1<<k) < n; k++)
    for (int i = 1; i <= n; i++) {
      f[i][k] = f[f[i][k-1]][k-1];
      g[i][k] = min(g[i][k-1], g[f[i][k-1]][k-1]);
    }
}
inline int min(int a, int b, int c) {return min(a, min(b, c));}
int Query(int a, int b)
{
  int r = 0x7fffffff;

  if (dep[a] < dep[b]) swap(a, b);
  for (int k = K-1; k >= 0; k--)
    if (f[a][k] != 0 && dep[f[a][k]] >= dep[b]) {r = min(r, g[a][k]); a = f[a][k];}
  if (a == b) return r;

  for (int k = K-1; k >= 0; k--)
    if (f[a][k] != f[b][k]) {r = min(r, g[a][k], g[b][k]); a = f[a][k]; b = f[b][k];}
  r = min(r, g[a][0], g[b][0]);
  return r;
}


int main()
{
	ios::sync_with_stdio(false);
	int m;
	cin >> n >> m;
	for (int i = 0; i < m; i++) cin >> e[i];
	Kruskal(); Make_Tree();

	Calc_Table();
	int q;
	cin >> q;
	while (q--) {
		int a, b;
		cin >> a >> b;
		cout << Query(a, b) << endl;
	}

	return 0;
}

