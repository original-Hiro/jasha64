#include "median.h"
#include <vector>
#include <stdexcept>
#include <algorithm>
using std::vector;
using std::domain_error;
using std::sort;

double median(vector<double> vec)
{
	vector<double>::size_type siz = vec.size();
	if (siz == 0) throw domain_error("median of an empty vector");
	//抛出异常，但不在该函数内处理，因为在这个函数里面做不了什么
	//这种情况下，会把异常回传给调用的程序。由调用程序来处理是更为合适的。 
	sort(vec.begin(), vec.end());
	if (siz % 2 == 0) return (vec[siz / 2] + vec[siz / 2 - 1]) / 2;
	else return vec[siz / 2];
}
