#include "submit-2AddPointBeforeQueryPolygon.h"
#include "PointInPolygon.h"
#include "RTreeUsage.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

static RTree<int, double, 2> T;
static unordered_map<int, Point> p;

void SetEnvironmentFromAddPointBeforeQueryPolygon()
{
	ios::sync_with_stdio(false);
}

void AddPointFromAddPointBeforeQueryPolygon(int id, double x, double y)
{
	p[id] = Point(x, y);
	const double a[2] = { x, y };
	T.Insert(a, a, id);
}

vector<int> QueryPolygonFromAddPointBeforeQueryPolygon(int n, vector<pair<double, double> >& polygon)
{
	Polygon Poly = Polygon(polygon, 0, n);
	double mn[2], mx[2];
	getMinBoundingRect(mn, mx, Poly);
	vector<int> vec, ret;
	T.Search(mn, mx, SearchCallback, vec);
	for (auto id : vec)
		if (PointInPolygon(p[id], Poly)) ret.emplace_back(id);
	return ret;
}
