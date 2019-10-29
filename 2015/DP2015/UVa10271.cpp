#include <iostream>
#include <algorithm>
using namespace std;

const int N = 5007;
int a[N], c[N];
long long f[N][1017];

int main()
{
	int T, n, k, i, j;
	
	cin >> T;
	while (T--)
	{
		cin >> k >> n; k += 8;
		for (i = n; i >= 1; --i) cin >> a[i];
		for (i = 3; i <= n; ++i) c[i] = (a[i] - a[i - 1]) * (a[i] - a[i - 1]);
		
		f[3][1] = c[3];
		for (i = 4; i <= n; ++i)
			for (j = 1; j <= k && j * 3 <= i; ++j)
			{
				f[i][j] = f[i - 2][j - 1] + c[i];
				if (i % 3 || j * 3 < i) f[i][j] = min(f[i][j], f[i - 1][j]);
			}
		
		cout << f[n][k] << endl;
	}
	
	return 0;
}

