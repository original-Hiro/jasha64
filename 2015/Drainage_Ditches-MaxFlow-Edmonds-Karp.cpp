#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;

const int N = 207, INF = 1000000007;
struct Edge {int s, t, c, f, Next;} e[407];
int n, Head[N], a[N], fa[N], Res;
void Edmonds_Karp()
{
	Res = 0;
	
	int v, i;
	
	while (true)
	{
		memset(a, 0, sizeof(a));
		queue<int> q;
		q.push(1); a[1] = INF;
		while (!q.empty())
		{
			v = q.front(); q.pop();
			i = Head[v];
			while (i)
			{
				if (!a[e[i].t] && e[i].c > e[i].f)
				{
					fa[e[i].t] = i;
					a[e[i].t] = min(a[v], e[i].c - e[i].f);
					q.push(e[i].t);
				}
				i = e[i].Next;
			}
			if (a[n]) break;
		}
		if (!a[n]) break;
		v = n;
		while (v != 1)
		{
			e[fa[v]].f += a[n]; e[fa[v] ^ 1].f -= a[n];
			v = e[fa[v]].s;
		}
		Res += a[n];
	}
}

int main()
{
	int m, i;
	
	while (cin >> m >> n)
	{
		Res = 0; m = (m << 1) + 1;
		
		for (i = 1; i <= n; ++i) Head[i] = 0;
		for (i = 2; i <= m; ++i)
		{
			cin >> e[i].s >> e[i].t >> e[i].c; e[i].f = 0;
			e[i].Next = Head[e[i].s]; Head[e[i].s] = i++;
			e[i].s = e[i - 1].t; e[i].t = e[i - 1].s; e[i].c = e[i].f = 0;
			e[i].Next = Head[e[i].s]; Head[e[i].s] = i;
		}
		
		Edmonds_Karp();
		
		cout << Res << endl;
	}
	
	return 0;
}

