//格式错误，已订正。下次做elearning作业记得看附件里的图片
#include <iostream>
#include <stdexcept>
#include "Date.h"
using std::cin; using std::cout; using std::endl;
using std::domain_error;

int main()
{
	Date d1, d2;
	
	cout << "请输入两个日期（年月日，以空格分隔）：" << endl;
	try { d1 = Date(cin); d2 = Date(cin); }
	catch (domain_error e)
	{
		cout << e.what() << endl;
		//system("pause");
		return 1;
	}
	cout << "日期一："; d1.Display(cout);
	cout << "日期二："; d2.Display(cout);
	cout << "两个日期相隔天数为：" << Interval(d1, d2) << endl;

	Date d = d1;
	d.inc_Day(); cout << "给日期一增加一日为："; d.Display(cout);
	d = d1;
	d.inc_Month(); cout << "给日期一增加一月为："; d.Display(cout);
	d = d1;
	d.inc_Year(); cout << "给日期一增加一年为："; d.Display(cout);
	
	//system("pause");
	//此处直接使用getchar()不能使程序暂停，对比前几次的程序发现，只有输入用EOF结束时才可以使用getchar()
	//推测是因为本程序执行到最后时输入缓冲区不是空的。
	//执行cin.clear()无效，因为cin.clear()仅仅清除输入流的错误状态，而不是清空输入缓冲区。
	//执行cin.ignore(2147483647, '\n')后可以使用getchar()暂停程序。
	//至于cin.sync()和关闭流同步，在VS中无效，在Dev中有效，推测这两个函数的实现和编译器有关。
	//为简便起见，使用system("pause")代替

	return 0;
}

