#include <iostream>
using namespace std;

int sum(int* a, unsigned len)
{
	int i, sum = 0;
	for (i = 0; i <= len - 1; i++) sum += a[i];
	return sum;
}

int main()
{
	int a[1];
	sum(a, 0);
	
	return 0;
}

