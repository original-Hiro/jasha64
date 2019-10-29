#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <list>

class Student_info
{
public:
	Student_info() :final_Grade(0), midterm(0), final(0) {}
	Student_info(std::istream& input) { Read(input); }
	std::istream& Read(std::istream&);
	std::ostream& Print(std::string::size_type, std::ostream&) const;
	//原则上，所有不更改执行对象内部的成员函数都声明成const成员函数，以便该类型的常量对象调用
	std::string name() const { return n; }
	double final_grade() const { return final_Grade; }
	bool valid() const { return !homework.empty(); }
	double grade() const;
	void get_final_grade() { final_Grade = grade(); }
	bool fgrade() const { return final_grade() < 60; }
	std::string letters_grade() const;
private:
	std::vector<double> homework;
	std::string n;
	double final_Grade, midterm, final;
};
//与类紧密相关的全局函数也放在类定义的头文件中
std::istream& Read(std::istream&, std::vector<double>&);
bool comp(const Student_info&, const Student_info&);
