#include <iostream>
#include <string>
#include <stdexcept>
#include <cstddef>
#include "median.h"
#include "Student_info.h"
using std::istream; using std::ostream; using std::endl;
using std::string;
using std::domain_error;

istream& Read(istream& input, Vec<double>& vec)
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

inline double grade(double hw, double midterm, double final)
{
	return hw * 0.4 + midterm * 0.2 + final * 0.4;
}
double Student_info::grade() const
{
	return ::grade(valid() ? median(homework) : 0, midterm, final);
}
string Student_info::letters_grade() const
{
	if (!valid()) return "student has done no homework";

	static const double numbers[] = { 90, 85, 82, 78, 75, 71, 66, 62, 60, 0 };
	static const char* const letters[] = { "A", "A-", "B+", "B", "B-", "C+", "C", "C-", "D", "F" };
	static const size_t ngrades = sizeof(numbers) / sizeof(*numbers);
	//定义变量用来保存某个特定数据结构的大小的时候，应使用该数据结构的相应类型。

	double grade = final_grade();
	for (size_t i = 0; i < ngrades; i++)
		if (grade >= numbers[i]) return letters[i];
	return "F";
}
