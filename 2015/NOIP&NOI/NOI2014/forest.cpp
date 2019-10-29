#include <iostream>
#include <vector>
using namespace std;

const long long N = 50007, INF = 5000000007;
struct Edge
{
	long long to, a, b;
	Edge(const int& To, const int& A, const int& B) {to = To; a = A; b = B;}
};
long long fa[N], fb[N];
vector<Edge> Next[N];
bool v[N];

int main()
{
	long long n, m, l, r, a, b;
	long long i, j, pos;
	
	cin >> n >> m;
	for (i = 0; i < m; i++)
	{
		cin >> l >> r >> a >> b;
		Next[l].push_back(Edge(r, a, b));
		Next[r].push_back(Edge(l, a, b));
	}
	
	fill(fa + 2, fa + n + 2, INF);
	fill(fb + 2, fb + n + 2, INF);
	for (i = 0; i < n; i++)
	{
		pos = n + 1;
		for (j = 1; j <= n; j++)
			if (!v[j] && fa[j] + fb[j] < fa[pos] + fb[pos]) pos = j;
		v[pos] = 1;
		for (j = 0; j < Next[pos].size(); j++)
			if (min(fb[Next[pos][j].to], max(fb[pos], Next[pos][j].b)) +
			min(fa[Next[pos][j].to], max(fa[pos], Next[pos][j].a)) <
			fa[Next[pos][j].to] + fb[Next[pos][j].to])
			{
				fa[Next[pos][j].to] = min(fa[Next[pos][j].to], max(fa[pos], Next[pos][j].a));
				fb[Next[pos][j].to] = min(fb[Next[pos][j].to], max(fb[pos], Next[pos][j].b));
			}
	}
	
	if (fa[n] == INF || fb[n] == INF) cout << -1 << endl;
	else cout << fa[n] + fb[n] << endl;
	
	return 0;
}

