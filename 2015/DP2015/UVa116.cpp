#include <iostream>
#include <algorithm>
using namespace std;

const int N = 107, M = 17, INF = 10007;
int n, a[N][M];
int f[N][M], s[N][M], r[3];

int main()
{
	int m;
	int i, j, k, Pos, c;
	
	while (cin >> m >> n)
	{
		Pos = 0;
		
		for (i = 0; i < m; i++)
			for (j = 0; j < n; j++) cin >> a[j][i];
		
		for (i = 0; i < n - 1; i++) fill(f[i], f[i] + m + 1, INF);
		for (i = 0; i < m; i++) f[n - 1][i] = a[n - 1][i];
		for (i = n - 2; i >= 0; i--)
			for (j = 0; j < m; j++)
			{
				r[0] = j;
				r[1] = (j + 1) % m;
				r[2] = (j - 1 + m) % m;
				sort(r, r + 3);
				for (k = 0; k < 3; k++)
					if (f[i + 1][r[k]] + a[i][j] < f[i][j])
					{
						f[i][j] = f[i + 1][r[k]] + a[i][j];
						s[i][j] = r[k];
					}
			}
		
		for (i = 1; i < m; i++)
			if (f[0][i] < f[0][Pos]) Pos = i;
		cout << Pos + 1;
		c = s[0][Pos];
		for (i = 1; i < n; i++)
		{
			cout << ' ' << c + 1;
			c = s[i][c];
		}
		cout << endl << f[0][Pos] << endl;
	}
	
	return 0;
}

