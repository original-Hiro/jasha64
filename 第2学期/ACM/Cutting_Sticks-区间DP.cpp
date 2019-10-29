#include <iostream>
using namespace std;

const int N = 57;
int a[N], f[N][N];

int main()
{
	int l;
	while (cin >> l && l)
	{
		int n;
		cin >> n;
		for (int i = 1; i <= n; i++) cin >> a[i]; a[++n] = l;
		
		fill(f[0], f[0] + N*N, 1e9);
		for (int i = 0; i < n; i++) f[i][i+1] = 0;
		for (int k = 2; k <= n; k++)
			for (int i = 0; i+k <= n; i++)
				for (int j = i+1; j < i+k; j++)
					f[i][i+k] = min(f[i][i+k], f[i][j] + f[j][i+k] + a[i+k] - a[i]);
		
		cout << "The minimum cutting is " << f[0][n] << '.' << endl;
	}
	
	return 0;
}

