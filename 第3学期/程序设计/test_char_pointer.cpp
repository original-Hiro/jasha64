#include <iostream>
using namespace std;

int main()
{
	//字符数组可以不指定大小，此时以初始化的字符串长度+1为大小 
	char c[] = "HoHoHo";
	cout << sizeof(c) << endl;
	
	char *p = c;
	p[0] = 'P'; p[1] = 'e';
	cout << p << endl;
	
	//可以把字符串赋值给指针变量，但赋值后p指向的不再是c[0]的地址，而是常量存储区的一个新地址 
	p = "T110";
	//p[0] = 'Z'; //取消注释会导致RE；字符串常量不能修改 
	cout << p << endl;
	
	return 0;
}

