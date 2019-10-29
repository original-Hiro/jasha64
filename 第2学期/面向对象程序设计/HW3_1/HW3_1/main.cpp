#include <iostream>
#include <ios>
#include <iomanip>
#include <vector>
#include <string>
#include <algorithm>
#include "Student_info.h"
#include "grade.h"
using std::cin; using std::cout; using std::endl;
using std::setw; using std::setprecision; using std::streamsize;
using std::vector;
using std::string;
using std::max; using std::sort;
using std::domain_error;

int main()
{
	calc_fails();
	/*
	vector<Student_info> students;
	Student_info record;
	string::size_type maxlen = 0;

	//读入学生数据，捕获并处理可能的异常，并统计最长的名字长度，便于对齐输出
	while (Read(cin, record))
	{
		try {
			get_final_grade(record);
			maxlen = max(maxlen, record.name.size());
			students.push_back(record);
		}
		catch (domain_error)
		{
			cout << record.name << " has done no homework" << endl;
		}
	}
	sort(students.begin(), students.end(), comp); //将学生信息按照总成绩顺序排序

	//输出学生成绩统计表
	for (vector<Student_info>::size_type i = 0; i < students.size(); i++)
	{
		//按设定的宽度输出学生名字
		cout << students[i].name << string(maxlen - students[i].name.size() + 1, ' ');
		//输出学生成绩
		streamsize prec = cout.precision();
		cout << setprecision(3) << students[i].final_grade << setprecision(prec);

		//最后输出一个换行符
		cout << endl;
	}
	*/
	//getchar();
	
	return 0;
}
