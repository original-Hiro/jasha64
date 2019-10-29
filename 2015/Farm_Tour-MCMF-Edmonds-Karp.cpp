#include <iostream>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 1007, INF = 350000007;
struct Edge {int s, t, d, c, f, Next;} e[40007];
int Head[N], Cost, n, f[N], fa[N], a[N];
bool inq[N];

bool SPFA()
{
	int v, i;
	queue<int> q;
	
	memset(inq, 0, sizeof(inq)); fill(f, f + N, INF);
	q.push(1); inq[1] = true; fa[1] = f[1] = 0; a[1] = INF;
	
	while (!q.empty())
	{
		v = q.front(); q.pop(); inq[v] = false;
		i = Head[v];
		while (i)
		{
			if (e[i].f < e[i].c && f[v] + e[i].d < f[e[i].t])
			{
				f[e[i].t] = f[v] + e[i].d;
				fa[e[i].t] = i;
				a[e[i].t] = min(a[v], e[i].c - e[i].f);
				if (!inq[e[i].t]) {q.push(e[i].t); inq[e[i].t] = true;}
			}
			i = e[i].Next;
		}
	}
	
	return f[n] != INF;
}
inline void Edmonds_Karp()
{
	while (SPFA())
	{
		Cost += a[n] * f[n];
		int i = n;
		while (i != 1)
		{
			e[fa[i]].f += a[n]; e[fa[i] ^ 1].f -= a[n];
			i = e[fa[i]].s;
		}
	}
}

int main()
{
	int m, i;
	
	cin >> n >> m; ++n; m = m << 2 | 1; m += 4;
	e[2].s = 0; e[2].t = 1; e[2].c = 2; Head[0] = 2;
	e[3].s = 1; Head[1] = 3;
	e[4].s = n - 1; e[4].t = n; e[4].c = 2;  e[4].Next = Head[n - 1]; Head[n - 1] = 4;
	e[5].s = n; e[5].t = n - 1; Head[n] = 5; 
	for (i = 6; i <= m; ++i)
	{
		cin >> e[i].s >> e[i].t >> e[i].d; e[i].c = 1;
		e[i].Next = Head[e[i].s]; Head[e[i].s] = i; ++i;
		e[i].s = e[i ^ 1].t; e[i].t = e[i ^ 1].s; e[i].d = -e[i ^ 1].d;
		e[i].Next = Head[e[i].s]; Head[e[i].s] = i; ++i;
		e[i].s = e[i - 1].s; e[i].t = e[i - 1].t; e[i].d = -e[i - 1].d; e[i].c = 1;
		e[i].Next = Head[e[i].s]; Head[e[i].s] = i; ++i;
		e[i].s = e[i ^ 1].t; e[i].t = e[i ^ 1].s; e[i].d = -e[i ^ 1].d;
		e[i].Next = Head[e[i].s]; Head[e[i].s] = i;
	}
	
	Edmonds_Karp();
	
	cout << Cost << endl;
	
	return 0;
}

