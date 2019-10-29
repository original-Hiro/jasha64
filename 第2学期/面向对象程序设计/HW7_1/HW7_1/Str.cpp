#include "Str.h"
#include <iostream>
#include <cctype>
using std::istream; using std::ostream;

istream& operator >> (istream& input, Str& a)
{
	a.data.clear(); //抹去a中已有的内容

	char c;
	while (input.get(c) && isspace(c)) ; //抛弃前导空格
	if (input)
	{
		do a.data.push_back(c);
		while (input.get(c) && !isspace(c)); //读入字符串的内容
		if (input) input.unget(); //如果读入了后续空格，把它放回输入流中
	}

	return input;
}
ostream& operator << (ostream& output, const Str& a)
{
	for (Str::size_type i = 0; i < a.size(); i++) output << a[i];
	return output;
}
Str operator + (const Str& a, const Str& b)
{
	Str r = a;
	r += b;
	return r;
}
