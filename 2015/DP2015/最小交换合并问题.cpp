#include <iostream>
#include <algorithm>
using namespace std;

const int N = 107, INF = 20000007;
int a[N], c[N], f[N][N];

int main()
{
	int n, k, i, j, p, Res;
	
	cin >> n;
	for (i = 1; i <= n; ++i) cin >> a[i];
	
	fill(f[0], f[0] + N * N, INF);
	for (i = 1; i < n; ++i) {f[i][i] = a[i]; f[i][i + 1] = a[i] + a[i + 1];}
	f[n][n] = a[n];
	for (k = 2; k < n; ++k)
		for (i = 1; i + k <= n; ++i)
		{
			f[i][i + k] = f[i][i] + (f[i + 1][i + k] << 1);
			for (j = i + 1; j < i + k - 1; ++j)
				f[i][i + k] = min(f[i][i + k],
				max(f[i][j], f[j + 1][i + k]) + (min(f[j + 1][i + k], f[i][j]) << 1));
			f[i][i + k] = min(f[i][i + k], (f[i][i + k - 1] << 1) + f[i + k][i + k]);
		}
	Res = f[1][n];
	for (p = 1; p < n; ++p)
	{
		copy(a + 1, a + n + 1, c + 1);
		swap(c[p], c[p + 1]);
		fill(f[0], f[0] + N * N, INF);
		for (i = 1; i < n; ++i) {f[i][i] = c[i]; f[i][i + 1] = c[i] + c[i + 1];}
		f[n][n] = c[n];
		for (k = 2; k < n; ++k)
			for (i = 1; i + k <= n; ++i)
			{
				f[i][i + k] = f[i][i] + (f[i + 1][i + k] << 1);
				for (j = i + 1; j < i + k - 1; ++j)
					f[i][i + k] = min(f[i][i + k],
					max(f[i][j], f[j + 1][i + k]) + (min(f[j + 1][i + k], f[i][j]) << 1));
				f[i][i + k] = min(f[i][i + k], (f[i][i + k - 1] << 1) + f[i + k][i + k]);
			}
		Res = min(Res, f[1][n]);
	}
	
	cout << Res << endl;
	
	return 0;
}

