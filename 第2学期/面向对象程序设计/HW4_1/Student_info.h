#ifndef GUARD_Student_info
#define GUARD_Student_info

// `Student_info.h' header file
#include <iostream>
#include <string>
#include <vector>

class Student_info {
	//保护标识符可以以任意顺序出现，而且可以出现多次
private:
	std::string n;
	double midterm, final;
	std::vector<double> homework;

public:
	Student_info();
	Student_info(std::istream&);
	std::string name() const {
		return n;
	}
	//常量成员函数不可以改变正在由它们执行的对象的内部状态
	//不允许在常量成员函数中调用非常量成员函数，这违反常量成员函数的定义
	bool valid() const {
		return !homework.empty();
	}
	std::istream& read(std::istream&);
	double grade() const;
};

bool compare(const Student_info&, const Student_info&);
std::istream& read_hw(std::istream&, std::vector<double>&);
#endif

