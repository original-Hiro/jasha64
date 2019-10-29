#include <stdlib.h>

int main()
{
	int** a = (int**)malloc(sizeof(int*) * 4);
	a[0] = (int*)malloc(sizeof(int) * 2);
	for (int i = 1; i < 3; i++) a[i] = (int*)malloc(sizeof(int) * 3) - (i-1);
	a[3] = (int*)malloc(sizeof(int) * 2) - 2;
	
	free(a[0]);
	for (int i = 1; i < 3; i++) free(a[i] + i-1);
	free(a[3] + 2);
	free(a);
	
	return 0;
}

