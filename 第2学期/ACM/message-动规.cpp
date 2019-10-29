#include <iostream>
#include <algorithm>
using namespace std;

const int N = 51;
int a[N][N], f[N+N][N][N];

inline void Tension(int& a, int b) {if (a < b) a = b;}

int main()
{
	int m, n;
	
	cin >> m >> n;
	for (int i = 1; i <= m; i++)
		for (int j = 1; j <= n; j++) cin >> a[i][j];
	
	for (int k = 3; k < m+n; k++)
		for (int i = 2; i <= m && i < k; i++)
			for (int j = 1; j < i; j++)
			{
				Tension(f[k][i][j], f[k-1][i][j]);
				Tension(f[k][i][j], f[k-1][i-1][j-1]);
				Tension(f[k][i][j], f[k-1][i][j-1]);
				if (j+1 < i) Tension(f[k][i][j], f[k-1][i-1][j]);
				f[k][i][j] += a[i][k-i] + a[j][k-j];
			}
	f[n+m][m][m] = f[n+m-1][m][m-1];
	
	cout << f[n+m][m][m] << endl;
	
	return 0;
}

