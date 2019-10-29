#include <iostream>
using namespace std;

int main()
{
	int a = 2147483648;
	int b = -2147483648;
	int c = 2147483649;
	unsigned short d = 65539;
	short e = -32790;
	//验证真值
	cout << "真值:" << endl;
	cout << "a = " << a << endl;
	cout << "b = " << b << endl;
	cout << "c = " << c << endl;
	cout << "d = " << d << endl;
	cout << "e = " << e << endl;
	return 0;
}

