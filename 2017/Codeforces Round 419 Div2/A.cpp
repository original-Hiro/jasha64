#include <cstdio>
using namespace std;

inline bool Good(int h, int m)
{
	int revm = 0;
	for (int i = 0; i < 2; i++)
	{
		revm = revm * 10 + m % 10;
		m /= 10;
	}
	return h == revm;
}

int main()
{
	int h, m, Res = 0;
	scanf("%d:%d", &h, &m);
	while (true)
	{
		if (Good(h, m)) break;
		++Res;
		if (++m == 60)
		{
			m = 0;
			if (++h == 24) h = 0;
		}
	}
	printf("%d\n", Res);
	
	return 0;
}

