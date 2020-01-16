#include "largeint.h"

largeint::largeint()
{
	v.push_back(0); //正号
	v.push_back(0); //数字0
}
largeint::largeint(int n)
{
	//vector是标准库类型，会被自身的构造函数初始化，此处不需要人为加以初始化 
	if (n < 0) {v.push_back(1); n = -n;}
	else v.push_back(0);
	while (n > 0) {v.push_back(n % 10); n /= 10;}
}

