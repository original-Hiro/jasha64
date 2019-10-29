#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;

const int N = 207, INF = N;
struct Edge {int s, t, f, Next;} e[N << 1];
int Head[N], a[N], d[N], n, m, Res;

void Push_Relabel()
{
	int v, i, c;
	bool Done, Relabel;
	queue<int> q;
	
	Res = 0;
	memset(a, 0, sizeof(a));
	memset(d, 0, sizeof(d));
	d[1] = n;
	
	i = Head[1];
	while (i)
	{
		if (e[i].f > 0)
		{
			a[e[i].t] += e[i].f; a[1] -= e[i].f;
			e[i ^ 1].f = e[i].f; e[i].f = 0;
		}
		i = e[i].Next;
	}
	
	do {
		Done = true;
		for (v = 2; v < n; ++v)
			if (a[v] > 0)
			{
				c = INF;
				i = Head[v];
				while (i)
				{
					if (e[i].f > 0) c = min(c, d[e[i].t]);
					i = e[i].Next;
				}
				if (c == INF) continue;
				Done = false; d[v] = c + 1;
				i = Head[v];
				while (i)
				{
					if (e[i].f > 0 && d[e[i].t] == d[v] - 1)
					{
						c = min(e[i].f, a[v]);
						e[i].f -= c; e[i ^ 1].f += c;
						a[v] -= c; a[e[i].t] += c;
					}
					if (a[v] == 0) break;
					i = e[i].Next;
				}
			}
	} while (!Done);
	
	Res = a[n];
}

int main()
{
	int i;
	
	while (cin >> m >> n)
	{
		memset(Head, 0, sizeof(Head));
		
		m = m << 1 | 1;
		for (i = 2; i <= m; ++i)
		{
			cin >> e[i].s >> e[i].t >> e[i].f;
			e[i].Next = Head[e[i].s]; Head[e[i].s] = i; ++i;
			e[i].s = e[i ^ 1].t; e[i].t = e[i ^ 1].s; e[i].f = 0;
			e[i].Next = Head[e[i].s]; Head[e[i].s] = i;
		}
		
		Push_Relabel();
		
		cout << Res << endl;
	}
	
	return 0;
}

