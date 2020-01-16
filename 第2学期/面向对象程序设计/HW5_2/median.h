#pragma once
#include <vector>
#include <stdexcept>
#include <algorithm>
//模板函数的定义要求是系统可直接访问的，所以其定义和声明都在头文件中
template <class In, class X>
X median(In beg, In end, X val)
{
	if (beg == end) throw std::domain_error("median of an empty sequence");
	std::vector<X> vec;
	typename std::vector<X>::size_type siz = end - beg; //类模板中涉及到成员类名的，必须加typename前缀
	std::copy(beg, end, back_inserter(vec));
	//把[beg, end)的值复制一遍，从而保证不更改原数组
	std::sort(vec.begin(), vec.end());
	if (siz % 2 == 0) return (vec[siz / 2] + vec[siz / 2 - 1]) / 2;
	else return vec[siz / 2];
}
//再次强调头文件中不可以使用using声明，其中的类型名都必须加上完整的namespace限定。如果忘记，编译器会报莫名其妙的错误
inline double median(const std::vector<double>& vec) { return median(vec.begin(), vec.end(), 0.0); }
