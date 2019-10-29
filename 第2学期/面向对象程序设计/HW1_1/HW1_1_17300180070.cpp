#include <iostream>
#include <string>

int main()
{
	std::string::size_type n;
	std::string name;
	
	std::cout << "Please enter your first name: ";
	std::cin >> name;
	std::cout << "Please enter the number of blanks surrounding the greeting: ";
	std::cin >> n;
	std::cout << std::endl;
	
	const std::string greeting = "Hello, " + name + "!";
	const std::string space(greeting.size(), ' ');
	const std::string::size_type col = greeting.size() + n*2 + 2;
	const std::string::size_type row = n*2 + 3;
	for (std::string::size_type i = 0; i < row; i++)
	{
		std::cout << '*';
		if (i == 0 || i == row-1)
			for (std::string::size_type j = 1; j < col-1; j++) std::cout << '*';
		else {
			for (std::string::size_type j = 0; j < n; j++) std::cout << ' ';
			if (i == n+1) std::cout << greeting;
			else std::cout << space;
			for (std::string::size_type j = 0; j < n; j++) std::cout << ' ';
		}
		std::cout << '*' << std::endl;
	}
	
	return 0;
}

