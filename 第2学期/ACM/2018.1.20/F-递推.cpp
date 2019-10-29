//插空法，用f[i][j]表示前i种字符组成长度为j的串有多少种方案，则f[i][j] = (f[i][j] + f[i-1][j-k] * C(j, k)) % MOD
#include <iostream>
#include <cstring>
using namespace std;

const int N = 101, MOD = 1000000007;
int C[N*N][N], f[N*N];

int main()
{
	ios::sync_with_stdio(false);
	for (int i = 0; i < N*N; i++)
	{
		C[i][0] = 1;
		for (int j = 1; j <= i && j < N; j++) C[i][j] = (C[i-1][j-1] + C[i-1][j]) % MOD;
	}
	
	int n, kase = 0;
	while (cin >> n)
	{
		memset(f, 0, sizeof(f));
		
		int maxl = 0;
		f[0] = 1;
		for (int i = 1, a; i <= n; i++)
		{
			cin >> a;
			maxl += a;
			for (int j = maxl; j > 0; j--)
				for (int k = 1; k <= j && k <= a; k++) f[j] = (f[j] + (long long)f[j-k] * C[j][k]) % MOD;
		}
		
		int Res = 0;
		for (int i = 1; i <= maxl; i++) Res = (Res + f[i]) % MOD;
		cout << "Case " << ++kase << ": " << Res << endl;
	}
	
	return 0;
}

