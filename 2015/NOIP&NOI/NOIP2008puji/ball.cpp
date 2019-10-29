#include <fstream>
using namespace std;

ifstream cin("ball.in");
ofstream cout("ball.out");
int f[37][37];

int main()
{
	int n, m;
	int i, j;
	
	cin >> n >> m;
	
	f[1][1] = f[1][n - 1] = 1;
	for (i = 2; i <= m; i++)
		for (j = 0; j < n; j++)
			f[i][j] = f[i - 1][(j + 1) % n] + f[i - 1][(j - 1 + n) % n];
			
	cout << f[m][0] << endl;
	
	return 0;
}

