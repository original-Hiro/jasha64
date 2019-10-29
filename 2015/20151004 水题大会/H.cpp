#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

inline bool isp(int x)
{
	int i, l = sqrt(x);
	for (i = 2; i <= l; ++i)
		if (x % i == 0) return false;
}

int main()
{
	int T, n, i, l;
	
	cin >> T;
	while (T--)
	{
		cin >> n;
		
		if (n == 1 || n == 2 || n == 3) {cout << "No" << endl; continue;}
		l = sqrt(n);
		for (i = 2; i <= l; ++i)
			if (n % i == 0)
			{
				if (isp(i) && isp(n / i)) cout << "Yes" << endl;
				else cout << "No" << endl;
				break;
			}
	}
	
	return 0;
}

