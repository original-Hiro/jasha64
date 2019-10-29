#pragma once
#include "PointInPolygon.h"
#include "RelaxTension.h"

inline void getMinBoundingRect(double* a_min, double* a_max, const Polygon& Poly)
{
	a_min[0] = a_max[0] = Poly[0].first; a_min[1] = a_max[1] = Poly[0].second;
	for (auto p : Poly) {Relax(a_min[0], p.first); Relax(a_min[1], p.second); Tension(a_max[0], p.first); Tension(a_max[1], p.second);}
}

