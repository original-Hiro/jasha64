#include <iostream>
#include <cstdio>
using namespace std;

int a[100007];

int main()
{
	int n, m, i, Low = 0, High = 0;
	cin >> n >> m;
	for (i = 1; i <= n; ++i) {scanf("%d", &a[i]); Low = max(Low, a[i]); High += a[i];}
	
	int j, c, Mid;
	while (Low <= High)
	{
		j = c = 0;
		Mid = (Low + High) >> 1;
		for (i = 1; i <= n; ++i)
		{
			if (c + a[i] > Mid) {++j; c = 0;}
			c += a[i];
		}
		if ((++j) <= m) High = Mid - 1;
		else Low = Mid + 1;
	}
	
	cout << Low << endl;
	
	return 0;
}

