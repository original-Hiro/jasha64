#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	long long T, x, x1, x2, i;
	
	cin >> T;
	while (T--)
	{
		cin >> x1 >> x2;
		x = x1 * x2;
		
		for (i = (long long)sqrt(x) - (long long)sqrt(x) % x1;; i -= x1)
			if (x % i == 0 && i % x1 == 0) {cout << i + x / i << ' '; break;}
		for (i = x1;; i += x1)
			if (x % i == 0 && i % x1 == 0) {cout << i + x / i << ' '; break;}
	}
	
	return 0;
}

