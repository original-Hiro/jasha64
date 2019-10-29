#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main()
{
	char s;
	double angle, fx;
	
	while (true)
	{
		cout << "请输入三角函数类型（“s”代表正弦，“c”代表余弦，“t”代表正切。输入“0”结束程序。）：";
		cin >> s;
		switch (s)
		{
			case 's': cout << "请输入正弦值："; cin >> fx; angle = asin(fx);
						cout << "余弦：" << cos(angle) << ' ' << "正切：" << tan(angle) << endl; break;
			case 'c': cout << "请输入余弦值："; cin >> fx; angle = acos(fx);
						cout << "正弦：" << sin(angle) << ' ' << "正切：" << tan(angle) << endl; break;
			case 't': cout << "请输入正切值："; cin >> fx; angle = atan(fx);
						cout << "正弦：" << sin(angle) << ' ' << "余弦：" << cos(angle) << endl; break;
			case '0': cout << "感谢使用！" << endl; return 0;
			default: cout << "输入错误。" << endl; break;
		}
	}
	return 0;
}

