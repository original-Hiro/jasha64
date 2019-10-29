#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <queue>
using namespace std;
#define lson o << 1, l, m
#define rson o << 1 | 1, m + 1, r

const int N = 100007, INF = 1073741823;
struct Edge {int t, f, Next;} e[N << 1];
struct Comm {int t, a, b;} c[N];
int n, q, Head[N];

namespace One
{
	int m, dep[N], fa[N], siz[N], son[N], top[N], tid[N], a[N], SG[1 << 17 | 1], L, R, V;
	void DFS1(int v)
	{
		siz[v] = 1;
		for (int i = Head[v]; i; i = e[i].Next)
		{
			const int& u = e[i].t;
			if (u == fa[v]) continue;
			dep[u] = dep[v] + 1; fa[u] = v;
			DFS1(u);
			siz[v] += siz[u];
			if (siz[u] > siz[son[v]]) son[v] = u;
		}
	}
	void DFS2(int v, int t)
	{
		top[v] = t;
		for (int i = Head[v]; i; i = e[i].Next)
		{
			const int& u = e[i].t;
			if (u == fa[v]) continue;
			if (u != son[v]) {DFS2(u, u); tid[u] = e[i].f;}
			else {DFS2(u, t); a[tid[u] = ++m] = e[i].f;}
		}
	}
	void SG_Build(int o, int l, int r)
	{
		if (l == r) {SG[o] = a[l]; return;}
		int m = (l + r) >> 1;
		SG_Build(lson); SG_Build(rson);
		SG[o] = min(SG[o << 1], SG[o << 1 | 1]);
	}
	int SG_Query(int o, int l, int r)
	{
		if (L <= l && r <= R) return SG[o];
		int m = (l + r) >> 1, Ret = INF;
		if (m >= L) Ret = min(Ret, SG_Query(lson));
		if (m < R) Ret = min(Ret, SG_Query(rson));
		return Ret;
	}
	void SG_Modify(int o, int l, int r)
	{
		if (l == r) {SG[o] = V; return;}
		int m = (l + r) >> 1;
		if (m < L) SG_Modify(rson);
		else SG_Modify(lson);
		SG[o] = min(SG[o << 1], SG[o << 1 | 1]);
	}
	int Query(int a, int b)
	{
		if (dep[a] < dep[b]) swap(a, b);
		
		int Ret = INF;
		while (a != b)
		{
			if (top[a] == top[b])
			{
				L = tid[a]; R = tid[son[b]];
				Ret = min(Ret, SG_Query(1, 1, m));
				return Ret;
			}
			if (a != top[a])
			{
				L = tid[a]; R = tid[son[top[a]]];
				Ret = min(Ret, SG_Query(1, 1, m));
			}
			Ret = min(Ret, tid[top[a]]); a = fa[top[a]];
			if (dep[a] < dep[b]) swap(a, b);
		}
		
		return Ret;
	}
	inline void Modify(int a, int b)
	{
		int v = e[a].t, u = e[a ^ 1].t;
		if (top[u] == top[v])
			if (fa[u] == v) {L = tid[u]; V = b; SG_Modify(1, 1, m); return;}
			else {L = tid[v]; V = b; SG_Modify(1, 1, m); return;}
		tid[e[a].t] = tid[e[a ^ 1].t] = b;
	}
	void Work()
	{
		srand(time(NULL));
		int r = rand() % n + 1;
		DFS1(r); DFS2(r, r);
		SG_Build(1, 1, m);
		for (int i = 0; i < q; i++)
			if (c[i].t == 0) printf("%d\n", Query(c[i].a, c[i].b));
			else {int x = c[i].a << 1; e[x].f = e[x ^ 1].f = c[i].b; Modify(x, c[i].b);}
	}
}
namespace Two
{
	int d[N];
	bool Build(int s, int t)
	{
		queue<int> Q;
		fill(d, d + N, 0);
		Q.push(s);
		while (!Q.empty())
		{
			int v = Q.front(); Q.pop();
			for (int i = Head[v]; i; i = e[i].Next)
			{
				int u = e[i].t;
				if (d[u] || !e[i].f) continue;
				d[u] = d[v] + 1;
				Q.push(u);
				if (u == t) return true;
			}
		}
		return false;
	}
	int Dinic(int v, int t, int flow)
	{
		if (v == t) return flow;
		int k = flow;
		for (int i = Head[v]; i; i = e[i].Next)
		{
			int u = e[i].t;
			if (d[u] != d[v] + 1 || !e[i].f) continue;
			int delta = Dinic(u, t, min(k, e[i].f));
			k -= delta; e[i].f -= delta; e[i ^ 1].f -= delta;
			if (!k) return flow;
		}
		if (k == flow) d[v] = -1;
		return flow - k;
	}
	void Work()
	{
		for (int i = 0; i < q; i++)
			if (c[i].t == 1)
			{
				int x = c[i].a << 1;
				e[x].f = e[x ^ 1].f = c[i].b;
			}
			else {
				int s = c[i].a, t = c[i].b;
				long long Res = 0;
				while (Build(s, t)) Res += Dinic(s, t, INF);
				printf("%d\n", Res);
			}
	}
}
inline void AddEdge(int s, int t, int f, int& T)
{
	e[T].t = t; e[T].f = f; e[T].Next = Head[s]; Head[s] = T++;
	e[T].t = s; e[T].f = f; e[T].Next = Head[t]; Head[t] = T++;
}

int main()
{
	freopen("flow.in", "r", stdin);
	freopen("flow.out", "w", stdout);
	
	int m;
	
	cin >> n >> m;
	for (int i = 0, Top = 2, a, b, f; i < m; i++)
	{
		scanf("%d%d%d", &a, &b, &f);
		AddEdge(a, b, f, Top);
	}
	cin >> q;
	for (int i = 0; i < q; i++) scanf("%d%d%d", &c[i].t, &c[i].a, &c[i].b);
	
	if (m == n - 1) One::Work();
	else Two::Work();
	
	return 0;
}

