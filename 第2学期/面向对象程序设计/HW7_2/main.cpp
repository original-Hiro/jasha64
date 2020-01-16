#include <iostream>
#include "Shape.h"
using std::cin; using std::cout; using std::endl;

int main()
{
	cout << "请输入三角形的三条边长：";
	Triangle t(cin);
	cout << "三角形的周长为：" << t.Circ() << "，面积为：" << t.Area() << endl;

	cout << "请输入矩形的长和宽：";
	Rectangle r(cin);
	cout << "矩形的周长为：" << r.Circ() << "，面积为：" << r.Area() << endl;

	cout << "请输入圆的半径：";
	Circle c(cin);
	cout << "圆的周长为：" << c.Circ() << "，面积为：" << c.Area() << endl;

	system("pause");
	return 0;
}
