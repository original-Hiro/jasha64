#include <iostream>
#include <algorithm>
using namespace std;

const int MOD = 1000007, N = 107;
int a[N], f[N][N];

int main()
{
	int n, m;
	int i, j, k;
	
	cin >> n >> m;
	for (i = 1; i <= n; i++) cin >> a[i];
	
	fill(f[1], f[1] + min(a[1], m) + 1, 1);
	for (i = 2; i <= n; i++)
		for (j = 0; j <= a[i]; j++)
			for (k = 0; k + j <= m; k++)
				f[i][k + j] = (f[i][k + j] + f[i - 1][k]) % MOD;
	
	cout << f[n][m] << endl;
	
	return 0;
}

