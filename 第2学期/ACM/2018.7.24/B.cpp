#include <iostream>
#include <algorithm>
using namespace std;

const int N = 1007;
long long a[N];

int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		long long x;
		int n;
		cin >> x >> n;
		if (n == 1) {cout << x << endl; continue;}
	
		long long k = x/(2*(n-1)); fill(a, a+n, k*2); a[0] = a[n-1] = k; //x <= 1e18 n > 1 k <= 1e18
		x %= 2*(n-1);
		for (int i = 0; i < n-1; i++)
		{
			if (x == 0) break;
			a[i]++; x--;
		}
		for (int i = n-1; i > 0; i--)
		{
			if (x == 0) break;
			a[i]++; x--;
		}
		
		cout << a[0];
		for (int i = 1; i < n; i++) cout << ' ' << a[i];
		cout << endl;
	}
	
	return 0;
}

