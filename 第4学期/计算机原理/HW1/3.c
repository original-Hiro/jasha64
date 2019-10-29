#include <stdio.h>

void main()
{
	unsigned int a = 3;
	unsigned short b = 3;
	char c = -3;
	int d;

	d = (a > c) ? 1:0;
	printf("unsigned int is %d\n", d);
	d = (b > c) ? 1:0;
	printf("unsigned short is %d\n", d);
}

