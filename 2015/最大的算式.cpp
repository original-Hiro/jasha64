#include <iostream>
#include <algorithm>
using namespace std;

const int N = 17;
int a[N], f[N][N][N];

int main()
{
	int n, m;
	int i, j;
	
	cin >> n >> m;
	for (i = 1; i <= n; i++) cin >> a[i];
	
	f[1][0][0] = a[1];
	f[2][1][0] = a[1] + a[2];
	f[2][0][1] = a[1] * a[2];
	for (i = 3; i <= n; i++)
	{
		f[i][0][i - 1] = f[i - 1][0][i - 2] * a[i];
		f[i][i - 1][0] = f[i - 1][i - 2][0] + a[i];
		for (j = 1; j < i && j <= m; j++)
			f[i][i - j - 1][j] = max(f[i - 1][i - j - 1][j - 1] * a[i], f[i - 1][i - j - 2][j] + a[i]);
	}
	
	cout << f[n][n - m - 1][m] << endl;
	
	return 0;
}

