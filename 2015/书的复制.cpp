#include <iostream>
#include <cstring>
using namespace std;

const int N = 107;
int f[N][N][N], fa[N][N][N];

int main()
{
	int n, t, k, i, j;
	
	memset(f, 0x3fffffff, sizeof(f));
	cin >> n >> t;
	for (i = 1; i <= n; ++i) cin >> f[1][i][i];
	
	for (i = 1; i < n; ++i)
		for (j = i + 1; j <= n; ++j) f[1][i][j] = f[1][i][j - 1] + f[1][j][j];
	for (k = 2; k <= t; ++k)
	{
		
	}
	
	for (i = t - 1; i > 0; --i)
	{
		
	}
	
	return 0;
}

