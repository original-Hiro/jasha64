#ifndef GUARD_grade_h
#define GUARD_grade_h
#include "Student_info.h"
//确保头文件只被编译一次
double grade(const Student_info&);
inline double grade(double hw, double midterm, double final)
{
	return hw * 0.4 + midterm * 0.2 + final * 0.4;
}
//内联函数应该定义在头文件中
#endif
