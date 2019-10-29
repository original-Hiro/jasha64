#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

const double eps = 0.000001;
inline double Abs(double x) {return x < 0 ? -x : x;}

int main()
{
	double l1, l2, c1, c2;
	cin >> l1 >> c1 >> c2;
	l2 = (1 + c1 * c2) * l1;
	l1 /= 2.0; l2 /= 2.0;
	
	double Low = l1, Mid, High = 1e+30, a1, a2;
	while (Abs(Low - High) > eps)
	{
		Mid = (Low + High) / 2.0;
		a1 = sin(l2 / Mid);
		a2 = l1 / Mid;
		if (a1 > a2) High = Mid - eps;
		else Low = Mid + eps;
	}
	
	cout << setiosflags(ios::fixed) << setprecision(3)
	<< Low - sqrt(Low * Low - l1 * l1) << endl;
	
	return 0;
}

