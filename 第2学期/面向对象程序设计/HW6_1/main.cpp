#include <iostream>
#include <fstream>
#include <ios>
#include <iomanip>
#include <string>
#include <algorithm>
#include <ctime>
#include <cstdlib>
#include "Student_info.h"
#include "fails_list.h"
#include "median.h"
#include "Vec.h"
using std::cin; using std::cout; using std::endl;
using std::ifstream; using std::ofstream;
using std::setw; using std::setprecision; using std::streamsize;
using std::string;
using std::max; using std::sort;
using std::domain_error;

int main()
{
	Vec<Student_info> students;
	Student_info record;
	string::size_type maxlen = 0;

	ifstream fin("grades.txt");
	ofstream fout("final.txt");
	while (record.Read(fin))
	{
		record.get_final_grade();
		maxlen = max(maxlen, record.name().size());
		students.push_back(record);
	}
	sort(students.begin(), students.end(), comp);

	for (Vec<Student_info>::size_type i = 0; i < students.size(); i++)
	{
		students[i].Print(maxlen, cout);
		students[i].Print(maxlen, fout);
	}
	
	cout << endl;
	cout << "the following is the result of testing median function on array" << endl;
	cout << "the random array is:" << endl;
	int a[10];
	srand(time(NULL));
	for (int i = 0; i < 10; i++) cout << (a[i] = rand() / (double)RAND_MAX * 100) << ' '; cout << endl;
	cout << "the median of the array is: " << median(a, a+10, 0) << endl;
	cout << "after median function called, the array is unchanged:" << endl;
	for (int i = 0; i < 10; i++) cout << a[i] << ' '; cout << endl;

	system("pause");
	
	return 0;
}
