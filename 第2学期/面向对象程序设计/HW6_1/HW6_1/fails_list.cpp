#include <iostream>
#include <ios>
#include <iomanip>
#include <list>
#include <iterator>
#include <string>
#include <algorithm>
#include "Student_info.h"

using std::cin; using std::cout; using std::endl; using std::streamsize;
using std::list;
using std::string;
using std::max;

list<Student_info> extract_fails(list<Student_info>& students)
{
	list<Student_info> fail;
	list<Student_info>::iterator I = students.begin();
	while (I != students.end())
	{
		if (I -> fgrade())
		{
			fail.push_back(*I);
			I = students.erase(I);
		}
		else I++;
	}
	return fail;
}
list<Student_info> students, fail;

void calc_fails(string::size_type len, list<Student_info>& students)
{
	fail = extract_fails(students);
	students.sort(comp);
}
