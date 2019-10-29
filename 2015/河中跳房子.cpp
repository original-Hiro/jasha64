#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;

int a[50007];

int main()
{
	int n, m, i, High, Low = 1;
	cin >> High >> n >> m;
	for (i = 1; i <= n; ++i) scanf("%d", &a[i]);
	a[++n] = High;
	for (i = n; i > 0; --i) a[i] -= a[i - 1];
	
	int Mid, k, s;
	while (Low <= High)
	{
		Mid = (Low + High) >> 1;
		s = k = 0;
		for (i = 1; i <= n; ++i)
		{
			s += a[i];
			if (s < Mid) ++k;
			else s = 0;
		}
		if (k <= m) Low = Mid + 1;
		else High = Mid - 1;
	}
	
	cout << High << endl;
	
	return 0;
}

