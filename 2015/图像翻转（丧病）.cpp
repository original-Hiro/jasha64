#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cctype>
using namespace std;

const int N = 107;
int a[N][N], c[N][N];

int main()
{
	int m, n, i, j;
	cin >> m >> n;
	for (i = 1; i <= m; ++i)
		for (j = 1; j <= n; ++j) cin >> a[i][j];
	
	
	char C;
	while (!isalpha(C)) C = getchar();
	while (isalpha(C))
	{
		if (C == 'A')
		{
			for (i = 1; i <= m; ++i)
				for (j = 1; j <= n; ++j) c[j][m - i + 1] = a[i][j];
			swap(m, n);
		}
		else if (C == 'B')
		{
			for (i = 1; i <= m; ++i)
				for (j = 1; j <= n; ++j) c[n - j + 1][i] = a[i][j];
			swap(m, n);
		}
		else if (C == 'C')
			for (i = 1; i <= m; ++i)
				for (j = 1; j <= n; ++j) c[i][n - j + 1] = a[i][j];
		else for (i = 1; i <= m; ++i)
				for (j = 1; j <= n; ++j) c[m - i + 1][j] = a[i][j];
		memcpy(a, c, sizeof(c));
		C = getchar();
	}
	
	
	for (i = 1; i <= m; ++i)
	{
		cout << a[i][1];
		for (j = 2; j <= n; ++j) cout << ' ' << a[i][j];
		cout << endl;
	}
	
	return 0;
}

