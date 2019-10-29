#include <iostream>
using namespace std;

int n;
int Pow(int m, int k)
{
	int c1 = 1, c2 = m;
	while (k > 0)
	{
		if (k & 1) c1 = c1 * c2 % n;
		c2 = c2 * c2 % n;
		k >>= 1;
	}
	return c1;
}

int main()
{
	int m, k, x;
	
	cin >> n >> m >> k >> x;
	
	cout << (x + m * Pow(10, k)) % n << endl;
	
	return 0;
}

