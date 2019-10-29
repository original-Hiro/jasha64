#include <iostream>
#include "largeint.h"
using std::cout; using std::endl;

int main()
{
	largeint a, b(2147483647); //测试构造函数 
	cout << a.size() << ' ' << b.size() << endl; //测试size()函数 
	
	//system("pause");
	return 0;
}

