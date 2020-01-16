#pragma once
#include <iostream>
#include <cmath>
#include <stdexcept>
const double pi = acos(-1);

class shape_base
{
	friend class Shape; //将类声明为友元，给予其访问private成员的权限
public:
	shape_base() : area(0), circ(0) {}
	//构造函数

	virtual ~shape_base() {}
	//析构函数（虚析构函数）
	//如果需要删除可能指向派生类对象的基类指针，则需要声明一个虚拟析构函数，以确保派生类空间完全释放

	virtual void get_Area() = 0;
	virtual void get_Circ() = 0;
	//成员函数：计算面积、计算周长（纯虚函数）
	//由于不知道形状，此处声明为纯虚函数，派生类重载时给出定义
	//由于声明了纯虚函数，此处shape_base类成为抽象基类，不能创建shape_base类对象
	//如果

	double Area() const { return area; }
	double Circ() const { return circ; }
	//访问器函数：面积、周长

protected:
	double area, circ;
	//成员变量：面积、周长

	virtual shape_base * clone() const = 0;
	//成员函数：克隆（纯虚函数）
	//因为该类是个抽象基类，不能定义该类对象，所以此函数无法被定义，故声明为纯虚函数
};
class Triangle : public shape_base
{
public:
	Triangle() : a(0), b(0), c(0) {}
	Triangle(std::istream& input) { input >> a >> b >> c; }
	//构造函数

	void get_Area()
	{
		if (a <= 0 || b <= 0 || c <= 0 || a + b <= c || a - b >= c)
			throw std::domain_error("invalid side length"); //如果参数不符合要求，抛出异常
		get_Circ(); //这个函数也会抛出异常，此处宜把异常回传给使用者进行处理，故此处不作处理
		double p = circ / 2;
		area = sqrt(p * (p - a) * (p - b) * (p - c));
	}
	void get_Circ()
	{
		if (a <= 0 || b <= 0 || c <= 0 || a + b <= c || a - b >= c)
			throw std::domain_error("invalid side length");
		circ = a + b + c;
	}
	//成员函数：面积、周长

protected:
	Triangle * clone() const { return new Triangle(*this); }
	//成员函数：克隆
	//派生类重载基类函数时一般要求参数列表和返回类型完全相同，但当基类函数返回的是基类指针时应返回派生类指针（返回类型协变）

private:
	double a, b, c;
	//成员变量：三边边长
};
class Rectangle : public shape_base
{
public:
	Rectangle() : a(0), b(0) {}
	Rectangle(std::istream& input) { input >> a >> b; }
	//构造函数

	void get_Area()
	{
		if (a <= 0 || b <= 0) throw std::domain_error("invalid side length");
		area = a * b;
	}
	void get_Circ()
	{
		if (a <= 0 || b <= 0) throw std::domain_error("invalid side length");
		circ = 2 * (a + b);
	}
	//成员函数：面积、周长

protected:
	Rectangle * clone() const { return new Rectangle(*this); }
	//成员函数：克隆

private:
	double a, b;
	//成员变量：长和宽
};
class Circle : public shape_base
{
public:
	Circle() : r(0) {}
	Circle(std::istream& input) { input >> r; }
	//构造函数

	void get_Area()
	{
		if (r <= 0) throw std::domain_error("invalid side length");
		area = pi * r * r;
	}
	void get_Circ()
	{
		if (r <= 0) throw std::domain_error("invalid side length");
		circ = 2 * pi * r;
	}
	//成员函数：面积、周长

protected:
	Circle * clone() const { return new Circle(*this); }
	//成员函数：克隆

private:
	double r;
	//成员变量：半径
};

//句柄类，消除类型依赖，从而在维持易用性的前提下使得程序能够对各类shape_base派生类对象进行处理
class Shape
{
public:
	Shape() : sp(0) {}
	Shape(std::istream& input) : sp(0) { read(input);	}
	//构造函数

	Shape(const Shape&);
	Shape& operator = (const Shape&);
	~Shape() { delete sp; }
	//涉及空间资源分配的类，需要定义复制、赋值、析构函数
	
	std::istream& read(std::istream&);
	//成员函数：读入

	void get_Area() const
	{
		if (sp) sp->get_Area();
		else throw std::runtime_error("uninitialized shape");
	}
	void get_Circ() const
	{
		if (sp) sp->get_Circ();
		else throw std::runtime_error("uninitialized shape");
	}
	//成员函数：计算面积、计算周长

	double Area() const
	{
		if (sp) return sp->Area();
		else throw std::runtime_error("uninitialized shape");
	}
	double Circ() const
	{
		if (sp) return sp->Circ();
		else throw std::runtime_error("uninitialized shape");
	}
	//成员函数：面积、周长
	//由于shape_base类的面积和周长已经定义为虚函数，所以可以实现动态绑定
	//原则上，不需要修改内部对象的成员函数都应该加const限定符，以便该类const对象可以调用
private:
	shape_base * sp;
};
