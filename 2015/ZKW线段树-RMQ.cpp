#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int f[1 << 20 | 1];

int main()
{
	int m, n, q, i;
	
	cin >> n;
	m = 1;
	while (m <= n + 1) m <<= 1;
	for (i = m + 1; i <= m + n; ++i) scanf("%d", &f[i]);
	Build();
	
	cin >> q;
	while (q--)
	{
		
	}
	
	return 0;
}

