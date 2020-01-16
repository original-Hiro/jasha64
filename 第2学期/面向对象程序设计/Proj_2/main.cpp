#include <iostream>
#include "largeint.h"
using std::cin; using std::cout; using std::endl;

int main()
{
	largeint a, b(10, 1); //测试构造函数 
	
	cin >> a; //测试流输入运算符 
	cout << "a = " << a << endl;
	cout << "b = " << b << endl; //测试流输出运算符
	cout << "-a = " << -a << endl;
	cout << "-b = " << -b << endl; //测试负号 
	
	if (a < b) cout << "a < b" << endl;
	else if (a == b) cout << "a = b" << endl; 
	else cout << "a > b" << endl;
	largeint abs_a = absv(a), abs_b = absv(b);
	if (abs_a != abs_b)
	{
		if (abs_a <= abs_b) cout << "|a| <= |b|" << endl;
		else if (abs_a >= abs_b) cout << "|a| >= |b|" << endl;
	}
	else cout << "|a| = |b|" << endl;
	//测试六种比较运算符 和 绝对值函数 
	
	system("pause");
	return 0;
}

