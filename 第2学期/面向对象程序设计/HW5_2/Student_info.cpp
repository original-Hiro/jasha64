#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>
#include <cstddef>
#include "median.h"
#include "Student_info.h"
using std::istream; using std::ostream; using std::endl;
using std::vector;
using std::string;
using std::domain_error;

istream& Read(istream& input, vector<double>& vec)
{
	if (input)
	{
		vec.clear();
		double x;
		while (input >> x) vec.push_back(x);
		input.clear();
	}
	return input;
}
//此处需要特别注意的是，"Student_info::"应加于返回值类型后、函数名前
istream& Student_info::Read(istream& input)
{
	input >> n >> midterm >> final;
	::Read(input, homework);
	return input;
}
ostream& Student_info::Print(string::size_type maxlen, ostream& output) const
{
	output << name() << string(maxlen - name().size() + 1, ' ')	<< letters_grade() << endl;
	return output;
}
bool comp(const Student_info& a, const Student_info& b)
{
	return a.name() < b.name();
}

//非成员函数上不能使用const限定符
inline double grade(double hw, double midterm, double final)
{
	return hw * 0.4 + midterm * 0.2 + final * 0.4;
}
//常量成员函数的声明和定义都要使用const限定符
double Student_info::grade() const
{
	return ::grade(valid() ? median(homework) : 0, midterm, final);
	//成员函数中调用全局函数，应在最前面加"::"
	//此处的::前面没有任何名称，因为我们自己定义的函数grade不属于任何命名空间或类型
}
//成员函数：将学生的成绩转换成对应的字母等级成绩
string Student_info::letters_grade() const
{
	if (!valid()) return "student has done no homework";

	static const double numbers[] = { 90, 85, 82, 78, 75, 71, 66, 62, 60, 0 };
	static const char* const letters[] = { "A", "A-", "B+", "B", "B-", "C+", "C", "C-", "D", "F" };
	//第一个const：修饰char，说明元素的类型是const char*（更进一步地说，这种写法声明的指针把它指向的对象视为常量）
	//第二个const：声明的变量（数组letters）不能被改变
	//类名结束后加const表示声明的该类型变量本身是常量，类名中加const修饰语指代该类型常量
	static const size_t ngrades = sizeof(numbers) / sizeof(*numbers);
	//定义变量用来保存某个特定数据结构的大小的时候，应使用该数据结构的相应类型。

	double grade = final_grade();
	for (size_t i = 0; i < ngrades; i++)
		if (grade >= numbers[i]) return letters[i];
	return "F";
}
