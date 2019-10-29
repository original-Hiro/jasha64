#include <iostream>
#include <cstdio>
#include <set>
#include <algorithm>
using namespace std;

const int N = 10007, M = N << 1;
namespace Ufind
{
	int f[N];
	void Init () {for (int i = 1; i < N; i++) f[i] = i;}
	void Merge(int a, int b) {f[Find(a)] = Find(b);}
	int Find(int x)
	{
		if (f[x] != x) return f[x] = Find(f[x]);
		return x;
	}
}
namespace Graph
{
	int s[M], t[M], w[M], Next[M], Head[N], m = 2;
	void AddEdge(int a, int b, int c)
	{
		s[m] = a; t[m] = b; w[m] = c; Next[m] = Head[a]; Head[a] = m++;
		s[m] = b; t[m] = a; w[m] = c; Next[m] = Head[b]; Head[b] = m++;
	}
}
namespace Tree
{
	int t[M], w[M], Next[M], Head[N], m = 2;
	bool vis[N];
	int f[N][15], g[N][15], dep[N];
	struct Edge
	{
		int x;
		Edge() {}
		Edge(int x):x(x) {}
		friend bool operator < (const Edge& a, const Edge& b) {return Graph::w[a] > Graph::w[b];}
	} e[N];
	void AddEdge(int d)
	{
		int s = Graph::s[d];
		t[m] = Graph::t[d]; w[m] = Graph::w[d]; Next[m] = Head[s]; Head[s] = m++;
		t[m] = s; w[m] = w[m ^ 1]; Next[m] = Head[Graph::t[d]]; Head[Graph::t[d]] = m++;
	}
	void Kruskal()
	{
		int t = 0;
		for (int i = 2; i <= Graph::m; i += 2) e[t++] = i;
		sort(e, e + t);
		for (int i = 0; i < t; i++)
			if (Ufind::Find(a) != Ufind::Find(b)) {Ufind::Merge(a, b); AddEdge(e[i]);}
		for (int i = 1; i <= n; i++)
			if (!vis[i]) DFS(i, 0);
		Calc();
	}
	void DFS(int v, int fa)
	{
		vis[v] = true; f[v][0] = fa; dep[v] = dep[fa] + 1;
		for (i = Head[v]; i; i = Next[i])
		{
			int u = t[i];
			if (!vis[u] && u != fa) {g[u][0] = w[i]; DFS(u, v);}
		}
	}
	void Calc()
	{
		for (int k = 1; k < 15; k++)
			for (int i = 1; i <= n; i++)
			{
				f[i][k] = f[f[i][k - 1]][k - 1];
				g[i][k] = min(g[i][k - 1], g[f[i][k - 1]][k - 1]);
			}
	}
	int Query(int a, int b)
	{
		if (Ufind::Find(a) != Ufind::Find(b)) return -1;
		
		int Ret = 0x7fffffff;
		if (dep[a] < dep[b]) swap(a, b);
		while (a != b)
		{
			int i = 0;
			while (dep[f[a][i]] < dep[b]) i++;
			Ret = min(Ret, g[a][i]);
			a = f[a][i];
			swap(a, b);
		}
		return Ret;
	}
}

int main()
{
	int n, m, q;
	
	cin >> n >> m;
	Ufind::Init();
	for (int i = 0, a, b, c; i < m; i++)
	{
		scanf("%d%d%d", &a, &b, &c);
		Graph::AddEdge(a, b, c); Ufind::Merge(a, b);
	}
	Tree::Kruskal();
	cin >> q;
	while (q--) {scanf("%d%d", &a, &b); printf("%d\n", Tree::Query(a, b));}
	
	return 0;
}

