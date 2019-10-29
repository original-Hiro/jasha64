#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;

const int N = 207, INF = 200000007, M = 407;
struct Edge {int s, t, f, Next;} e[M];
int n, a[N], fa[N], d[N], Head[N], Cur[N], Res;

bool BFS()
{
	int v, i;
	queue<int> q;
	
	memset(d, 0, sizeof(d));
	q.push(1); d[1] = 0;
	while (!q.empty())
	{
		v = q.front(); q.pop();
		i = Head[v];
		while (i)
		{
			if (e[i].f > 0 && !d[e[i].t] && e[i].t != 1)
			{
				d[e[i].t] = d[e[i].s] + 1;
				fa[e[i].t] = i;
				q.push(e[i].t);
			}
			i = e[i].Next;
		}
	}
	
	return d[n];
}
int DFS(int v, int a)
{
	if (v == n || a == 0) return a;
	
	int &i = Cur[v], Flow = 0, f;
	while (i)
	{
		if (d[e[i].t] == d[v] + 1 && (f = DFS(e[i].t, min(a, e[i].f))) > 0)
		{
			e[i].f -= f; e[i ^ 1].f += f;
			Flow += f; a -= f;
			if (a == 0) break;
		}
		i = e[i].Next;
	}
	
	return Flow;
}
void Dinic()
{
	int i;
	while (BFS())
	{
		for (i = 1; i <= n; ++i) Cur[i] = Head[i];
		Res += DFS(1, INF);
	}
}

int main()
{
	int m, i;
	
	ios::sync_with_stdio(false);
	
	while (cin >> m >> n)
	{
		memset(Head, 0, sizeof(Head));
		Res = 0;
		
		m = m << 1 | 1;
		for (i = 2; i <= m; ++i)
		{
			cin >> e[i].s >> e[i].t >> e[i].f;
			e[i].Next = Head[e[i].s]; Head[e[i].s] = i; ++i;
			e[i].s = e[i ^ 1].t; e[i].t = e[i ^ 1].s;
			e[i].Next = Head[e[i].s]; Head[e[i].s] = i;
		}
		
		Dinic();
		
		cout << Res << endl;
	}
	
	return 0;
}

