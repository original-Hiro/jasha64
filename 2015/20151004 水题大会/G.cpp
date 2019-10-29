#include <iostream>
using namespace std;

long long a, b, c;
long long Pow()
{
	if (!b) return 1 % c;
	long long c1 = a % c, c2 = 1;
	while (b > 1)
	{
		if (b & 1) c2 = c2 * c1 % c;
		c1 = c1 * c1 % c;
		b >>= 1;
	}
	return c1 * c2 % c;
}

int main()
{
	cin >> a >> b >> c;
	
	cout << Pow() << endl;
	
	return 0;
}

