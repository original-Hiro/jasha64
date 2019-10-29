#include <fstream>
#include <algorithm>
using namespace std;

ifstream cin("message.in");
ofstream cout("message.out");
const int N = 57;
int a[N][N], f[N * 2][N][N];

int main()
{
	int m, n;
	int k, i, j;
	
	cin >> m >> n;
	for (i = 1; i <= m; i++)
		for (j = 1; j <= n; j++) cin >> a[i][j];
	n = max(m, n);
	
	for (k = 3; k < 2 * n; k++)
		for (i = 1; i < k - 1; i++)
			for (j = i + 1; j < k; j++)
			{
				f[k][i][j] = max(f[k][i][j], f[k - 1][i - 1][j - 1]);
				f[k][i][j] = max(f[k][i][j], f[k - 1][i - 1][j]);
				f[k][i][j] = max(f[k][i][j], f[k - 1][i][j - 1]);
				f[k][i][j] = max(f[k][i][j], f[k - 1][i][j]);
				f[k][i][j] += a[i][k - i] + a[j][k - j];
			}
	
	cout << f[2 * n - 1][n - 1][n] << endl;
	
	return 0;
}

