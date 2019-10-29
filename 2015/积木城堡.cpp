#include <iostream>
#include <cstdio>
using namespace std;

const int N = 107, H = 10007;
int a[N][N], c[H], t, Top[N], f[H];
bool v[H];

int main()
{
	int n, i, j, k, c1;
	
	cin >> n;
	for (i = 1; i <= n; ++i)
		while (scanf("%d", &j) && j != -1) a[i][++Top[i]] = j;
	
	for (i = 1; i <= n; ++i)
	{
		++f[0]; c[t = 1] = 0; v[0] = true;
		for (j = 1; j <= Top[i]; ++j)
		{
			c1 = t;
			for (k = 1; k <= c1; ++k)
				if (!v[c[k] + a[i][j]])
				{
					v[c[k] + a[i][j]] = true;
					++f[c[k] + a[i][j]];
					c[++t] = c[k] + a[i][j];
				}
		}
		fill(v, v + H, false);
		fill(c, c + H, 0);
	}
	
	for (i = H - 1; i >= 0; --i)
		if (f[i] == n) {cout << i << endl; return 0;}
	
	return 0;
}

