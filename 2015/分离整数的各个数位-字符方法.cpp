#include <cstdio>
#include <cctype>
#include <stack>
using namespace std;

stack<char> Printer;

int main()
{
	char c;
	
	while (isdigit(c = getchar())) Printer.push(c);
	
	putchar(Printer.top()); Printer.pop();
	while (!Printer.empty())
	{
		c = Printer.top(); Printer.pop();
		putchar(' '); putchar(c);
	}
	
	return 0;
} 

