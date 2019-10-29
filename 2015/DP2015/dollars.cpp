#include <iostream>
#include <iomanip>
#include <algorithm>
using namespace std;

const int N = 107;
double a[N], f[N][2];

int main()
{
	int n, i, j, c;
	
	cin >> n;
	for (i = 1; i <= n; ++i) {cin >> c; a[i] = c;}
	
	f[1][0] = 100.0; f[1][1] = a[1];
	for (i = 2; i <= n; ++i)
		for (j = 1; j < i; ++j)
		{
			f[i][0] = max(f[j][0], f[j][1] / a[i] * 100.0);
			f[i][1] = max(f[j][1], f[j][0] / 100.0 * a[i]);
		}
	
	cout << setiosflags(ios :: fixed) << setprecision(2) << f[n][0] << endl;
	
	return 0;
}

