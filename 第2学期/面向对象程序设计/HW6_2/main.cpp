#include "Queue.h"
#include "Work.h"

int main()
{
	Work(); //为了显示出析构函数调用效果，把工作部分封装到另外一个函数中，函数执行结束时销毁该函数内声明的局部变量，此时调用析构函数
	system("pause");
	return 0;
}
