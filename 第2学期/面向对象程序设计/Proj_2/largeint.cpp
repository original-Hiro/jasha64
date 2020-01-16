#include "largeint.h"
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <cctype>
using std::istream; using std::ostream;
using std::reverse;

largeint::largeint()
{
	v.push_back(0);
	v.push_back(0);
}
largeint::largeint(int n)
{
	if (n < 0) {v.push_back(1); n = -n;}
	else v.push_back(0);
	while (n > 0) {v.push_back(n % 10); n /= 10;}
}
largeint::largeint(size_type n, unsigned int val):v(n, val) //先用输入的数正向初始化vector 
{
	v.push_back(0); //再将符号位添加至末尾 
	reverse(v.begin(), v.end()); //最后反转整个vector，使符号位在最前面并使输入的数反向存储 
}

//这个函数注意一下实现方式，因为友元函数不是成员函数，所以不声明成largeint::operator>>，更不能在实现的地方加friend修饰符
istream& operator >> (istream& input, largeint& a)
{
	a.v.clear(); //清空现在存有的值 
	
	bool neg = 0; //是负数 
	char c;
	while (input.get(c) && !isdigit(c) && c != '-') ; //读入并丢弃所有无关字符 
	if (input)
	{
		if (c == '-') { neg = 1; input.get(c); } //读到了负号，则标记该数为负数，然后读入下一个字符 
		do a.v.push_back(c - '0');
		while (input.get(c) && isdigit(c)); //存储所有的数字 
		if (input) input.unget(); //如果后面还有其它输入内容，就把读到的内容放回输入流中 
	}
	
	a.v.push_back(neg); //将符号位添加至末尾 
	reverse(a.v.begin(), a.v.end()); //最后反转整个vector，使符号位在最前面并使输入的数反向存储 
	while (a.size() > 1 && a[a.size()] == 0) a.v.pop_back(); //抛弃前导0
	//数学上已经规定0和-0等价，我们在此对-0不作处理
	return input;
}
ostream& operator << (ostream& output, const largeint& a)
{
	if (a[0] == 1) output << '-'; //如果是负数，首先输出负号
	
	//由于数在vector内反向存储，此处逆向输出vector中存储的每一位 
	int siz = a.size();
	output << a[siz];
	for (int i = siz-1; i > 0; i--) output << a[i];
	
	return output;
}

bool operator < (const largeint& a, const largeint& b)
{
	if (a[0] == 1 && b[0] == 0) return true;
	if (a[0] == 0 && b[0] == 1) return false;
	if (a[0] == 1 && b[0] == 1) return -b < -a;
	//统一符号 
	
	if (a.size() != b.size()) return a.size() < b.size(); //位数相同，则较短的数较小
	for (int i = a.size(); i > 0; i--)
		if (a[i] != b[i]) return a[i] < b[i]; //位数不同，逐位比较 
	return false; //相等 
}

largeint absv(const largeint& a)
{
	largeint b(a); //复制副本 
	b[0] = 0; //修改符号 
	return b; //返回副本 
}

