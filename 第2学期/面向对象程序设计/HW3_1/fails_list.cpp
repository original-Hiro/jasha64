#include <iostream>
#include <ios>
#include <iomanip>
#include <list>
#include <iterator>
#include <string>
#include <algorithm>
#include "grade.h"
#include "Student_info.h"

using std::cin; using std::cout; using std::endl; using std::streamsize;
using std::list;
using std::string;
using std::max;

//vector支持索引和快速随机访问，list支持快速随机插入与删除，故选择用list而不是vector
list<Student_info> extract_fails(list<Student_info>& students)
{
	list<Student_info> fail;
	list<Student_info>::iterator I = students.begin();
	//iterator类型支持修改，const_iterator类型支持对容器内对象的只读访问，不支持对该对象进行修改，但支持对容器本身进行插入与删除
	while (I != students.end())
	{
		if (fgrade(*I))
		{
			fail.push_back(*I);
			I = students.erase(I);
		}
		else I++;
	}
	return fail;
}
list<Student_info> students, fail;

void calc_fails()
{
	string::size_type len = 0; //要用标准库自带的长度类型来表示标准库对象的大小
	Student_info s;
	while (Read(cin, s))
	{
		get_final_grade(s);
		students.push_back(s);
		len = max(len, s.name.size());
	}

	fail = extract_fails(students);
	streamsize prec = cout.precision();
	cout.precision(3);
	students.sort(comp);
	cout << "passing student records:" << endl;
	for (list<Student_info>::iterator I = students.begin(); I != students.end(); I++)
	{
		cout << I->name << string(len - (I->name).size() + 1, ' ') << I->final_grade << endl;
	}
	fail.sort(comp);
	cout << "failing student records:" << endl;
	for (list<Student_info>::iterator I = fail.begin(); I != fail.end(); I++)
		cout << I->name << string(len - (I->name).size() + 1, ' ') << I->final_grade << endl;
	cout.precision(prec); //修改精度输出完毕后，最后要恢复到默认的精度
}
