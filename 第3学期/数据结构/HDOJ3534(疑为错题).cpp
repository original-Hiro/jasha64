//求树的直径有几条 
//利用求树的直径的动态规划算法，只是在DP过程中记录方案数 
//f[v] = max{g[u1] + w(v, u1) + g[u2] + w(v, u2) | u1, u2为v的子节点}
//gcnt[v] = sum{gcnt[u1] * gcnt[u2] | g[u1] + w(v, u1) + g[u2] + w(v, u2) == f[v]}
//maxlen = max{f[v] | v是树中的顶点}
//maxcnt = sum{gcnt[v] | f[v] == maxlen} 
#include <iostream>
#include <cstring>
using namespace std;

const int N = 100001;
int to[N+N], Head[N], Next[N+N], w[N+N];
inline void AddEdge(int v, int u, int W, int j) {to[j] = u; w[j] = W; Next[j] = Head[v]; Head[v] = j;}
int g[N], gcnt[N];
int maxlen, maxcnt;
void DFS(int v, int fa) //不需要保存fa时，可以把它作为参数传递，省掉一个fa数组 
{
	g[v] = 0; gcnt[v] = 1;
	for (int i = Head[v]; i != 0; i = Next[i])
	{
		int u = to[i];
		if (u == fa) continue;
		DFS(u, v);
		int curlen = g[u] + w[i];
		if (g[v] + curlen > maxlen) {maxlen = g[v] + curlen; maxcnt = gcnt[v] * gcnt[u];} //更新直径长度 
		else if (g[v] + curlen == maxlen) maxcnt += gcnt[v] * gcnt[u]; //计入直径条数 
		if (curlen > g[v]) {g[v] = curlen; gcnt[v] = gcnt[u];} //更新g[v] 
		else if (curlen == g[v]) gcnt[v] += gcnt[u]; //计入g[v]方案数 
	}
}
inline void Make_Tree(int v) {DFS(v, 0);}

int main()
{
	ios::sync_with_stdio(false);
	int n;
	while (cin >> n)
	{
		memset(Head, 0, sizeof(Head)); maxlen = 0;
		for (int i = 1, j = 2, v, u, w; i < n; i++) {cin >> v >> u >> w; AddEdge(v, u, w, j++); AddEdge(u, v, w, j++);}
		Make_Tree(1);
		cout << maxlen << ' ' << maxcnt << endl;
	}
	
	return 0;
}

