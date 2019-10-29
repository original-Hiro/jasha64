/*
欲求哪些点可能是直径的端点，先求出任一直径(u, v) 
思考其他端点与已知直径端点的关系，记len为直径长度，不难发现： 
若len为偶数，记x为直径的中点，所有与x距离最远的点都可能是直径端点 
若len为奇数，记(a, b)为直径最中间的一条边，与a距离最远的点、与b距离最远的点都可能是直径端点 
从而得出这样一种做法：与u距离最远的点、与v距离最远的点都可能是直径端点 
*/
/*
这题其实是道找规律的题，应该画图来找规律 
当时做这道题的时候下意识以为正解一定是DP，结果所有的时间都用来调DP了，也并没有做出来 
这启发我们，一种做法做不出来，可以立刻停下来，从头、完整地思考这道题目有没有其他做法 
*/
#include <iostream>
using namespace std;

const int N = 100001;
int to[N+N], Head[N], Next[N+N];
inline void AddEdge(int v, int u, int j) {to[j] = u; Next[j] = Head[v]; Head[v] = j;}
int dep[N], g[N];
bool flag[N]; 
void DFS(int v, int fa)
{
	g[v] = 0;
	for (int i = Head[v]; i != 0; i = Next[i])
	{
		int u = to[i];
		if (u == fa) continue;
		dep[u] = dep[v] + 1; DFS(u, v);
		g[v] = max(g[v], g[u] + 1);
	}
}
void Make_Tree(int v) {dep[v] = 0; DFS(v, 0);}

int main()
{
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	for (int i = 1, j = 2, v, u; i < n; i++) {cin >> v >> u; AddEdge(v, u, j++); AddEdge(u, v, j++);}
	
	Make_Tree(1);
	int nr = 1;
	for (int v = 2; v <= n; v++)
		if (dep[v] > dep[nr]) nr = v;
	Make_Tree(nr);
	int mx = 0;
	for (int v = 1; v <= n; v++)
		if (dep[v] > mx) {mx = dep[v]; nr = v;}
	for (int v = 1; v <= n; v++)
		if (dep[v] == mx) flag[v] = 1;
	Make_Tree(nr);
	for (int v = 1; v <= n; v++)
		if (dep[v] == mx) flag[v] = 1;
	
	int res = 0;
	for (int v = 1; v <= n; v++)
		if (flag[v]) res++;
	cout << res << endl;
	return 0;
}

