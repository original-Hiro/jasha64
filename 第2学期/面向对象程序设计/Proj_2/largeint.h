#pragma once
#include <iostream>
#include <vector>
#include <cstdlib>

class largeint
{
public:
	typedef std::vector<int>::size_type size_type;
	//类型定义 

	largeint();
	largeint(int);
	largeint(size_type, unsigned int);
	//构造函数 
	
	friend std::istream& operator >> (std::istream&, largeint&);
	friend std::ostream& operator << (std::ostream&, const largeint&);
	//重载流输入输出运算符 
	
	friend bool operator < (const largeint&, const largeint&);
	friend bool operator > (const largeint& a, const largeint& b) { return b < a; }
	friend bool operator <= (const largeint& a, const largeint& b) { return !(b < a); }
	friend bool operator >= (const largeint& a, const largeint& b) { return !(a < b); }
	friend bool operator != (const largeint& a, const largeint& b) { return a < b || b < a; }
	friend bool operator == (const largeint& a, const largeint& b) { return !(a < b) && !(b < a); }
	//重载关系运算符 
	
	friend largeint operator - (largeint a) { a[0] = !a[0]; return a; }
	//friend largeint absv(const largeint& a) {return a < 0 ? -a : a;} 这种写法简单但较慢
	friend largeint absv(const largeint&);
	//重载负号 及 函数：绝对值 
	//友元函数给非成员函数以成员函数的访问权限，因为绝对值函数需要访问largeint类的私有成员，我们把它声明成友元函数 
	//重载负号函数写成友元函数的原因是，它的唯一操作数是它的右操作数，所以不能写成成员函数

	size_type size() const {return v.size() - 1;}
	//成员函数：位数
private:
	std::vector<int> v;
	
	int& operator [] (int x) { return v[x]; }
	const int& operator [] (int x) const { return v[x]; }
	//重载索引运算符
	//此处为成员函数添加了索引运算符，但是不希望所有用户都有权限单独访问大整数某一位，所以声明为private 
};
