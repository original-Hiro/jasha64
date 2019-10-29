#include <iostream>
#include <algorithm>
#include <cstdlib>
using namespace std;

int n;

const int N = 10007;
struct Edge {int t, v, s, Next;} e[N<<1];
int Head[N];
inline void AddEdge(int s, int t, int v, int& Top)
{
	e[Top].t = t; e[Top].v = v; e[Top].Next = Head[s]; Head[s] = Top++;
}

#define lo o<<1
#define ro o<<1|1
#define lson o<<1,   l,   m
#define rson o<<1|1, m+1, r
const int MAXM = 1<<15|1;
int SG[MAXM];
void SG_Modify(int o, int l, int r, const int p, const int v)
{
	if (l == r) {SG[o] = v; return;}
	int m = (l+r)>>1;
	if (p <= m) SG_Modify(lson, p, v);
	else SG_Modify(rson, p, v);
	SG[o] = max(SG[lo], SG[ro]);
}
int SG_Query(int o, int l, int r, const int ll, const int rr)
{
	if (ll <= l && r <= rr) return SG[o];
	int m = (l+r)>>1, Ret = 0;
	if (ll <= m) Ret = max(Ret, SG_Query(lson, ll, rr));
	if (rr >  m) Ret = max(Ret, SG_Query(rson, ll, rr));
	return Ret;
}

int dep[N], siz[N], fa[N], son[N], val[N];
void DFS1(int v)
{
	siz[v] = 1; son[v] = 0;
	for (int i = Head[v]; i; i = e[i].Next)
	{
		int u = e[i].t;
		if (u == fa[v]) continue;
		e[i].s = e[i^1].s = u;
		fa[u] = v; dep[u] = dep[v] + 1; val[u] = e[i].v;
		DFS1(u); siz[v] += siz[u];
		if (siz[u] > siz[son[v]]) son[v] = u;
	}
}
int top[N], tid[N], DFN;
inline void Modify(const int p, const int v) {SG_Modify(1, 1, n, tid[p], v);}
void DFS2(int v, int t)
{
	top[v] = t; tid[v] = ++DFN; Modify(v, val[v]);
	if (son[v] == 0) return;
	DFS2(son[v], t);
	for (int i = Head[v]; i; i = e[i].Next)
	{
		int u = e[i].t;
		if (u == son[v] || u == fa[v]) continue;
		DFS2(u, u);
	}
}
inline int SG_Query(const int a, const int b) {return SG_Query(1, 1, n, tid[a], tid[b]);}
int Query(int a, int b)
{
	int Ret = 0;
	while (top[a] != top[b])
	{
		if (dep[top[a]] < dep[top[b]]) swap(a, b);
		int t = top[a];
		Ret = max(Ret, SG_Query(t, a));
		a = fa[t];
	}
	if (dep[a] > dep[b]) swap(a, b);
	if (a != b) Ret = max(Ret, SG_Query(son[a], b));
	return Ret;
}

int main()
{
	ios::sync_with_stdio(false);
	srand(19260817);
	
	int T;
	cin >> T;
	while (T--)
	{
		fill(Head, Head + N, 0);
		fill(SG, SG + MAXM, 0);
		DFN = 0;
		
		cin >> n;
		for (int i = 1, j = 2, a, b, c; i < n; i++)
		{
			cin >> a >> b >> c;
			AddEdge(a, b, c, j); AddEdge(b, a, c, j);
		}
		
		int r = rand() % n + 1;
		fa[r] = 0; dep[r] = 1; DFS1(r); DFS2(r, r);
		
		char s[7];
		while (true)
		{
			cin >> s;
			if (s[0] == 'D') break;
			int a, b;
			if (s[0] == 'C') {cin >> a >> b; Modify(e[a<<1].s, b);}
			else {cin >> a >> b; cout << Query(a, b) << endl;}
		}
	}
	
	return 0;
}

