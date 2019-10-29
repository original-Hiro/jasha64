#include <iostream>
#include <algorithm>
using namespace std;

const int N = 57;
int a[N], f[N][N];

int main()
{
	int l, n;
	int i, j, k;
	
	while (cin >> l && l)
	{
		fill(a, a + N, 0);
		cin >> n;
		for (i = 0; i <= n + 1; i++) fill(f[i], f[i] + n + 2, 0x7fffffff);
		for (i = 1; i <= n; i++) cin >> a[i];
		a[n + 1] = l;
		
		for (i = 0; i <= n; i++) f[i][i + 1] = 0;
		for (i = 2; i <= n + 1; i++)
			for (j = 0; j + i <= n + 1; j++)
				for (k = 1; k < i; k++)
					f[j][j + i] = min(f[j][j + i],
					f[j][j + k] + f[j + k][j + i] + a[j + i] - a[j]);
		
		cout << "The minimum cutting is " << f[0][n + 1] << '.' << endl;
	}
	
	return 0;
}

