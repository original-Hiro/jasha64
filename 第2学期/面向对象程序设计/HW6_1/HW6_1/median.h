#pragma once
#include <stdexcept>
#include <algorithm>
#include <vector>
#include "Vec.h"
template <class In, class X>
X median(In beg, In end, X val)
{
	if (beg == end) throw std::domain_error("median of an empty sequence");
	std::vector<X> vec(beg, end);
	typename std::vector<X>::size_type siz = end - beg;
	std::sort(vec.begin(), vec.end());
	if (siz % 2 == 0) return (vec[siz / 2] + vec[siz / 2 - 1]) / 2;
	else return vec[siz / 2];
}
inline double median(const Vec<double>& vec) { return median(vec.begin(), vec.end(), 0.0); }
