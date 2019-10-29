#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <list>

struct Student_info
{
	std::vector<double> homework;
	std::string name;
	double final_grade, midterm, final;
};
//不可以使用using指令，因为如果使用了，它们也会对包含这个头文件的程序产生同样的限定，这是不合规范的 
//由于调用这些函数与上面的结构体密切相关，因此将它们封装在一个头文件中
std::istream& Read(std::istream&, Student_info&);
std::istream& Read(std::istream&, std::vector<double>&);
bool comp(const Student_info&, const Student_info&);
void get_final_grade(Student_info&);
inline bool fgrade(Student_info s)
{
	return s.final_grade < 60;
}
//头文件中的内容都是定义性和说明性的，不含有可执行内容 
std::list<Student_info> extract_fails(std::list<Student_info>&);
void calc_fails();
