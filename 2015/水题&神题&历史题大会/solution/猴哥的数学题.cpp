#include <iostream>
using namespace std;

const int MOD = 2014;

int Pow(int a, int b)
{
	if (!b) return 1;
	int c1 = a % MOD, c2 = 1;
	while (b > 1)
	{
		if (b & 1) c2 = c2 * c1 % MOD;
		c1 = c1 * c1 % MOD;
		b >>= 1;
	}
	return c1 * c2 % MOD;
}

int main()
{
	int a, b;
	
	cin >> a >> b;
	
	cout << Pow(a, b) << endl;
	
	return 0;
}

