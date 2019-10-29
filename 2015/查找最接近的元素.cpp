#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

int a[100007];

int main()
{
	int n, i, q, k, j, m;
	
	cin >> n;
	for (i = 0; i < n; ++i) scanf("%d", &a[i]);
	cin >> q;
	while (q--)
	{
		cin >> k;
		
		i = 0; j = n - 1;
		while (i <= j)
		{
			m = (i + j) >> 1;
			if (a[m] == k) {i = m; break;}
			if (a[m] > k) j = m - 1;
			else i = m + 1;
		}
		
		if (j == -1 || abs(a[i] - k) < abs(a[j] - k)) cout << a[i] << endl;
		else cout << a[j] << endl;
	}
	
	return 0;
}

