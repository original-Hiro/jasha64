//SPOJ - treeramids
//DFS
//首先很容易想出：进行BFS，计算完下一层的体积后求和并计算间隔，就是上一层的体积 
//因为自底向上的BFS实现相对麻烦，我们直接采用DFS，因为DFS也是遍历完子节点才会回归，
//所以仍然可以求出正确答案，利用其回归的过程完成计算即可 
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

const int N = 10001;
int to[N+N], Head[N], Next[N+N];
inline void AddEdge(int u, int v, int j) {to[j] = v; Next[j] = Head[u]; Head[u] = j;}
int f[N], fa[N];
void DFS(int v)
{
	f[v] = 1;
	for (int i = Head[v]; i != 0; i = Next[i])
	{
		int u = to[i];
		if (u == fa[v]) continue;
		fa[u] = v; DFS(u);
		f[v] = f[v] + f[u] + 1; //每增加一个子节点就要增加1的间隔，所以f[v] += f[u] + 1; 
	}
}
void Make_Tree(int v) {fa[v] = 0; DFS(v);}

int main()
{
	ios::sync_with_stdio(false);
	int T;
	cin >> T;
	while (T--)
	{
		memset(Head, 0, sizeof(Head)); //多笔测资时，每笔必须初始化邻接矩阵的Head 
		int n;
		cin >> n;
		for (int i = 1, j = 2, u, v; i < n; i++)
		{
			cin >> u >> v;
			AddEdge(u, v, j++); AddEdge(v, u, j++);
		}
		
		Make_Tree(0);
		int res = 0;
		for (int i = 0; i < n; i++) res += f[i];
		cout << res << endl;
	}
	
	return 0;
}

