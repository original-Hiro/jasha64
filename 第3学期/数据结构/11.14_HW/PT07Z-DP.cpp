//SPOJ - longest path in a tree
//DP
//我曾经在高中信息奥赛书上看到过树上最长路的DP解法：
//对于以任一节点v为根的子树，记g[v]为这一子树中根到节点的距离的最大值，易见g[v] = max{g[u] + 1}，u是v的子节点 
//则，以任一节点r为根的子树中的最长路径f[v] = g[u] + g[v] + 1，其中u和v是r的子节点中g值前两大的 
//我们随意指定一个根节点，如上操作即可，最后答案为max{f[v] | v是树上的节点 
#include <iostream>
#include <algorithm>
using namespace std;

const int N = 10001;
int to[N+N], Head[N], Next[N+N];
inline void AddEdge(int u, int v, int i) {to[i] = v; Next[i] = Head[u]; Head[u] = i;}
int f[N], fa[N], maxlen; //f[v]表示以v为根的子树中根到节点的距离的最大值 
inline void Tension(int& a, int b) {if (a < b) a = b;}
void DFS(int v) //建树并完成节点v的f值的计算 
{
	f[v] = 0;
	for (int i = Head[v]; i != 0; i = Next[i])
	{
		int u = to[i];
		if (u == fa[v]) continue;
		fa[u] = v; DFS(u);
		int curlen = f[u] + 1;
		Tension(maxlen, f[v] + curlen);
		//此时f[v]存储的是访问到u以前访问的子节点中f的最大值，这种写法可确保取到最大值和次大值，而且不用特判没有子节点和只有1个子节点的情况 
		Tension(f[v], curlen);
	}
}
void Make_Tree(int v) {fa[v] = 0; DFS(v);}

int main()
{
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	for (int i = 1, j = 2, u, v; i < n; i++)
	{
		cin >> u >> v;
		AddEdge(u, v, j++); AddEdge(v, u, j++);
	}
	
	Make_Tree(1);
	cout << maxlen << endl;
	
	return 0;
}

