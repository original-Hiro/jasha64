#include <iostream>
#include <cstdio>
#include <cctype>
using namespace std;

int main()
{
	int d, t;
	char c;
	
	cin >> d;
	do c = getchar(); while (!isalpha(c));
	while (isalpha(c))
	{
		t = c - 'a';
		t = (t + d + 26) % 26;
		c = t + 'a';
		putchar(c);
		c = getchar();
	}
	
	return 0;
}

