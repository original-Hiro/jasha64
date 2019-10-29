#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;

const int N = 1007, INF = -1 << 31;
int a[N][N], f[2][N], s[2][N], g[2], c[N];

int main()
{
	int n, m, p, t, i, j, k, Res;
	
	cin >> n >> m >> p;
	for (i = 1; i <= n; ++i)
		for (j = 1; j <= m; ++j) scanf("%d", &a[j][i]);
	for (i = 1; i <= n; ++i) cin >> c[i];
	
	fill(s[0] + 1, s[0] + n + 1, p);
	for (t = 1; t <= m; ++t)
	{
		i = t & 1;
		f[i][1] = g[i ^ 1] + a[t][n] - c[n];
		s[i][1] = 1;
		for (k = 2; k <= n; ++k)
		{
			f[i][k] = g[i ^ 1] + a[t][k - 1] - c[k - 1];
			s[i][k] = 1;
		}
		if (s[i ^ 1][n] < p && f[i ^ 1][n] + a[t][n] > f[i][1])
		{
			f[i][1] = f[i ^ 1][n] + a[t][n];
			s[i][1] = s[i ^ 1][n] + 1;
		}
		for (k = 2; k <= n; ++k)
			if (s[i ^ 1][k - 1] < p && f[i ^ 1][k - 1] + a[t][k - 1] > f[i][k])
			{
				f[i][k] = f[i ^ 1][k - 1] + a[t][k - 1];
				s[i][k] = s[i ^ 1][k - 1] + 1;
			}
		g[i] = f[i][1];
		for (k = 2; k <= n; ++k) g[i] = max(g[i], f[i][k]);
	}
	
	m &= 1; Res = f[m][1];
	for (i = 1; i <= n; ++i) Res = max(Res, f[m][i]);
	cout << Res << endl;
	
	return 0;
}

