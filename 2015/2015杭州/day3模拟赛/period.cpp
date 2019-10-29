#include <iostream>
#include <cstdio>
#include <cctype>
using namespace std;

char c[1000007];

int main()
{
	int n, i, j, k, t = 1;
	bool Appropriate;
	
	cin >> n;
	while (!isalpha(c[1] = getchar())) ;
	for (i = 2; i <= n; i++)
	{
		c[i] = getchar();
		if (i % t) continue;
		Appropriate = true;
		for (j = 0; j * t < i; j++)
			for (k = 1; k <= t; k++)
				if (c[j * t + k] != c[k])
				{
					Appropriate = false;
					if (i % (++t)) break;
					else j = 0;
				}
		if (Appropriate) printf("%d %d\n", i, i / t);
	}
	
	return 0;
}

