#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <ctime>
using namespace std;

const int N = 50007;
struct Edge {int s, t, Next;} e[N << 1];
struct SLPF
{
	int siz, son, dep, fa;
	int top, tid, rk;
} f[N];
int Head[N], SG[N << 2], a[N], v, M = 1, DFN;

void DFS1(int x, int fa, int d)
{
	f[x].siz = 1; f[x].dep = d; f[x].fa = fa;
	int i = Head[x];
	while (i)
	{
		int v = e[i].t;
		if (v == fa) {i = e[i].Next; continue;}
		DFS1(v, x, d + 1);
		f[x].siz += f[v].siz;
		if (f[v].siz > f[f[x].son].siz) f[x].son = v;
		i = e[i].Next;
	}
}
void DFS2(int x, int top)
{
	f[x].top = top; f[f[x].tid = ++DFN].rk = x;
	if (!f[x].son) return;
	DFS2(f[x].son, top);
	int i = Head[x];
	while (i)
	{
		int v = e[i].t;
		if (v == f[x].son || v == f[x].fa) {i = e[i].Next; continue;}
		DFS2(v, v);
		i = e[i].Next;
	}
}
int SG_Query(int x)
{
	int r = SG[x += M];
	while (x > 1) r += SG[x >>= 1];
	return r;
}
void SG_Modify(int l, int r)
{
	l += M - 1; r += M + 1;
	while (abs(l - r) > 1)
	{
		if (~l & 1) SG[l ^ 1] += v;
		if ( r & 1) SG[r ^ 1] += v;
		l >>= 1; r >>= 1;
	}
}
inline int Query(int x) {return SG_Query(f[x].tid);}
void Modify(int x, int y)
{
	while (f[x].top != f[y].top)
	{
		if (f[f[x].top].dep < f[f[y].top].dep) swap(x, y);
		int F = f[x].top;
		SG_Modify(f[F].tid, f[x].tid);
		x = f[F].fa;
	}
	if (f[x].dep > f[y].dep) swap(x, y);
	SG_Modify(f[x].tid, f[y].tid);
}

int main()
{
	int n, m, q;
	while (scanf("%d%d%d", &n, &m, &q) == 3)
	{
		M = 1; DFN = 0;
		memset(Head, 0, sizeof(Head));
		memset(SG, 0, sizeof(SG));
		for (int i = 1; i <= n; i++) f[i].son = 0;
		
		while (M <= (n + 1)) M <<= 1;
		for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
		for (int i = 1, j = 2; i <= m; i++)
		{
			scanf("%d%d", &e[j].s, &e[j].t);
			e[j].Next = Head[e[j].s]; Head[e[j].s] = j; ++j;
			e[j].s = e[j ^ 1].t; e[j].t = e[j ^ 1].s;
			e[j].Next = Head[e[j].s]; Head[e[j].s] = j; ++j;
		}
		
		srand(time(NULL));
		int r = rand() % n + 1;
		DFS1(r, 0, 1); DFS2(r, r);
		for (int i = 1; i <= n; i++) {v = a[i]; Modify(i, i);}
		
		int a, b;
		char argv;
		while (q--)
		{
			scanf(" %c", &argv);
			if (argv == 'I') {scanf("%d%d%d", &a, &b, &v); Modify(a, b);}
			else if (argv == 'D') {scanf("%d%d%d", &a, &b, &v); v = -v; Modify(a, b);}
			else {scanf("%d", &a); printf("%d\n", Query(a));}
		}
	}
	
	return 0;
}

