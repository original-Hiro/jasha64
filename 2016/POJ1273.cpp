#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

const int N = 207, INF = 2147483647;
struct Edge {int t, f, Next;} e[N << 1];
int n, Res, Cur[N], Head[N], d[N];

bool BFS()
{
	queue<int> q;
	
	fill(d, d + N, 0);
	d[1] = 1; q.push(1);
	while (!q.empty())
	{
		int v = q.front(); q.pop();
		for (int i = Head[v]; i; i = e[i].Next)
		{
			int u = e[i].t;
			if (e[i].f && !d[u])
			{
				d[u] = d[v] + 1;
				q.push(u);
			}
		}
	}
	
	return d[n];
}
int DFS(int v, int a)
{
	if (v == n || a == 0) return a;
	
	int Ret = 0, f;
	for (int& i = Cur[v]; i; i = e[i].Next)
	{
		int u = e[i].t;
		if (d[u] != d[v] + 1 || !e[i].f) continue;
		f = DFS(u, min(a, e[i].f));
		e[i].f -= f; e[i ^ 1].f += f;
		a -= f; Ret += f;
		if (!a) break;
	}
	
	return Ret;
}
void Dinic()
{
	while (BFS())
	{
		copy(Head, Head + N, Cur);
		Res += DFS(1, INF);
	}
}
inline void AddEdge(int a, int b, int f, int& t)
{
	e[t].t = b; e[t].f = f; e[t].Next = Head[a]; Head[a] = t++;
	e[t].t = a; e[t].f = 0; e[t].Next = Head[b]; Head[b] = t++;
}

int main()
{
	int m;
	
	while (cin >> m >> n)
	{
		fill(Head, Head + N, 0);
		Res = 0;
		
		for (int i = 1, j = 2, a, b, f; i <= m; i++)
		{
			cin >> a >> b >> f;
			AddEdge(a, b, f, j);
		}
		
		Dinic();
		
		cout << Res << endl;
	}
	
	return 0;
}

