#include "submit-4MixQueryPoint.h"
#include "PointInPolygon.h"
#include "RTreeUsage.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

static RTree<int, double, 2> T;
static unordered_map<int, Polygon> Polygons;

void SetEnvironmentFromMixQueryPoint()
{
	ios::sync_with_stdio(false);
}

vector<int> QueryPointFromMixQueryPoint(double x, double y)
{
	Point p = Point(x, y);
	const double a[2] = { x, y };
	vector<int> vec, ret; T.Search(a, a, SearchCallback, vec);
	for (auto id : vec)
		if (PointInPolygon(p, Polygons[id])) ret.emplace_back(id);
	return ret;
}

void AddPolygonFromMixQueryPoint(int id, int n, vector<pair<double, double> >& polygon)
{
	Polygon Poly = Polygon(polygon, id, n);
	double *mn = Poly.mn, *mx = Poly.mx;
	getMinBoundingRect(mn, mx, Poly);
	T.Insert(mn, mx, id);
	Polygons[id] = Poly;
}

void DeletePolygonFromMixQueryPoint(int id)
{
	double *mn = Polygons[id].mn, *mx = Polygons[id].mx;
	T.Remove(mn, mx, id);
	Polygons.erase(id);
}
