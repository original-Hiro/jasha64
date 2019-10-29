#include <iostream>
#include "Str.h"
using std::cin; using std::cout; using std::endl;

int main()
{
	Str::size_type n;
	Str name;

	cout << "Please enter your first name: ";
	cin >> name;
	cout << "Please enter the number of blanks surrounding the greeting: ";
	cin >> n;
	cout << endl;

	const Str greeting = "Hello, " + name + "!";
	const Str space(greeting.size(), ' ');
	const Str::size_type col = greeting.size() + n * 2 + 2;
	const Str::size_type row = n * 2 + 3;
	for (Str::size_type i = 0; i < row; i++)
	{
		cout << '*';
		if (i == 0 || i == row - 1)
			for (Str::size_type j = 1; j < col - 1; j++) cout << '*';
		else {
			for (Str::size_type j = 0; j < n; j++) cout << ' ';
			if (i == n + 1) cout << greeting;
			else cout << space;
			for (Str::size_type j = 0; j < n; j++) cout << ' ';
		}
		cout << '*' << endl;
	}

	cout << "逐个字符输出greeting(字符之间以空格分隔):" << endl;
	for (Str::size_type i = 0; i < greeting.size(); i++) cout << greeting[i] << ' ';
	cout << endl;

	system("pause");
	return 0;
}
