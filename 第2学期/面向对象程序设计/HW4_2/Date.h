#pragma once
//确保头文件不被重复编译 
#include <iostream>
const int max_Day[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

class Date
{
	private: 
	//年、月、日，定义为私有数据成员 
	//class的默认保护方式即为private，但仍然建议显式地声明保护方式 
	int Y, M, D;
	
	public:
	Date();
	Date(int, int, int);
	Date(std::istream&);
	std::ostream& Display(std::ostream&); //头文件中不可以使用using声明
	void inc_Year();
	void inc_Month();
	void inc_Day();
	
	//访问器接口，获得年月日
	//使用const限定符保证访问时不会修改private数据
	int Year() const { return Y; }
	int Month() const { return M; }
	int Day() const { return D; }
	
	//成员函数（内联的）：当月实际的最大天数（md是max date的缩写） 
	//内联函数的声明和定义不分开
	//如果是闰年2月，M == 2和is_Leap_Year()的值均为1，最大天数自动修改为29天，反之亦然 
	int md() const { return max_Day[M] + (M == 2 * is_Leap_Year()); }
	
	//成员函数（内联的）：判断该日期的日/月是否有效（用于输入函数中抛出异常） 
	bool dayValid() const { return 0 < D && D <= md(); }
	bool monValid() const { return 1 <= M && M <= 12; }
	
	//成员函数（内联的）：判断当前的年份是否为闰年 
	bool is_Leap_Year() const { return Y % 400 == 0 || (Y % 4 == 0 && Y % 100 != 0); }
};

int Interval(Date, Date);
