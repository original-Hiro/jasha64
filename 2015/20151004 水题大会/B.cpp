#include <iostream>
using namespace std;

inline bool is(int i)
{
	int x = i, r = 0, c;
	while (x > 0)
	{
		c = x % 10;
		r += c * c * c;
		x /= 10;
	}
	return r == i;
}

int main()
{
	int i;
	
	for (i = 100; i < 1000; ++i)
		if (is(i)) cout << i << endl;
	
	return 0;
}

