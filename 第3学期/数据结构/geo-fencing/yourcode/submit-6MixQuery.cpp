#include "submit-6MixQuery.h"
#include "RTreeUsage.h"
#include "PointInPolygon.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

static RTree<int, double, 2> TPoly, TPoint;
static unordered_map<int, Polygon> Polygons;
static unordered_map<int, Point> Points;

void SetEnvironmentFromMixQuery()
{
	ios::sync_with_stdio(false);
}

void AddPointFromMixQuery(int id, double x, double y)
{
	Points[id] = Point(x, y);
	const double a[2] = { x, y };
	TPoint.Insert(a, a, id);
}

void DeletePointFromMixQuery(int id)
{
	const double a[2] = { Points[id].first, Points[id].second };
	TPoint.Remove(a, a, id);
	Points.erase(id);
}

vector<int> QueryPointFromMixQuery(double x, double y)
{
	Point p = Point(x, y);
	const double a[2] = { x, y };
	vector<int> vec, ret; TPoly.Search(a, a, SearchCallback, vec);
	for (auto id : vec)
		if (PointInPolygon(p, Polygons[id])) ret.emplace_back(id);
	return ret;
}

void AddPolygonFromMixQuery(int id, int n, vector<pair<double, double>> &polygon)
{
	Polygon Poly = Polygon(polygon, id, n);
	double *mn = Poly.mn, *mx = Poly.mx;
	getMinBoundingRect(mn, mx, Poly);
	TPoly.Insert(mn, mx, id);
	Polygons[id] = Poly;
}

void DeletePolygonFromMixQuery(int id)
{
	double *mn = Polygons[id].mn, *mx = Polygons[id].mx;
	TPoly.Remove(mn, mx, id);
	Polygons.erase(id);
}

vector<int> QueryPolygonFromMixQuery(int n, vector<pair<double, double>> &polygon)
{
	Polygon Poly = Polygon(polygon, 0, n);
	double mn[2], mx[2];
	getMinBoundingRect(mn, mx, Poly);
	vector<int> vec, ret;
	TPoint.Search(mn, mx, SearchCallback, vec);
	for (auto id : vec)
		if (PointInPolygon(Points[id], Poly)) ret.emplace_back(id);
	return ret;
}

