#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

const double eps = 0.000001;
int v[10007];

int main()
{
	int i, n, k, r;
	double High = 0;
	cin >> n >> k; ++k;
	for (i = 0; i < n; ++i) {cin >> r; High = max(High, (double)(v[i] = r * r));}
	
	int Num;
	double Low = 0, Mid;
	while (Low <= High)
	{
		Num = 0;
		Mid = (Low + High) / 2.0;
		for (i = 0; i < n; ++i) Num += v[i] / Mid;
		if (Num >= k) Low = Mid + eps;
		if (Num < k) High = Mid - eps;
	}
	
	cout << setiosflags(ios::fixed) << setprecision(3) << High * atan2(0, -1) << endl;
	
	return 0;
}

