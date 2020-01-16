#include "grade.h"
#include "Student_info.h"
#include "median.h"
#include <stdexcept>
using std::domain_error;

double grade(const Student_info& s)
{
	if (s.homework.empty())
		throw domain_error("student has done no homework");
	return grade(median(s.homework), s.midterm, s.final);
}
//КЏЪ§жиди