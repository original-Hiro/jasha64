#include <iostream>
using namespace std;

typedef const int& int_;
const int N = 37;
int m, n, f[N][N], Match[N * N], G[N * N][5], Top[N * N], Res;
bool v[N * N], s[N][N];

inline void AddEdge(int_ x, int_ y)
{
	int p = f[x][y];
	if (x > 1 && !s[x - 1][y]) G[p][++Top[p]] = f[x - 1][y];
	if (x < m && !s[x + 1][y]) G[p][++Top[p]] = f[x + 1][y];
	if (y > 1 && !s[x][y - 1]) G[p][++Top[p]] = f[x][y - 1];
	if (y < n && !s[x][y + 1]) G[p][++Top[p]] = f[x][y + 1];
//	cout << f[x][y];
//	for (int i = 1; i <= 4; ++i)
//		if (G[p][i]) cout << ' ' << G[p][i];
//	cout << endl;
}
bool Calc(int_ x)
{
	for (int i = 1; i <= Top[x]; ++i)
		if (!v[G[x][i]])
		{
			v[G[x][i]] = true;
			if (!Match[G[x][i]] || Calc(Match[G[x][i]])) {Match[G[x][i]] = x; return true;}
		}
	return false;
}

int main()
{
	int k, x, y, t1 = 0, t2 = 0;
	
	cin >> m >> n >> k;
	for (int i = 0; i < k; ++i)
	{
		cin >> y >> x;
		s[x][y] = true;
	}
	if ((m * n - k) & 1) {cout << "NO" << endl; return 0;}
	
	for (x = 1; x <= m; ++x)
		for (y = 1; y <= n; ++y)
			if ((x + y) & 1) f[x][y] = ++t1;
			else f[x][y] = ++t2;
	for (x = 1; x <= m; ++x)
		for (y = 1; y <= n; ++y)
			if (!s[x][y] && ((x + y) & 1)) AddEdge(x, y);
	for (x = 1; x <= m * n; ++x)
	{
		fill(v + 1, v + n * m + 1, false);
		if (Calc(x)) ++Res;
	}
	
	if ((Res << 1) == m * n - k) cout << "YES" << endl;
	else cout << "NO" << endl;
	
	return 0;
}

