#pragma once
//确保头文件只被编译一次的另一种写法
#include <vector>
double median(std::vector<double>);
//将频繁调用的短代码声明为内联函数，提高效率