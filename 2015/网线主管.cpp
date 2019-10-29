#include <iostream>
#include <iomanip>
#include <algorithm>
using namespace std;

int a[10007];

int main()
{
	int i, n, k, High = 0;
	double c;
	cin >> n >> k;
	for (i = 0; i < n; ++i)
	{
		cin >> c; c *= 100;
		High = max(High, a[i] = c);
	}
	
	int Num, Low = 1, Mid;
	while (Low <= High)
	{
		Num = 0;
		Mid = (Low + High) >> 1;
		for (i = 0; i < n; ++i) Num += a[i] / Mid;
		if (Num >= k) Low = Mid + 1;
		if (Num < k) High = Mid - 1;
	}
	
	cout << setiosflags(ios::fixed) << setprecision(2) << High / 100.00 << endl;
	
	return 0;
}

