//SPOJ - longest path in a tree
//DFS
//求树上最长路的DFS做法是：先随意指定一个点为根，通过DFS建立起树结构，然后选出此时 
//深度最大的节点，再以选出的这个节点为根建树，最后最大的深度即为所求的最长路的长度 
//依据是，无论以哪个点为根，最深的节点一定在待求的最长路中 
#include <iostream>
#include <algorithm>
using namespace std;

const int N = 10001;
int to[N+N], Head[N], Next[N+N]; //to和Next用于存边，需要开2n+2的大小（无向图） 
inline void AddEdge(int u, int v, int i) {to[i] = v; Next[i] = Head[u]; Head[u] = i;}
int fa[N], dep[N];
void DFS(int v)
{
	for (int i = Head[v]; i != 0; i = Next[i])
	{
		int u = to[i];
		if (u == fa[v]) continue;
		fa[u] = v; dep[u] = dep[v] + 1; DFS(u);
	}
}
void Make_Tree(int v) {fa[v] = dep[v] = 0; DFS(v);}

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
	int cur = 1;
	for (int i = 2; i <= n; i++)
		if (dep[i] > dep[cur]) cur = i;
	Make_Tree(cur);
	
	cout << *max_element(dep+1, dep+n+1) << endl;
	return 0;
}

