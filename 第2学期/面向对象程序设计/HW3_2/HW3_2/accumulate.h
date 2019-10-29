#pragma once
#include <vector>
template <class In, class X>
X accumulate(In b, In e, X x)
{
	while (b != e) x += *(b++);
	return x;
}
//类模板的定义必须是系统可以直接访问的，因此必须定义在头文件中
