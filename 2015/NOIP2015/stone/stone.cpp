#include <iostream>
#include <cstdio>
using namespace std;

int n, m, a[50007];

bool Can(int Mid)
{
	int i, c = 0, r = 0;
	for (i = 0; i < n; ++i)
	{
		if (c + a[i] >= Mid) {c = 0; continue;}
		else {
			c += a[i]; ++r;
			if (r > m) return false;
		}
	}
	return true;
}

int main()
{
	freopen("stone.in", "r", stdin);
	freopen("stone.out", "w", stdout);
	
	int l, i;
	cin >> l >> n >> m;
	for (i = 0; i < n; ++i) scanf("%d", &a[i]);
	for (i = n - 1; i >= 0; --i) a[i] -= a[i - 1];
	
	int Low = 0, Mid, High = l;
	while (Low <= High)
	{
		Mid = (Low + High) >> 1;
		if (Can(Mid)) Low = Mid + 1;
		else High = Mid - 1;
	}
	
	cout << High << endl;
	
	return 0;
}

