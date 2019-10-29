#include <stdio.h>

void main()
{
	union NUM
	{
		int a;
		char b[4];
	} num;

	num.a = 0x87654321;
	printf("0x%X\n", num.b[1]);
	printf("0x%X\n", num.b[2]);	
}

