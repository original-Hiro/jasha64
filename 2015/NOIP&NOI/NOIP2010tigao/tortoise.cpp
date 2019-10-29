#include <fstream>
#include <algorithm>
using namespace std;

ifstream cin("tortoise.in");
ofstream cout("tortoise.out");
const int N = 47;
int a[357], num[4], f[N][N][N][N];

int main()
{
	int n, m;
	int i, cache, i1, i2, i3;
	
	cin >> n >> m;
	for (i = 0; i < n; i++) cin >> a[i];
	for (i = 0; i < m; i++)
	{
		cin >> cache;
		num[cache - 1]++;
	}
	
	for (i = 0; i <= num[0]; i++)
		for (i1 = 0; i1 <= num[1]; i1++)
			for (i2 = 0; i2 <= num[2]; i2++)
				for (i3 = 0; i3 <= num[3]; i3++)
				{
					if (i) f[i][i1][i2][i3] = max(f[i][i1][i2][i3], f[i - 1][i1][i2][i3]);
					if (i1) f[i][i1][i2][i3] = max(f[i][i1][i2][i3], f[i][i1 - 1][i2][i3]);
					if (i2) f[i][i1][i2][i3] = max(f[i][i1][i2][i3], f[i][i1][i2 - 1][i3]);
					if (i3) f[i][i1][i2][i3] = max(f[i][i1][i2][i3], f[i][i1][i2][i3 - 1]);
					f[i][i1][i2][i3] += a[i + 2 * i1 + 3 * i2 + 4 * i3];
				}
	
	cout << f[num[0]][num[1]][num[2]][num[3]] << endl;
	
	return 0;
}

