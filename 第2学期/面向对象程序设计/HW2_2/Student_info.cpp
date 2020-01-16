#include <iostream>
#include <vector>
#include <string>
#include "Student_info.h"
#include "grade.h"
//值得一提的是，在头文件中包含cpp文件是不规范的，容易导致重复定义 
using std::istream;
using std::vector;
using std::string;

istream& Read(istream& input, vector<double>& vec)
{
	if (input)
	{
		vec.clear(); //初始化
		double x;
		while (input >> x) vec.push_back(x); //读入数据并存储到vec中
		input.clear(); //重置输入流的状态
	}
	return input;
}
istream& Read(istream& input, Student_info& s)
{
	input >> s.name >> s.midterm >> s.final;
	Read(input, s.homework);
	return input;
}
bool comp(const Student_info& a, const Student_info& b)
{
	return a.final_grade > b.final_grade;
}
void get_final_grade(Student_info& s)
{
	s.final_grade = grade(s);
}
