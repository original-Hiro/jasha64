#include <iostream>
#include <algorithm>
#include <cstdlib>
using namespace std;

const int N = 10007;
struct Edge {int t, v, Next;} e[N<<1];
int Head[N];
inline void AddEdge(int s, int t, int v, int& T)
{
	e[T].t = t; e[T].v = v; e[T].Next = Head[s]; Head[s] = T++;
}

int n;
int f[N][15], g[N][15], dep[N];
void DFS(int v)
{
	for (int i = Head[v]; i; i = e[i].Next)
	{
		int u = e[i].t;
		if (u == f[v][0]) continue;
		dep[u] = dep[v] + 1; f[u][0] = v; g[u][0] = e[i].v; DFS(u);
	}
}
void LCA_Ready()
{
	for (int k = 1; (1<<k) < n; k++)
		for (int i = 1; i <= n; i++)
		{
			f[i][k] = f[f[i][k-1]][k-1];
			g[i][k] = g[i][k-1] + g[f[i][k-1]][k-1];
		}
}
int LCA(int v, int u)
{
	if (dep[v] < dep[u]) swap(v, u);
	for (int k = 14; k >= 0; k--)
		if (dep[f[v][k]] >= dep[u]) v = f[v][k];
	if (v == u) return v;
	for (int k = 14; k >= 0; k--)
		if (f[v][k] != f[u][k]) {v = f[v][k]; u = f[u][k];}
	return f[v][0];
}
int Dist(int v, int u)
{
	int Ret = 0;
	if (dep[v] < dep[u]) swap(v, u);
	for (int k = 14; k >= 0; k--)
		if (dep[f[v][k]] >= dep[u]) {Ret += g[v][k]; v = f[v][k];}
	if (v == u) return Ret;
	for (int k = 14; k >= 0; k--)
		if (f[v][k] != f[u][k])
		{
			Ret += g[v][k]; v = f[v][k];
			Ret += g[u][k]; u = f[u][k];
		}
	return Ret + g[v][0] + g[u][0];
}
int Find_Kth(int s, int t, int k)
{
	if (dep[s] < dep[t]) return Find_Kth(t, s, dep[t] - dep[s] + 2 - k);
	--k;
	for (int i = 14; i >= 0; i--)
		if ((1<<i) & k) s = f[s][i];
	return s;
}
int Kth(int v, int u, int k)
{
	int p = LCA(v, u);
	int d = dep[v] - dep[p] + 1 - k;
	if (d == 0) return p;
	else if (d > 0) return Find_Kth(v, p, k);
	else return Find_Kth(p, u, -d + 1);
}

int main()
{
	ios::sync_with_stdio(false);
	srand(19260817);
	
	int T;
	cin >> T;
	while (T--)
	{
		fill(Head, Head + N, 0);
		
		cin >> n;
		for (int i = 1, j = 2, a, b, c; i < n; i++)
		{
			cin >> a >> b >> c;
			AddEdge(a, b, c, j); AddEdge(b, a, c, j);
		}
		
		int r = rand() % n + 1;
		f[r][0] = 0; dep[r] = 1; DFS(r);
		LCA_Ready();
		
		char cmd[7];
		while (true)
		{
			cin >> cmd;
			if (cmd[1] == 'O') break;
			int a, b, k;
			cin >> a >> b;
			if (cmd[0] == 'D') cout << Dist(a, b) << endl;
			else {cin >> k; cout << Kth(a, b, k) << endl;}
		}
		cout << endl;
	}
	
	return 0;
}

