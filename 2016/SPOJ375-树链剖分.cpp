#include <cstdio>
#include <algorithm>
using namespace std;
#define lson o << 1, l, m
#define rson o << 1 | 1, m + 1, r

const int N = 10007;
struct Edge {int s, t, w, Next;} e[N << 1];
int Head[N], son[N], top[N], dep[N], siz[N], fa[N], fb[N], tid[N], idx = 0;
int Max[1 << 16 | 1], M;

void DFS1(int v)
{
	siz[v] = 1;
	for (int i = Head[v]; i; i = e[i].Next)
	{
		int u = e[i].t;
		if (u == fa[v]) continue;
		fa[u] = v; fb[u] = i; dep[u] = dep[v] + 1;
		DFS1(u);
		siz[v] += siz[u];
		if (siz[son[v]] < siz[u]) son[v] = u;
	}
}
void DFS2(int v, int tp)
{
	top[v] = tp;
	if (fb[v]) Max[(tid[v] = ++idx) + M] = e[fb[v]].w;
	if (!son[v]) return;
	DFS2(son[v], tp);
	for (int i = Head[v]; i; i = e[i].Next)
	{
		int u = e[i].t;
		if (u == fa[v] || u == son[v]) continue;
		DFS2(u, u);
	}
}
inline void Build(int n)
{
	for(int i = M - 1; i > 0; --i)
		Max[i] = max(Max[i << 1], Max[i << 1 | 1]);
}
inline int query(int s, int t)
{
	int rtn = 0;
	for(s += M - 1, t += M + 1; s ^ t ^ 1; s >>= 1, t >>= 1)
	{
		if(~s & 1) rtn = max(rtn, Max[s ^ 1]);
		if( t & 1) rtn = max(rtn, Max[t ^ 1]);
	}
	return rtn;
}
inline void Update(int s, int d)
{
	for(Max[s += M] = d, s >>= 1; s ^ 1; s >>= 1)
		Max[s] = max(Max[s << 1], Max[s << 1 | 1]);
}
inline int Query(int x, int y)
{
	int Ret = -0x7fffffff;
	while (top[x] != top[y])
	{
		if (dep[top[x]] < dep[top[y]]) swap(x, y);
		Ret = max(Ret, query(tid[top[x]], tid[x]));
		x = fa[top[x]];
	}
	if (x == y) return Ret;
	if (dep[x] > dep[y]) swap(x, y);
	Ret = max(Ret, query(tid[son[x]], tid[y]));
	return Ret;
}
inline void AddEdge(int f, int t, int d, int& T)
{
	e[++T].Next = Head[f]; e[T].s = f; e[T].t = t; e[T].w = d; Head[f] = T;
	e[++T].Next = Head[t]; e[T].s = t; e[T].t = f; e[T].w = d; Head[t] = T;
}

int main()
{
	int T;
	scanf("%d", &T);
	while(T--)
	{
		fill(Head, Head + N, 0);
		fill(son, son + N, 0);
		idx = 0;
		
		int n;
		scanf("%d", &n);
		M = 1;
		while (M <= n + 1) M <<= 1;
		for(int i = 1, j = 1, l, r, d; i < n; ++i)
		{
			scanf("%d%d%d", &l, &r, &d);
			AddEdge(l, r, d, j);
		}
		dep[1] = 0; DFS1(1);
		DFS2(1, 1);
		Build(n);
		
		while (true)
		{
			char cmd[7];
			int l, r;
			scanf("%s", cmd);
			if (cmd[0] == 'D') break;
			scanf("%d%d", &l, &r);
			if (cmd[0] == 'Q') printf("%d\n", Query(l, r));
			else if (cmd[0] == 'C')
			{
				int f = e[l << 1].s, t = e[l << 1].t;
				Update(dep[f] > dep[t] ? tid[f] : tid[t], r);
			}
		}
	}
	
	return 0;
}

