#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

const int N = 20007;
struct Edge {int t, v, Next;} e[200007];
int Top = 2, n, Head[N], High;
int vis[N], Mid;

inline void AddEdge(int a, int b, int c)
{
	e[Top].t = b; e[Top].v = c;
	e[Top].Next = Head[a]; Head[a] = Top++;
}
bool DFS(int v, int prev)
{
	vis[v] = prev ? -vis[prev] : 1;
	for (int i = Head[v]; i; i = e[i].Next)
	{
		if (e[i].v < Mid) continue; 
		int u = e[i].t;
		if (vis[u] == vis[v]) return false;
		if (!vis[u] && !DFS(u, v)) return false;
	}
	return true;
}
bool Can()
{
	fill(vis + 1, vis + n + 1, 0);
	for (int i = 1; i <= n; i++)
		if (!vis[i] && !DFS(i, 0)) return false;
	return true;
}
void BSearch()
{
	int Low = 0, Ans = High;
	Mid = High >> 1;
	
	while (Low <= High)
	{
		if (Can()) {Ans = Mid; High = Mid - 1;}
		else Low = Mid + 1;
		Mid = (Low + High) >> 1;
	}
	
	cout << max(Ans - 1, 0) << endl;
}

int main()
{
	int m;
	
	cin >> n >> m;
	for (int i = 1, a, b, c; i <= m; i++)
	{
		scanf("%d%d%d", &a, &b, &c);
		High = max(High, c);
		AddEdge(a, b, c); AddEdge(b, a, c);
	}
	
	BSearch();
	
	return 0;
}

