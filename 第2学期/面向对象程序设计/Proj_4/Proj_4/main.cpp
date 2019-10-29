#include <iostream>
#include "largeint.h"
using std::cin; using std::cout; using std::endl;

int main()
{
	largeint a;
	int b;
	
	cin >> a >> b;
	
	cout << "a * b = " << a * b << endl;
	cout << "a / b = " << a / b << endl;
	cout << "a % b = " << a % b << endl;
	
	system("pause");
	return 0;
}

