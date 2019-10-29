#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int a[100007];

int main()
{
	int n, p, i, j, m, c, k;
	
	cin >> n;
	for (i = 0; i < n; ++i) scanf("%d", &a[i]);
	cin >> p;
	
	sort(a, a + n);
	for (i = 0; i < n; ++i)
	{
		c = p - a[i];
		j = n - 1;
		k = i + 1;
		while (k <= j)
		{
			m = (k + j) >> 1;
			if (a[m] == c) {cout << a[i] << ' ' << a[m] << endl; return 0;}
			if (a[m] > c) j = m - 1;
			else k = m + 1;
		}
	}
	
	cout << "No" << endl;
	
	return 0;
}

