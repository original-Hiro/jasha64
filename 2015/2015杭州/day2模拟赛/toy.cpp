#include <fstream>
#include <algorithm>
using namespace std;

ifstream cin("toy.in");
ofstream cout("toy.out");
const int N = 107, INF = 1000007;
int f[N][N];

int main()
{
	int n, m, i, l, r;
	cin >> n >> m;
	for (i = 1; i <= n; i++) fill(f[i] + 1, f[i] + n + 1, INF);
	for (i = 0; i < m; i++)
	{
		cin >> l >> r;
		f[l][r] = f[r][l] = 1;
	}
	
	int k, j;
	for (k = 1; k <= n; k++)
		for (i = 1; i <= n; i++)
			for (j = 1; j <= n; j++)
				f[i][j] = min(f[i][j], f[i][k] + f[k][j]);
	
	int Res = 0;
	for (i = 1; i <= n; i++)
		for (j = 1; j <= n; j++)
			if (f[i][j] != INF) Res = max(Res, f[i][j]);
	cout << Res << endl;
	
	return 0;
}

