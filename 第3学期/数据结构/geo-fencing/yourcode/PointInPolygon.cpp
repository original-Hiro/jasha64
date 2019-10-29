#include "PointInPolygon.h"
using namespace std;

bool PointInPolygon(Point q, const Polygon& Poly)
{
	double qx = q.first, qy = q.second;
	int n = Poly.siz;
	bool ret = 0;
	double x1 = Poly[n-1].first, y1 = Poly[n-1].second, x2, y2;
	for (int i = 0; i < n; i++)
	{
		x2 = Poly[i].first; y2 = Poly[i].second;
		if (((y1 > qy) != (y2 > qy)) && (qx < (x2 - x1) * (qy - y1) / (y2 - y1) + x1)) ret = !ret;
		x1 = x2; y1 = y2;
	}
	return ret;
}
