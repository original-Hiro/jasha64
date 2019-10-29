#include <fstream>
using namespace std;

ifstream cin("magic.in");
ofstream cout("magic.out");
int a[40][40];

int main()
{
	int n, i, j, x, y;
	
	cin >> n;
	
	a[x = 1][y = (n + 1) >> 1] = 1;
	for (i = 2; i <= n * n; ++i)
	{
		if (x == 1 && y != n) {x = n; ++y;} 
		else if (x != 1 && y == n) {--x; y = 1;}
		else if (x == 1 && y == n) ++x;
		else if (!a[x - 1][y + 1]) {--x; ++y;}
		else ++x;
		a[x][y] = i;
	}
	
	for (i = 1; i <= n; ++i)
	{
		cout << a[i][1];
		for (j = 2; j <= n; ++j) cout << ' ' << a[i][j];
		cout << endl;
	}
	
	return 0;
}

