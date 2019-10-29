#include "submit-1AddPolygonBeforeQueryPoint.h"
#include "PointInPolygon.h"
#include "RTreeUsage.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

static RTree<int, double, 2> T;
static unordered_map<int, Polygon> Polygons;

void SetEnvironmentFromAddPolygonBeforeQueryPoint()
{
	ios::sync_with_stdio(false);
}

vector<int> QueryPointFromAddPolygonBeforeQueryPoint(double x, double y)
{
	Point p = Point(x, y);
	const double a[2] = { x, y };
	vector<int> vec, ret; T.Search(a, a, SearchCallback, vec);
	for (auto id : vec)
		if (PointInPolygon(p, Polygons[id])) ret.emplace_back(id);
    return ret;
}

void AddPolygonFromAddPolygonBeforeQueryPoint(int id, int n, vector<pair<double, double> >& polygon)
{
	Polygon Poly = Polygon(polygon, id, n);
	double *mn = Poly.mn, *mx = Poly.mx;
	getMinBoundingRect(mn, mx, Poly);
	T.Insert(mn, mx, id);
	Polygons[id] = Poly;
}
