#include <cstdio>
using namespace std;

int main()
{
	freopen("9.in", "w", stdout);
	
	int i;
	for (i = 1; i <= 1000; ++i) putchar('1');
	putchar('0');
	for (++i; i <= 2000; ++i) putchar('1');
	putchar('\n');
	for (i = 1; i <= 2000; ++i) putchar('1');
	
	return 0;
} 

