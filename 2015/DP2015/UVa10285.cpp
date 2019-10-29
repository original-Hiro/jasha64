#include <iostream>
#include <algorithm>
#include <string>
#include <cstdio>
#include <cstring>
using namespace std;

const int N = 107, dx[] = {0, -1, 1, 0}, dy[] = {-1, 0, 0, 1};
int r, c, a[N][N];
int f[N][N];

int DP(const int& x, const int& y)
{
	if (x < 1 || x > r || y < 1 || y > c) return 0;
	if (f[x][y]) return f[x][y];
	int i;
	for (i = 0; i < 4; i++)
		if (a[x][y] < a[x + dx[i]][y + dy[i]])
			f[x][y] = max(f[x][y], DP(x + dx[i], y + dy[i]));
	return ++f[x][y];
}

int main()
{
	int T;
	int i, j, Res;
	string Name;
	
	cin >> T;
	while (T--)
	{
		Res = 0;
		memset(f, 0, sizeof(f));
		
		cin >> Name >> r >> c;
		for (i = 1; i <= r; i++)
			for (j = 1; j <= c; j++) scanf("%d", &a[i][j]);
		
		for (i = 1; i <= r; i++)
			for (j = 1; j <= c; j++) Res = max(Res, DP(i, j));
		
		cout << Name << ": " << Res << endl;
	}
	
	return 0;
}

