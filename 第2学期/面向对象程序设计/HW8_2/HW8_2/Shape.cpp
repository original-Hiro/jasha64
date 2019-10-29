#include "Shape.h"
#include <iostream>
using std::istream;

Shape::Shape(const Shape& rhs) : sp(0)
{
	if (rhs.sp) sp = rhs.sp->clone();
	//复制函数的对象都是未初始化的，所以不需进行其他操作
}
Shape& Shape::operator = (const Shape& rhs)
{
	if (&rhs != this) //自我赋值判断
	{
		delete sp; //清除已有内容
		if (rhs.sp) sp = rhs.sp->clone();
		else sp = 0;
	}
	return *this;
}
istream& Shape::read(istream& input)
{
	delete sp;
	//删除原有的内容

	char c;
	input >> c;
	if (c == 'T') sp = new Triangle(input);
	else if (c == 'R') sp = new Rectangle(input);
	else sp = new Circle(input);

	return input;
}
