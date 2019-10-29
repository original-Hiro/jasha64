#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

char c[4];
struct Defence
{
	char op;
	int t;
} d[100007];

int main()
{
	int n, m, i;
	cin >> n >> m;
	for (i = 1; i <= n; i++)
	{
		scanf(" %s%d", c, &d[i].t);
		if (c[0] == 'A') d[i].op = '&';
		else if (c[0] == 'O') d[i].op = '|';
		else d[i].op = '^';
	}
	
	int j, Res = 0, c0, c1;
	bool Greater = false;
	for (i = 29; i >= 0; i--)
	{
		c0 = 0; c1 = 1 << i;
		for (j = 1; j <= n; j++)
			if (d[j].op == '&') {c0 &= d[j].t & (1 << i); c1 &= d[j].t & (1 << i);}
			else if (d[j].op == '|') {c0 |= d[j].t & (1 << i); c1 |= d[j].t & (1 << i);}
			else {c0 ^= d[j].t & (1 << i); c1 ^= d[j].t & (1 << i);}
		if (Greater) Res |= max(c0, c1);
		else if (m & (1 << i))
				if (c1 > c0) Res |= c1;
				else {Greater = true; Res |= c0;}
			else Res |= c0;
	}
	
	cout << Res << endl;
	
	return 0;
}

