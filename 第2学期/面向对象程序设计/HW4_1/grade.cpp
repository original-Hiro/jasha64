#include <stdexcept>
#include <vector>
#include "grade.h"
#include "median.h"
#include "Student_info.h"

using std::domain_error;  using std::vector;


// compute a student's overall grade from midterm and final exam grades and homework grade
double grade(double midterm, double final, double homework)
{
	return 0.2 * midterm + 0.4 * final + 0.4 * homework;
}

// compute a student's overall grade from midterm and final exam grades
// and vector of homework grades.
// this function does not copy its argument, because `median' does so for us.
//非成员函数上不能使用const限定符
double grade(double midterm, double final, const vector<double>& hw)
{
	if (hw.size() == 0)
		throw domain_error("student has done no homework");
	return grade(midterm, final, median(hw));
}
//常量成员函数的声明和定义都要使用const限定符
double Student_info::grade() const
{
	if (!valid()) throw domain_error("attempted to call grade() of an empty \"Student_info\" variable");
	return ::grade(midterm, final, homework); //此处的::前面没有任何名称，因为我们自己定义的函数grade不属于任何命名空间或类型
}

