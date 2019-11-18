//"CTSC" 2016
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
#define Jump_a {if (ta == Watcher[a]) ++Res[a]; a = fa[a]; ++ta;}
#define Jump_b {if (tb == Watcher[b]) ++Res[b]; b = fa[b]; --tb;}

const int N = 100007;
int n, q, Watcher[N], Res[N];
//Graph
int To[N << 1], Next[N << 1], Head[N];
inline void AddEdge(int a, int b, int d) {To[d] = b; Next[d] = Head[a]; Head[a] = d;}
//Tree
int dep[N], fa[N];
void DFS(int v)
{
	for (int i = Head[v]; i; i = Next[i])
	{
		int u = To[i];
		if (u != fa[v]) {dep[u] = dep[v] + 1; fa[u] = v; DFS(u);}
	}
}
//Namespaces
namespace One
{
	int Calc_Dist(int a, int b)
	{
		int da = 0, db = 0;
		if (dep[a] < dep[b]) swap(a, b);
		while (dep[a] > dep[b]) {a = fa[a]; ++da;}
		while (a != b) {a = fa[a]; ++da; b = fa[b]; ++db;}
		return da + db;
	}
	void Work()
	{
		int a, b;
		while (q--)
		{
			scanf("%d%d", &a, &b);
			int ta = 0, tb = Calc_Dist(a, b);
			while (dep[a] > dep[b]) Jump_a;
			while (dep[b] > dep[a]) Jump_b;
			while (a != b) {Jump_a; Jump_b;}
			if (ta == Watcher[a]) ++Res[a];
		}
	}
}
namespace Two
{
	void Work() //深度 = 节点编号 
	{
		int a, b;
		while (q--) {scanf("%d%d", &a, &b); ;}
		
	}
}
namespace Three
{
	void Work()
	{
		
	}
}
namespace Four
{
	void Work()
	{
		
	}
}
namespace Five
{
	void Work()
	{
		
	}
}

int main()
{
	freopen("running.in", "r", stdin);
	freopen("running.out", "w", stdout);
	
	cin >> n >> q;
	for (int i = 1, a, b, d = 2; i < n; i++)
	{
		scanf("%d%d", &a, &b);
		AddEdge(a, b, d++); AddEdge(b, a, d++);
	}
	dep[1] = 1; DFS(1);
	for (int i = 1; i <= n; i++) scanf("%d", &Watcher[i]);
	
	if (n % 10 <= 3) One::Work();
	else if (n % 10 == 4) Two::Work(); 
	else if (n % 10 == 5) Three::Work();
	else if (n % 10 == 6) Four::Work();
	else Five::Work();
	
	printf("%d", Res[1]);
	for (int i = 2; i <= n; i++) printf(" %d", Res[i]);
	printf("\n");
	
	return 0; //mdzz
}

