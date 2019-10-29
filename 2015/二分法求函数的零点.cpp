#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

const double eps = 0.000001;
inline double f(double x) {return x*x*x*x*x - 15 * x*x*x*x + 85 * x*x*x - 225 * x*x + 274 * x - 121;}

int main()
{
	double i = 1.5, j = 2.4, m;
	
	do {
		m = (i + j) / 2.0;
		if (f(m) > 0) i = m;
		else j = m;
	} while (fabs(i - j) > eps);
	
	printf("%.6lf\n", m);
	
	return 0;
}

