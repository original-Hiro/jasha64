//SPOJ - transform the expression
//栈 
#include <iostream>
#include <cstdio>
#include <cstring>
#include <stack>
using namespace std;

inline int inp(char c) //priority in the stack
{
	switch (c)
	{
		case '$': return -1;
		case '(': return 0;
		case '+': case '-': return 1;
		case '*': case '/': return 2;
		default: return 3; //case '^'
	}
}
inline int exp(char c) //priority out of the stack
{
	switch (c)
	{
		case '+': case '-': return 1;
		case '*': case '/': return 2;
		default: return 4; //case '^'
	}
}
//老板说可以通过给括号也设定优先级来减少分类讨论的复杂程度（几种情况可以合并）， 
//但是这种写法会降低程序可读性并增加理解难度，此处不予采用 

int main()
{
	//ios::sync_with_stdio(false);
	//一开始由于加了这句，导致一直WA
	//再次强调，如果想要流输入输出和标准输入输出都用，不要关闭流同步 
	 
	int n;
	cin >> n;
	while (n--)
	{
		char c[401];
		cin >> c;
		int len = strlen(c);
		stack<char> s; s.push('$');
		for (int i = 0; i < len; i++)
		{
			if (isalpha(c[i])) putchar(c[i]); //遇到操作数：直接输出 
			else if (c[i] == '(') s.push(c[i]); //遇到左括号：直接入栈 
			else if (c[i] == ')') //遇到右括号：把上一个左括号以后入栈的操作符依次出栈并输出，然后左括号出栈 
			{
				while (s.top() != '(') {putchar(s.top()); s.pop();}
				s.pop();
			}
			else { //其他：先将前面所有高优先级或同优先级操作符依次出栈输出，然后当前操作符入栈 
				while (exp(c[i]) <= inp(s.top())) {putchar(s.top()); s.pop();}
				s.push(c[i]);
			}
		}
		while (s.top() != '$') {putchar(s.top()); s.pop();}
		cout << endl;
	}
	
	return 0;
}

