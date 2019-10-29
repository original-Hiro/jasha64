#include <cstdio>

int main()
{
	double x = 21.001, y = 20.001, z = 1.0;
	for (int i = 0; i < 20; i++)
	{
		if (x - y == z) puts("equal");
		else puts("not equal");
		x += z; y += z;
		printf("%d, %f, %f\n", i, x, y);
	}

	return 0;
}

