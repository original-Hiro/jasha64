#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;

const int N = 207, INF = 200000007, M = 407;
struct Edge {int s, t, f, Next;} e[M];
int n, fa[N], d[N], Head[N], Cur[N], Num[N], Res;

void BFS()
{
	int v, i;
	queue<int> q;
	
	memset(d, 0, sizeof(d));
	q.push(n); d[n] = 0;
	while (!q.empty())
	{
		v = q.front(); q.pop();
		i = Head[v];
		while (i)
		{
			if (e[i].f > 0 && !d[e[i ^ 1].t] && e[i ^ 1].t != n)
			{
				++Num[d[e[i ^ 1].t] = d[e[i ^ 1].s] + 1];
				q.push(e[i ^ 1].t);
			}
			i = e[i].Next;
		}
	}
}
int Augment()
{
	int v = n, a = INF;
	
	while (v != 1)
	{
		a = min(e[fa[v]].f, a);
		v = e[fa[v]].s;
	}
	v = n;
	while (v != 1)
	{
		e[fa[v]].f -= a; e[fa[v] ^ 1].f += a;
		v = e[fa[v]].s;
	}
	
	return a;
}
void ISAP()
{
	int i, v = 1;
	
	BFS();
	copy(Head + 1, Head + n + 1, Cur + 1);
	
	while (d[1] < n)
	{
		if (v == n) {Res += Augment(); v = 1;}
		
		bool OK = false;
		i = Cur[v];
		while (i)
		{
			if (e[i].f > 0 && d[e[i].t] == d[v] - 1)
			{
				OK = true;
				fa[e[i].t] = i; Cur[v] = i;
				v = e[i].t;
				break;
			}
			i = e[i].Next;
		}
		if (!OK)
		{
			int c = n - 1;
			i = Head[v];
			while (i)
			{
				if (e[i].f > 0) c = min(c, d[e[i].t]);
				i = e[i].Next;
			}
			if (--Num[d[v]] == 0) break;
			++Num[d[v] = c + 1]; Cur[v] = Head[v];
			if (v != 1) v = e[fa[v]].s;
		}
	}
}

int main()
{
	int m, i;
	
	ios::sync_with_stdio(false);
	
	while (cin >> m >> n)
	{
		memset(Num, 0, sizeof(Num));
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
		
		ISAP();
		
		cout << Res << endl;
	}
	
	return 0;
}

