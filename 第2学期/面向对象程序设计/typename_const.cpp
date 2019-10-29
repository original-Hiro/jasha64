#include <iostream>
#include <cstddef>
using std::cout;

size_t const NDim = 10; //这种写法和const size_t等价，表示声明的变量是不可被改变的
//const int* a和int const* a表示a是一个指针，它总是把它所指向的目标当作一个int常量
//int* const a; 表示a是一个指针常量，初始化的时候必须固定指向一个int变量，之后就不能再指向别的地方了。
//类名结束后加const表示声明的该类型变量本身是常量，类名中加const修饰语指代该类型常量。 
int Coords[NDim];

int main()
{
	return 0;
}

