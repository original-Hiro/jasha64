// source file for `Student_info'-related functions
#include "Student_info.h"

using std::istream;  using std::vector;

bool compare(const Core& x, const Core& y)
{
	return x.name() < y.name();
}

istream& Grad::read(istream& input)
{
	read_common(input);
	input >> thesis;
	read_hw(input, homework);
	return input;
}

Student_info::Student_info(const Student_info& rhs) : cp(0)
{
	if (rhs.cp) cp = rhs.cp->clone();
}
Student_info& Student_info::operator = (const Student_info& rhs)
{
	if (&rhs != this) //防止自我赋值
	{
		delete cp;
		if (rhs.cp) cp = rhs.cp->clone();
		else cp = 0;
	}
	return *this;
}
istream& Student_info::read(istream& input)
{
	delete cp; //删除原有内容

	char ch;
	input >> ch;

	if (ch == 'G') cp = new Grad(input);
	else cp = new Core(input);

	return input;
}

// read homework grades from an input stream into a `vector<double>'
istream& read_hw(istream& in, vector<double>& hw)
{
	if (in) {
		// get rid of previous contents
		hw.clear();

		// read homework grades
		double x;
		while (in >> x)
			hw.push_back(x);

		// clear the stream so that input will work for the next student
		in.clear();
	}
	return in;
}

