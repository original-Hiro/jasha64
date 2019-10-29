#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;

int main()
{
	int T, Res, n, m;
	bool Flag = false;
	
	cin >> T;
	while (T--)
	{
		Res = 0;
		Flag = false;
		
		scanf("%d%d", &n, &m);
		
		if (n > 1 && m > 1)
		{
			if (n > m)
			{
				Res += m;
				n -= m - 1;
				m = 1;
			}
			else {
				Res += n;
				m -= n - 1;
				n = 1;
			}
			Flag = true;
		}
		if (!Flag)
		{
			if (m > 2) m |= 1;
			else if (n > 2) n |= 1;
		}
		if (m > 1)
		{
			if (m <= 2) Res += m - 1;
			else Res += ((m - 3) >> 1) + 2;
		}
		else if (n > 1)
		{
			if (n <= 2) Res += n - 1;
			else Res += ((n - 3) >> 1) + 2;
		}
		
		printf("%d\n", Res);
	}
	
	return 0;
}

