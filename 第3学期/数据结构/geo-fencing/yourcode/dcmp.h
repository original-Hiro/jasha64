#pragma once
#include <cmath>
const double eps = 1e-8;
inline int dcmp(double x)
{
	if (fabs(x) < eps) return 0;
	return x < 0 ? -1 : 1;
}

