#include <iostream>
using namespace std;

const long long MOD = 998244353;
typedef const int& int_;
long long f[307][307], c[607][607], x;

inline long long Next_Random() {return (x = (100000005 * x + 20150823) % MOD) / 100;}
long long C(int_ n, int_ k)
{
	if (c[n][k]) return c[n][k];
	c[n][0] = 1;
	for (int i = 1; i <= n; i++) c[n][i] = c[n][i - 1] * (n - i + 1) / i % MOD;
	return c[n][k];
}

int main()
{
	int i, j;
	long long n, m, q, v, u, k;
	
	cin >> n >> m >> q >> x;
	
	while (q--)
	{
		v = Next_Random() % n + 1;
		u = Next_Random() % m + 1;
		k = Next_Random() % (n + m - v - u + 1);
		for (i = 0; v + i <= n; ++i)
			for (j = k; u - i + j <= m; ++j)
			{
				if (u - i + j <= 0) continue;
				f[v + i][u - i + j] = (f[v + i][u - i + j] + C(j, i)) % MOD;
			}
	}
	
	for (i = 1; i <= n; ++i)
	{
		cout << f[i][1];
		for (j = 2; j <= m; ++j) cout << ' ' << f[i][j];
		cout << endl;
	}
	
	return 0;
} 

