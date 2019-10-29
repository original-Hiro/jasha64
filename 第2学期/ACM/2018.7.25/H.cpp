#include <iostream>
#include <cstring>
#include <cstdio>
#include <cctype>
using namespace std;

//有负数时的读入优化（七行读入优化） 
inline int Read()
{
	int r = 0;
	bool isNeg = 0;
	char c = getchar();
	while (!isdigit(c) && c != '-') c = getchar();
	if (c == '-') {isNeg = 1; c = getchar();}
	while (isdigit(c)) {r = r*10 + c-'0'; c = getchar();}
	return isNeg ? -r : r;
}

typedef long long ll;
const int N = 100007;
int w[N];

int t[N+N], Head[N], Next[N+N], Top;
inline void AddEdge(int S, int T)
{
	t[Top] = T;
	Next[Top] = Head[S]; Head[S] = Top;
	Top++;
}

ll f[N]; //f[i]表示包含节点i的路径条数  
int n, fa[N], dep[N], siz[N];
void DFS(int u)
{
	ll l = 0, r = 0; //u的左、右子树的大小 
	siz[u] = 1;
	for (int i = Head[u]; i; i = Next[i])
	{
		int v = t[i];
		if (v == fa[u]) continue;
		fa[v] = u; dep[v] = dep[u]+1;
		DFS(v);
		siz[u] += siz[v];
		if (l == 0) l = siz[v];
		else r = siz[v]; //已知条件保证u如果有子节点则必有左右2个 
	}
	ll p = n-1 - l - r; //树中除去以u为根子树剩余的节点数 
	f[u] = (l*r + r*p + p*l + n-1) * 2 + 1;
	//不以i为一端的路径数为2(lr+ur+lu)，以i为一端的路径数为2(n-1)，乘以2的原因是树是无向图，以i为两端的路径数为1（即路径i->i）
}
void Make_Tree() {fa[n] = 0; dep[n] = 1; DFS(n);}

int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		cin >> n;
		for (int i = 1; i <= n; i++) w[i] = Read();
		memset(Head, 0, sizeof(Head)); Top = 2;
		for (int i = 0, u, v; i < n-1; i++)
		{
			u = Read(); v = Read();
			AddEdge(u, v); AddEdge(v, u);
		}

		Make_Tree();
		//Res == 0: 已经成立SUM == 0
		ll SUM = 0;
		for (int i = 1; i <= n; i++) SUM += w[i] * f[i];
		if (SUM == 0) {cout << 0 << endl; continue;}
		//Res == 1: SUM != 0，且存在节点u使得SUM % f[u] == 0
		bool Sol1 = 0;
		for (int i = 1; i <= n; i++)
			if (SUM % f[i] == 0)
			{
				cout << 1 << ' ' << i << endl;
				Sol1 = 1;
				break;
			}
		if (Sol1) continue;
		//Res == 2: 上述两种情况都不成立 
		int o = 1;
		for (int i = 2; i <= n; i++)
			if (dep[o] < dep[i]) o = i;
		cout << 2 << ' ' << o << ' ' << fa[o] << endl;
	}

	return 0;
}

