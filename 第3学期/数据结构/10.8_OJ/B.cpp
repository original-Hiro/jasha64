#include <iostream>
using namespace std;

int a[101][101];

int main()
{
	int n;
	cin >> n;
	
	int x = 1, y = 1, z = 1;
	a[1][1] = 1;
	while (z < n*n)
	{
		while (y < n && !a[x][y+1]) a[x][++y] = ++z;
		while (x < n && !a[x+1][y]) a[++x][y] = ++z;
		while (y > 1 && !a[x][y-1]) a[x][--y] = ++z;
		while (x > 1 && !a[x-1][y]) a[--x][y] = ++z;
	}
	
	for (int i = 1; i <= n; i++)
	{
		cout << a[i][1];
		for (int j = 2; j <= n; j++) cout << ' ' << a[i][j];
		cout << endl;
	}
	
	return 0;
}

