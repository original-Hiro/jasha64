#include <iostream>
#include <algorithm>
using namespace std;

const int N = 101;
int f[N][N];

int main()
{
	int n, m, i, j, k;
	
	for (i = 1; i < N; ++i) f[i][1] = i;
	for (i = 1; i < N; ++i)
		for (j = 2; j < N; ++j)
		{
			f[i][j] = max(f[0][j - 1], f[i - 1][j]) + 1;
			for (k = 1; k <= i; ++k)
				f[i][j] = min(f[i][j], max(f[k - 1][j - 1], f[i - k][j]) + 1);
		}
	
	while (cin >> n >> m) cout << f[n][m] << endl;
	
	return 0;
}

