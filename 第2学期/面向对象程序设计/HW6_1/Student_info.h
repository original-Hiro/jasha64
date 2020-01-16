#pragma once
#include <iostream>
#include <string>
#include <list>
#include "Vec.h"

class Student_info
{
public:
	Student_info() :final_Grade(0), midterm(0), final(0) {}
	Student_info(std::istream& input) { Read(input); }
	std::istream& Read(std::istream&);
	std::ostream& Print(std::string::size_type, std::ostream&) const;
	std::string name() const { return n; }
	double final_grade() const { return final_Grade; }
	bool valid() const { return !homework.empty(); }
	double grade() const;
	void get_final_grade() { final_Grade = grade(); }
	bool fgrade() const { return final_grade() < 60; }
	std::string letters_grade() const;
private:
	Vec<double> homework;
	std::string n;
	double final_Grade, midterm, final;
};
std::istream& Read(std::istream&, Vec<double>&);
bool comp(const Student_info&, const Student_info&);
