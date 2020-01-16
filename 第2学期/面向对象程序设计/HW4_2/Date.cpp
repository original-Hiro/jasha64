#include <iostream>
#include <stdexcept>
#include "Date.h"
using std::istream; using std::ostream; using std::endl;
using std::domain_error;

//三种构造函数（经过测试，构造函数也可以内联）
Date::Date() { Y = 2015; M = D = 1; }
//此处不全部初始化为0，而是赋值为一个有效的日期。
//结合其它成员函数中确保运算结果有效性的部分，我们就可以确保一个程序中存在的一切Date类型对象都是有效日期。
Date::Date(int a, int b, int c): Y(a), M(b), D(c) {} //构造函数初始化列表，在构造函数的函数体之前执行
Date::Date(istream& input)
{
	input >> Y >> M >> D;
	if (!dayValid()) throw domain_error("invalid day");
	if (!monValid()) throw domain_error("invalid month");
}

//成员函数：输出 
//此处需要特别注意的是，Date::应加于返回值类型后、函数名前
ostream& Date::Display(ostream& output)
{
	output << Y << "年" << M << "月" << D << "日" << endl; //输出这个Date对象的年、月、日，中间用点隔开，并输出一个换行符
	return output;
}

//成员函数：增加1年，增加1月，增加1日 
void Date::inc_Year()
{
	if (is_Leap_Year() && M == 2 && D == 29) D = 28; //闰年2月29日增加一年的结果修正为平年2月28日 
	Y++;
}
void Date::inc_Month()
{
	if (++M == 13) { Y++; M = 1; }
	if (D > md()) D = md(); //如果增加一个月后的日期超出了当月最大的日期，将其修正为等于当月最大的日期 
}
void Date::inc_Day()
{
	if (++D > md())
	{
		D = 1;
		if (++M == 13) { Y++; M = 1; } //12月31日增加一天的结果修正为次年1月1日 
	}
}

//功能函数：计算一个日期增加一年/月所增加的天数（用于计算日期间隔）（直接放在源文件中，不能被其他用户调用）
//增加一年函数中，需要特别注意的问题是，如果当前的月大于二月，计算的时候我们跨过了次年二月而不是当年二月，则需要判断次年是否是闰年 
//否则，我们跨过了当年二月而不是次年二月，需要判断当年是否是闰年 
//特殊：2月29日增加一年只能增加到2月28日，扣除该天
int ymd(Date d)
{
	bool is_229 = d.is_Leap_Year() && d.Month() == 2 && d.Day() == 29;
	if (d.Month() > 2) d.inc_Year();
	return 365 - is_229 + d.is_Leap_Year();
}
//增加一月函数中，需要注意的是如果当前的日期在下个月中大于最大日期，则需要扣除多出的天数
int mmd(Date d)
{
	int re = d.md(), dd = d.Day();
	d.inc_Month();
	if (dd > d.Day()) re -= dd - d.Day();
	return re;
}

//功能函数：计算两个日期的间隔（因为两个日期是平等关系，所以不作为其中一个日期的成员函数调用） 
int Interval(Date a, Date b)
{
	int A = 0, B = 0; //A记录日期a增加了多少天，B记录日期b增加了多少天
	while (a.Day() >= 28) { A++; a.inc_Day(); }
	while (b.Day() >= 28) { B++; b.inc_Day(); }
	//上面两行处理一个bug：
	//如果需要增加一个月，但是下个月没有这个日期，会出问题，所以把月末的日期先前进到下个月初。
	//同样这样也可以解决闰年2月29日增加一年的问题。
	while (a.Month() < b.Month()) { A += a.md(); a.inc_Month(); }
	while (b.Month() < a.Month()) { B += b.md(); b.inc_Month(); }
	while (a.Day() < b.Day()) { A++; a.inc_Day(); }
	while (b.Day() < a.Day()) { B++; b.inc_Day(); }
	while (a.Year() < b.Year()) { A += ymd(a); a.inc_Year(); }
	while (b.Year() < a.Year()) { B += ymd(b); b.inc_Year(); }
	return abs(A-B); //到达一个相同的日期，a和b增加的天数的差的绝对值，就是a和b的相隔的天数。
}

