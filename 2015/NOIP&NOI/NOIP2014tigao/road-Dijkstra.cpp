#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

const int N = 10007, INF = 200007;
int n, s, t;
int f[N];
bool done[N], can[N];
vector<int> G[N], C[N];
struct HeapNode
{
	int u, d;
	HeapNode(int a) {u = a; d = f[a];}
	friend bool operator < (const HeapNode& a, const HeapNode& b) {return a.d > b.d;}
};

inline void AddEdge(int from, int to)
{
	G[from].push_back(to);
	C[to].push_back(from);
}
void Sign()
{
	int i, u;
	queue<int> q;
	bool c[N];
	
	c[t] = true;
	q.push(t);
	while (!q.empty())
	{
		u = q.front(); q.pop();
		for (i = 0; i < C[u].size(); i++)
			if (!c[C[u][i]])
			{
				c[C[u][i]] = true;
				q.push(C[u][i]);
			}
	}
	copy(c + 1, c + n + 1, can + 1);
	for (i = 1; i <= n; i++)
		if (!can[i]) q.push(i);
	while (!q.empty())
	{
		u = q.front(); q.pop();
		for (i = 0; i < C[u].size(); i++)
			if (can[C[u][i]]) can[C[u][i]] = false;
	}
}
void Dijkstra()
{
	if (!can[t]) {f[t] = INF; return;}
	
	int i, u;
	priority_queue<HeapNode> q;
	
	fill(f + 1, f + s, INF);
	fill(f + s + 1, f + n + 1, INF);
	if (can[s]) q.push(HeapNode(s));
	while (!q.empty())
	{
		u = q.top().u; q.pop();
		if (done[u]) continue;
		done[u] = true;
		for (i = 0; i < G[u].size(); i++)
			if (can[G[u][i]] && f[u] + 1 < f[G[u][i]])
			{
				f[G[u][i]] = f[u] + 1;
				q.push(HeapNode(G[u][i]));
			}
	}
}

int main()
{
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	
	int m, l, r;
	int i;
	
	cin >> n >> m;
	for (i = 0; i < m; i++)
	{
		scanf("%d%d", &l, &r);
		AddEdge(l, r);
	}
	cin >> s >> t;
	
	Sign();
	Dijkstra();
	
	if (f[t] == INF) cout << -1 << endl;
	else cout << f[t] << endl;
	
	return 0;
}

