#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

const int N = 1607;
int n, m, k, a[N], Res, Head[N], Next[N * N];
bool v[N];

struct Edge
{
	int l, r, d;
	
	Edge() {}
	Edge(const int& a, const int& b, const int& c) {l = a; r = b; d = c;}
	friend bool operator < (const Edge& a, const Edge& b) {return a.d > b.d;}
} e[N * N];

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
			e[++k] = Edge(t, t + m, min(a[t], a[t + m]));
			Next[k] = Head[t]; Head[t] = k;
			q.push(t + m);
		}
		if (t % m != 3 && t + 1 < n * m)
		{
			e[++k] = Edge(t, t + 1, min(a[t], a[t + 1]));
			Next[k] = Head[t]; Head[t] = k;
			q.push(t + 1);
		}
	}
}
void Prim()
{
	int i;
	Edge t; 
	priority_queue<Edge> pq;
	
	v[0] = true;
	i = Head[0];
	while (i)
	{
		pq.push(e[i]);
 		i = Next[i];
	}
	while (!pq.empty())
	{
		t = pq.top(); pq.pop();
		if (!v[t.r])
		{
			Res += t.d;
			v[t.r] = true;
			i = Head[t.r];
			while (i)
			{
				pq.push(e[i]);
				i = Next[i];
			}
		}
	}
}

int main()
{
	int i, j;
	
	cin >> m >> n;
	for (i = 0; i < n; i++)
		for (j = 0; j < m; j++) cin >> a[i * m + j];
	
	BFS();
	Prim();
	
	cout << Res << endl;
	
	return 0;
}

