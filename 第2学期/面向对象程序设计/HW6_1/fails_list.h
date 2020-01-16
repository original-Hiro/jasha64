#pragma once
#include "Student_info.h"
#include <string>
#include <list>

std::list<Student_info> extract_fails(std::list<Student_info>&);
void calc_fails(std::string::size_type, std::list<Student_info>&);
