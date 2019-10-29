#include <iostream>
#include <algorithm>
using namespace std;

const int N = 107;
int a[N], c[N], f[N][N >> 1];

int main()
{
	int n, k, i, j;
	
	cin >> n >> k; k += 3;
	if (n < (k << 1)) {cout << -1 << endl; return 0;}
	for (i = 1; i <= n; ++i) cin >> a[i];
	sort(a + 1, a + n + 1);
	for (i = 2; i <= n; ++i) c[i] = (a[i] - a[i - 1]) * (a[i] - a[i - 1]);
	
	f[2][1] = c[2];
	for (i = 3; i <= n; ++i)
		for (j = 1; j <= (i >> 1); ++j)
		{
			f[i][j] = f[i - 2][j - 1] + c[i];
			if ((i & 1) || j < (i >> 1)) f[i][j] = min(f[i][j], f[i - 1][j]);
		}
	
	cout << f[n][k] << endl;
	
	return 0;
}

