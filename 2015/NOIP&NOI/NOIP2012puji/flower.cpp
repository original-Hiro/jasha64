#include <fstream>
#include <algorithm>
using namespace std;

ifstream cin("flower.in");
ofstream cout("flower.out");
const int MOD = 1000007, N = 107;
int a[N], n, m, f[N][N];

int main()
{
	int i, j, k;
	
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		 cin >> a[i];
		 if (!a[i]) {i--; n--;}
	}
	
	for (i = 1; i <= min(a[1], m); i++) f[1][i] = 1;
	for (i = 0; i <= n; i++) f[i][0] = 1;
	for (i = 2; i <= n; i++)
		for (j = 1; j <= m; j++)
			for (k = 0; k <= a[i]; k++)
			{
				if (j < k) break;
				f[i][j] = (f[i][j] + f[i - 1][j - k]) % MOD;
			}
	
	cout << f[n][m] % MOD << endl;
	
	return 0;
}

