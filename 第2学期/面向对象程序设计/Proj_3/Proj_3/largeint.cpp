#include "largeint.h"
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <cctype>
using std::istream; using std::ostream;
using std::reverse;
using std::max;

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
largeint::largeint(size_type n, unsigned int val) :v(n, val)
{
	v.push_back(0);
	reverse(v.begin(), v.end());
}

istream& operator >> (istream& input, largeint& a)
{
	a.v.clear();
	
	bool neg = 0;
	char c;
	while (input.get(c) && !isdigit(c) && c != '-') ;
	if (input)
	{
		if (c == '-') { neg = 1; input.get(c); }
		do a.v.push_back(c - '0');
		while (input.get(c) && isdigit(c));
		if (input) input.unget();
	}
	
	a.v.push_back(neg);
	reverse(a.v.begin(), a.v.end());
	while (a.size() > 1 && a[a.size()] == 0) a.v.pop_back();
	return input;
}
ostream& operator << (ostream& output, const largeint& a)
{
	if (a[0] == 1) output << '-';
	
	int siz = a.size();
	output << a[siz];
	for (int i = siz-1; i > 0; i--) output << a[i];
	
	return output;
}

largeint operator + (const largeint& a, const largeint& b)
{
	if (a[0] && !b[0]) return b - (-a);
	if (!a[0] && b[0]) return a - (-b);
	if (a[0] && b[0]) return -(-a + (-b));
	//统一符号

	largeint c;
	c.v.clear(); //此处的c派特殊用途，我们需要一个完全未初始化的largeint对象，所以对其vector容器执行clear操作
	c.v.push_back(0); //因为已经统一符号，所以符号位为+
	for (largeint::size_type i = 1, g = 0;; i++)
	{
		if (g == 0 && i >= a.v.size() && i >= b.v.size()) break;
		int x = g; //从上一位进位而来的值，加到这一位
		if (i < a.v.size()) x += a[i];
		if (i < b.v.size()) x += b[i]; //两数对应位相加
		c.v.push_back(x % largeint::BASE);
		g = x / largeint::BASE; //处理这一位进位
	}
	return c;
}
largeint operator - (const largeint& a, const largeint& b)
{
	if (a[0] && !b[0]) return -(-a + b);
	if (!a[0] &&  b[0]) return a + (-b);
	if (a[0]  &&  b[0]) return (-b) - (-a);
	//统一符号
	if (a < b) return -(b - a);
	//为了实现方便，我们采取这种方式来确保下面a >= b

	largeint res; //由于构造函数的原因，已经有了一位初值为0的数位
	for (int i = 1; i < a.v.size(); i++)
	{
		res[i] += a[i]; //将被减数的当前位加到结果的当前位
		if (i < b.v.size()) res[i] -= b[i]; //当前位相减
		if (res[i] < 0) { res[i] += largeint::BASE; res.v.push_back(-1); } //如果需要借位，则将下一位初值设为-1
		else res.v.push_back(0); //否则下一位初值为0
	}
	while (res.size() > 1 && res.v.back() == 0) res.v.pop_back(); //消除前导0
	return res;
}

bool operator < (const largeint& a, const largeint& b)
{
	if (a[0] == 1 && b[0] == 0) return true;
	if (a[0] == 0 && b[0] == 1) return false;
	if (a[0] == 1 && b[0] == 1) return -b < -a;
	
	if (a.size() != b.size()) return a.size() < b.size();
	for (int i = a.size(); i > 0; i--)
		if (a[i] != b[i]) return a[i] < b[i];
	return false;
}

largeint absv(const largeint& a)
{
	largeint b(a);
	b[0] = 0;
	return b;
}


