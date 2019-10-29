#include "submit-5MixQueryPolygon.h"
#include "PointInPolygon.h"
#include "RTreeUsage.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

static RTree<int, double, 2> T;
static unordered_map<int, Point> p;

void SetEnvironmentFromMixQueryPolygon()
{
	ios::sync_with_stdio(false);
}

void AddPointFromMixQueryPolygon(int id, double x, double y)
{
	p[id] = Point(x, y);
	const double a[2] = { x, y };
	T.Insert(a, a, id);
}

void DeletePointFromMixQueryPolygon(int id)
{
	const double a[2] = { p[id].first, p[id].second };
	T.Remove(a, a, id);
	p.erase(id);
}

vector<int> QueryPolygonFromMixQueryPolygon(int n, vector<pair<double, double> >& polygon)
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
