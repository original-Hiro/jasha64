#include <fstream>
#include <string>
using namespace std;

ifstream cin("substring.in");
ofstream cout("substring.out");
const long long MOD = 1000000007;
long long f[1007][207][207][2];
string s1, s2;

int main()
{
	int n, m, t, i, j, k;
	
	cin >> n >> m >> t >> s1 >> s2;
	
	for (i = 0; i <= n; ++i)
		for (k = 0; k <= i; ++k) f[i][0][k][0] = 1;
	for (i = 1; i <= n; ++i)
		for (j = 1; j <= i && j <= m; ++j)
			if (i >= 2 && j >= 2 && s1[i - 2] == s2[j - 2] && s1[i - 1] == s2[j - 1])
				for (k = 1; k <= i && k <= j; ++k)
				{
					f[i][j][k][0] = (f[i - 1][j][k][0] + f[i - 1][j][k][1]) % MOD;
					f[i][j][k][1] = (f[i - 1][j - 1][k - 1][0] + f[i - 1][j - 1][k - 1][1] + f[i - 1][j - 1][k][1]) % MOD;
				}
			else if (s1[i - 1] == s2[j - 1])
				for (k = 1; k <= i && k <= j; ++k)
				{
					f[i][j][k][0] = (f[i - 1][j][k][0] + f[i - 1][j][k][1]) % MOD;
					f[i][j][k][1] = (f[i - 1][j - 1][k - 1][0] + f[i - 1][j - 1][k - 1][1]) % MOD;
				}
			else for (k = 1; k <= i && k <= j; ++k)
				{
					f[i][j][k][0] = f[i - 1][j][k][0] + f[i - 1][j][k][1];
					f[i][j][k][1] = 0;
				}
	
	cout << (f[n][m][t][0] + f[n][m][t][1]) % MOD << endl;
	
	return 0;
}

