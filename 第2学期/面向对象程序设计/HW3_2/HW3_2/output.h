#pragma once
#include <iostream>
//在一行上输出[b, e)范围内的所有对象，用空格隔开（行末没有多余空格），最后换行
template <class In>
void output(In b, In e)
{
	std::cout << *(b++);
	while (b != e) std::cout << ' ' << *(b++);
	std::cout << std::endl;
}
