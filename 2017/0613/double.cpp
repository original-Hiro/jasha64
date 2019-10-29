#include <iostream>
#include <algorithm>
using namespace std;

const int N = 11, MAXN = 27, MOD = 10007;
int f[N][N][MAXN];
char a[N][N];

inline int Todigit(char a) {return a == 0 ? 0 : a - 'a' + 1;}
//inline int Spc(int x, int y) {return x == 1 || y == 1 ? 0 : 1;}

int main()
{
	int T;
	int x, y;

	for (int i = 0; i < N; i++) f[i][0][0] = f[0][i][0] = 1;
	cin >> T;
	while (T--)
	{
		for (int i = 1; i < N; i++)
			for (int j = 1; j < N; j++)
				fill(f[i][j], f[i][j] + MAXN, 0);
		
		cin >> x >> y;
		for (int i = 1; i <= x; i++)
			for (int j = 1; j <= y; j++) cin >> a[i][j];
		
		for (int i = 1; i <= x; i++)
			for (int j = 1; j <= y; j++)
				if (a[i][j] != '.')
				{
					int l = Todigit(a[i][j]);
					for (int k1 = 0; k1 <= l; k1++)
						for (int k2 = 0; k2 <= l; k2++)
						{
							int sc = 0;
							for (int k3 = 0; k3 <= k1 && k3 <= k2; k3++) sc += f[i-1][j-1][k3];
							if (!sc) sc = 1;
							f[i][j][l] = (f[i][j][l] + f[i-1][j][k1] * f[i][j-1][k2] / sc % MOD) % MOD;
						}
//					int xc = 0, yc = 0, sc = 0;
//					for (int p = 0; p <= l; p++) xc += f[i-1][j  ][p];
//					for (int p = 0; p <= l; p++) yc += f[i  ][j-1][p];
//					for (int p = 0; p <= l; p++) sc += f[i-1][j-1][p];
//					f[i][j][l] = xc / sc * (yc % MOD) % MOD;
				}
				else {
					int l = max(1, max(Todigit(a[i-1][j]), Todigit(a[i][j-1])));
					for (int q = l; q < MAXN; q++)
					{
						for (int k1 = 0; k1 <= q; k1++)
							for (int k2 = 0; k2 <= q; k2++)
							{
								int sc = 0;
								for (int k3 = 0; k3 <= k1 && k3 <= k2; k3++) sc += f[i-1][j-1][k3];
								if (!sc) sc = 1;
								f[i][j][q] = (f[i][j][q] + f[i-1][j][k1] * f[i][j-1][k2] / sc % MOD) % MOD;
							}
//						int xc = 0, yc = 0, sc = 0;
//						for (int p = 0; p <= q; p++) xc += f[i-1][j  ][p];
//						for (int p = 0; p <= q; p++) yc += f[i  ][j-1][p];
//						for (int p = 0; p <= q; p++) sc += f[i-1][j-1][p];
//						f[i][j][q] = xc / sc * (yc % MOD) % MOD;
					}
				}
		
		int Res = 0;
		for (int i = 1; i < MAXN; i++) Res = (Res + f[x][y][i]) % MOD;
		cout << Res << endl;
//		cout << f[1][3][26] << ' ' << f[2][2][26] << ' ' << f[3][1][26] << ' ' << f[2][3][26] << ' ' << f[3][2][26] << ' ' << f[3][3][26] << endl;
	}
	
	return 0;
}

