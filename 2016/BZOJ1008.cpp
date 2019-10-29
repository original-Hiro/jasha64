#include <iostream>
using namespace std;

const int MOD = 100003;

long long Pow(long long a, long long b)
{
	if (!a && !b) return 0;
	long long c1 = a % MOD, c2 = 1;
	while (b)
	{
		if (b & 1) c2 = c2 * c1 % MOD;
		c1 = c1 * c1 % MOD;
		b >>= 1;
	}
	return c2;
}

int main()
{
	long long n, m;
	
	cin >> m >> n;
	
	cout << (Pow(m, n) - m % MOD * Pow(m - 1, n - 1) % MOD + MOD) % MOD << endl;
	
	return 0;
}

