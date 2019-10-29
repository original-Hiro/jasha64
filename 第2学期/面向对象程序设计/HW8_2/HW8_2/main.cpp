#include <iostream>
#include <ios>
#include <iomanip>
#include <fstream>
#include <stdexcept>
#include "Shape.h"
using std::cin; using std::cout; using std::endl; using std::setw;
using std::ifstream;
using std::domain_error;

int main()
{
	ifstream fin("shape.txt");

	cout << "Area    Circumference" << endl;
	Shape s;
	while (s.read(fin))
	{
		try {
			s.get_Area();
			s.get_Circ();
		}
		catch (domain_error e)
		{
			cout << e.what() << endl;
			continue;
		}
		cout.setf(std::ios::left); //左对齐
		cout << setw(7) << s.Area();
		cout << ' ';
		cout << setw(7) << s.Circ() << endl;
		//setw的作用域只有当前语句，不需要恢复默认设定
	}

	system("pause");
	return 0;
}
