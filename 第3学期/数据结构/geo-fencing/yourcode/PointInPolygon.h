#pragma once
#include "dcmp.h"
#include <vector>
#include <algorithm>
typedef std::pair<double, double> Point;
Point operator - (Point, Point);
struct Polygon: public std::vector<Point>
{
	int id, siz;
	double mn[2], mx[2];
	Polygon() : id(0), siz(0), mn{}, mx{} {}
	Polygon(const vector<Point>& vec, int id, int siz) : vector<Point>(vec), id(id), siz(siz) {}
};

inline double Dot(Point p1, Point p2) {return p1.first * p2.first + p1.second * p2.second;}
inline double Cross(Point p1, Point p2) {return p1.first * p2.second - p2.first * p1.second;}
inline bool OnSegment(Point q, Point p1, Point p2) {return dcmp(Cross(q, p1-p2)) == 0 && dcmp(Dot(q, p1-p2)) <= 0;}
inline bool SegmentIntersect(Point a1, Point a2, Point b1, Point b2)
{
	int c1 = dcmp(Cross(a2 - a1, b1 - a1)), c2 = dcmp(Cross(a2 - a1, b2 - a1)),
		c3 = dcmp(Cross(b2 - b1, a1 - b1)), c4 = dcmp(Cross(b2 - b1, a2 - b1));
	return c1 * c2 < 0 && c3 * c4 < 0;
}
bool PointInPolygon(Point, const Polygon&);

