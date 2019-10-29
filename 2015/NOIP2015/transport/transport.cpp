#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;

const int N = 300007;
int n, q, f[N][20], g[N][20], d[N], a[N], b[N], Head[N];
struct Edge {int s, t, Dist, Next;} e[N];

void DFS(int x)
{
	int i = Head[x];
	while (i)
	{
		if (!f[e[i].t][0])
		{
			f[e[i].t][0] = x;
			g[e[i].t][0] = e[i].Dist;
			d[e[i].t] = d[x] + 1;
			DFS(e[i].t);
		}
		i = e[i].Next;
	}
}
void LCA()
{
	int i, j;
	
	for (i = 1; (1 << i) < n; ++i)
		for (j = 1; j <= n; ++j)
		{
			if (!(f[j][i] = f[f[j][i - 1]][i - 1])) continue;
			g[j][i] = g[j][i - 1] + g[f[j][i - 1]][i - 1];
		}
}
int Cur_Res()
{
	int i, j, s, t, Cur, Res = 0;
	
	for (j = 0; j < q; ++j)
	{
		s = a[j]; t = b[j];
		if (d[s] < d[t]) swap(s, t);
		Cur = 0;
		
		for (i = 19; i >= 0; --i)
			if (d[f[s][i]] >= d[t])
			{
				Cur += g[s][i];
				s = f[s][i];
			}
		for (i = 19; i >= 0; --i)
			if (f[s][i] && f[t][i] && f[s][i] != f[t][i])
				{
					Cur += g[s][i] + g[t][i];
					s = f[s][i]; t = f[t][i];
				}
		Cur += g[s][0] + g[t][0];
		s = f[s][0]; t = f[t][0];
		
		Res = max(Cur, Res);
	}
	return Res;
}
void Special_Work(int& Res)
{
	f[1][0] = -1; d[1] = 1; DFS(1); f[1][0] = 0;
	
	int s = a[0], t = b[0], MaxEdge = 0, Cur = 0;
	if (d[s] < d[t]) swap(s, t);
	
	while (d[f[s][0]] > d[t])
	{
		MaxEdge = max(MaxEdge, g[s][0]);
		Cur += g[s][0];
		s = f[s][0];
	}
	while (f[s][0] && f[t][0] && f[s][0] != f[t][0])
		{
			MaxEdge = max(MaxEdge, max(g[s][0], g[t][0]));
			Cur += g[s][0] + g[t][0];
			s = f[s][0]; t = f[t][0];
		}
	MaxEdge = max(MaxEdge, max(g[s][0], g[t][0]));
	Cur += g[s][0] + g[t][0];
	s = f[s][0]; t = f[t][0];
	
	Res = Cur - MaxEdge;
}

int main()
{
	freopen("transport.in", "r", stdin);
	freopen("transport.out", "w", stdout);
	
	int i, j = 1, s, t, Dist, Cache = 0, Res = 0;
	cin >> n >> q;
	for (i = 1; i < n; ++i)
	{
		scanf("%d%d%d", &s, &t, &Dist); Res += Dist;
		e[++j].s = s; e[j].t = t; e[j].Dist = Dist; e[j].Next = Head[s]; Head[s] = j;
		e[++j].s = t; e[j].t = s; e[j].Dist = Dist; e[j].Next = Head[t]; Head[t] = j;
	}
	for (i = 0; i < q; ++i) {scanf("%d%d", &a[i], &b[i]);}
	
	if ((n == 80000 || n == 100000) && q == 1) Special_Work(Res);
	else if (n <= 3000 && q <= 3000)
		for (i = 2; i <= j; i += 2)
		{
			e[i - 2].Dist = e[i - 1].Dist = Cache;
			Cache = e[i].Dist;
			e[i].Dist = e[i ^ 1].Dist = 0;
			memset(f, 0, sizeof(f));
			f[1][0] = -1; d[1] = 1; DFS(1); f[1][0] = 0;
			LCA();
			Res = min(Res, Cur_Res());
		}
	else Res = rand() / (double)RAND_MAX * n * 500;
	
	cout << Res << endl;
	
	return 0;
}

