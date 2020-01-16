#pragma once
#include <algorithm>
template <class In, class X>
X min_element(In b, In e)
{
	X x = *(b++);
	while (b != e) x = std::min(x, *(b++)); //头文件中不可以使用using声明
	return x;
}
template <class In, class X>
X max_element(In b, In e)
{
	X x = *(b++);
	while (b != e) x = std::max(x, *(b++));
	return x;
}
//顺序只读访问 input operator 要求迭代器支持++、*、!=