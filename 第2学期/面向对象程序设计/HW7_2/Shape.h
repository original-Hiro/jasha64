#pragma once
#include <iostream>
#include <cmath>
const double pi = acos(-1);

class Shape
{
public:
	Shape() : Area(0), Circ(0) {}
	//构造函数

	virtual double Area() = 0;
	//成员函数：面积
	virtual double Circ() = 0;
	//成员函数：周长
	//由于不知道形状，此处声明为纯虚函数，由派生类给出定义
protected:
	//这种保护标签下的成员允许该类、派生类访问，不允许使用者访问
	double Area, Circ;
};
class Triangle : public Shape
//这里的public关键字的含义是，从基类继承的内容是派生类接口的一部分，基类public成员自动成为派生类public成员
{
public:
	Triangle() : a(0), b(0), c(0) {}
	Triangle(std::istream& input) { input >> a >> b >> c; }
	//构造函数
	//派生类对象构造规则：先用基类构造函数初始化基类的部分，再调用派生类构造函数初始化派生类的部分

	double Area()
	{
		if (Shape::Area) return Shape::Area;
		double p = Circ() / 2;
		return Shape::Area = sqrt(p * (p - a) * (p - b) * (p - c));
	}
	//成员函数：面积
	//海伦公式

	double Circ()
	{
		if (Shape::Circ) return Shape::Circ;
		return Shape::Circ = a + b + c;
	}
	//成员函数：周长

private:
	double a, b, c;
	//成员变量：三边边长
};
class Rectangle : public Shape
{
public:
	Rectangle() : a(0), b(0) {}
	Rectangle(std::istream& input) { input >> a >> b; }
	//构造函数

	double Area()
	{
		if (Shape::Area) return Shape::Area;
		return Shape::Area = a * b;
	}
	//成员函数：面积

	double Circ()
	{
		if (Shape::Circ) return Shape::Circ;
		return Shape::Circ = 2 * (a + b);
	}
	//成员函数：周长

private:
	double a, b;
	//成员变量：长和宽
};
class Circle : public Shape
{
public:
	Circle() : r(0) {}
	Circle(std::istream& input) { input >> r; }
	//构造函数

	double Area()
	{
		if (Shape::Area) return Shape::Area;
		return Shape::Area = pi * r * r;
	}
	//成员函数：面积

	double Circ()
	{
		if (Shape::Circ) return Shape::Circ;
		return Shape::Circ = 2 * pi * r;
	}
	//成员函数：周长

private:
	double r;
	//成员变量：半径
};
