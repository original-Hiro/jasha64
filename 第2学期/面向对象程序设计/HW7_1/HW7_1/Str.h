#pragma once
//确保头文件只被编译一次
#include "Vec.h"
#include <algorithm>
#include <vector>
#include <cstring>

class Str
{
public:
	typedef Vec<char>::size_type size_type;
	//类型定义

	Str() {}
	Str(size_type n, char c = 0) :data(n, c) {}
	Str(const char* c) { std::copy(c, c + strlen(c), std::back_inserter(data)); }
	template <class In> Str(In b, In e) { std::copy(b, e, std::back_inserter(data)); }
	//构造函数

	size_type size() const { return data.size(); }
	//成员函数：长度

	char& operator [] (int i) { return data[i]; }
	const char& operator [] (int i) const { return data[i]; }
	//重载索引运算符

	friend std::istream& operator >> (std::istream&, Str&);
	friend std::ostream& operator << (std::ostream&, const Str&);
	//重载流输入输出运算符
	//因为输出流运算符不直接访问private成员，可以不声明成友元函数
	//这里考虑到把输入输出运算符放在一起更整洁，所以仍然把它声明成有元含税

	Str operator += (const Str& rhs)
	{
		copy(rhs.data.begin(), rhs.data.end(), std::back_inserter(data));
		return *this;
	}
	//重载复合赋值号+=
private:
	Vec<char> data;
};
//结构体定义的最后应输入分号结束
Str operator + (const Str&, const Str&);
//重载连接运算符
//头文件中不应包含可执行内容
//因为不需要访问private成员，所以不需要声明成友元函数