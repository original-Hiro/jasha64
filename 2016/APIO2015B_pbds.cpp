#include <iostream>
#include <algorithm>
#include <set>
#include <ext/pb_ds/priority_queue.hpp>
using namespace std;

const int N = 30007, INF = 1073741823;
int n, d[N];
set<int> doge[N];
bool vis[N];
struct HeapNode
{
	int v;
	HeapNode(int a = 0) {v = a;}
	operator int () const {return v;}
	friend bool operator < (const HeapNode& a, const HeapNode& b) {return d[a] > d[b];}
};
typedef __gnu_pbds::priority_queue<HeapNode> Heap;

Heap pq;
Heap::point_iterator p[N];
inline void Update(int a, int b, int c)
{
	if (d[b] > d[a] + c) {d[b] = d[a] + c; pq.modify(p[b], HeapNode(b));}
}
int Dijkstra(int s, int t)
{
	d[s] = 0; vis[s] = 0;
	for (int i = 0; i < n; i++) p[i] = pq.push(HeapNode(i));
	while (!pq.empty())
	{
		int v = pq.top().v; pq.pop();
		if (d[v] == INF || v == t) break;
		if (vis[v]) continue;
		vis[v] = true;
		for (set<int>::iterator I = doge[v].begin(); I != doge[v].end(); I++)
		{
			int delta = *I;
			for (int j = v + delta, k = 1; j < n; j += delta, k++)
			{
				Update(v, j, k);
				if (doge[j].find(delta) != doge[j].end()) break;
			}
			for (int j = v - delta, k = 1; j >= 0; j -= delta, k++)
			{
				Update(v, j, k);
				if (doge[j].find(delta) != doge[j].end()) break;
			}
		}
	}
	
	return d[t] == INF ? -1 : d[t];
}

int main()
{
	ios::sync_with_stdio(false);
	fill(d, d + N, INF);
	
	int m, s, t;
	cin >> n >> m;
	for (int i = 0, a, b; i < m; i++)
	{
		cin >> a >> b;
		if (i == 0) s = a;
		else if (i == 1) t = a;
		doge[a].insert(b);
	}
	
	cout << Dijkstra(s, t) << endl;
	
	return 0;
}

