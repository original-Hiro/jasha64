#include <iostream>
#include <algorithm>
using namespace std;

const int N = 200007;
int t[N+N], Head[N], Next[N+N], Top = 2;
inline void AddEdge(int S, int T)
{
	t[Top] = T;
	Next[Top] = Head[S]; Head[S] = Top;
	Top++;
}

int deg[N], fa[N];
int f[N], g[N]; //f:以节点为根的子树，节点所在各链上的分岔点数目之和最大值; g:以节点为一端的链，分岔点数目之和最大值 
void DFS(int u)
{
	int max1 = 0, max2 = 0, d = (deg[u] > 2);
	for (int i = Head[u]; i; i = Next[i])
	{
		int v = t[i];
		if (v == fa[u]) continue;
		fa[v] = u; DFS(v);
		g[u] = max(g[u], g[v]+d);
		//找最大的两个数的另一种写法 
		max2 = max(max2, g[v]);
		if (max1 < max2) swap(max1, max2);
	}
	f[u] = max1 + max2 + d;
}

int main()
{
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	int tot = 0; //分岔点总个数 
	for (int i = 0, a, b; i < n-1; i++)
	{
		cin >> a >> b;
		AddEdge(a, b); AddEdge(b, a);
		if (++deg[a] == 3) tot++;
		if (++deg[b] == 3) tot++;
	}
	
	DFS(1);
	for (int i = 1; i <= n; i++)
		if (f[i] == tot) {cout << "YES" << endl; return 0;}
	cout << "NO" << endl;
	
	return 0;
}

