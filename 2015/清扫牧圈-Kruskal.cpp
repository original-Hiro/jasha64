#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

const int N = 1607;
int n, m, k, a[N], f[N], Res;

struct Edge
{
	int l, r, d;
	
	Edge() {}
	Edge(const int& a, const int& b, const int& c) {l = a; r = b; d = c;}
	friend bool operator < (const Edge& a, const Edge& b) {return a.d < b.d;}
} e[N * N];

int Find(const int& x)
{
	if (f[x] != x) return f[x] = Find(f[x]);
	return x;
}
void BFS()
{
	int t;
	queue<int> q;
	
	q.push(0);
	while (!q.empty())
	{
		t = q.front(); q.pop();
		if (t + m < n * m)
		{
			e[k++] = Edge(t, t + m, min(a[t], a[t + m]));
			q.push(t + m);
		}
		if (t % m != 3 && t + 1 < n * m)
		{
			e[k++] = Edge(t, t + 1, min(a[t], a[t + 1]));
			q.push(t + 1);
		}
	}
}
void Kruskal()
{
	sort(e, e + k);
	int i;
	for (i = 0; i < n * m; i++) f[i] = i;
	for (i = 0; i < k; i++)
		if (Find(e[i].l) != Find(e[i].r))
		{
			f[Find(e[i].l)] = Find(e[i].r);
			Res += e[i].d;
		}
}

int main()
{
	int i, j;
	
	cin >> m >> n;
	for (i = 0; i < n; i++)
		for (j = 0; j < m; j++) cin >> a[i * m + j];
	
	BFS();
	Kruskal();
	
	cout << Res << endl;
	
	return 0;
}

