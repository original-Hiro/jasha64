#include <iostream>
#include <algorithm>
using namespace std;

const int N = 1000007;
bool f[N], d[N];

int main()
{
	int n, m, i, j, a, Res = 0;
	
	cin >> n >> m;
	if (n > N) {cout << 0 << endl; return 0;}
	fill(f + 1, f + n, true);
	for (i = 1; i <= m; ++i)
	{
		cin >> a;
		fill(d + 1, d + n, false);
		for (j = a; !d[j]; j = (j + a) % n) {d[j] = true; f[j] = false;}
	}
	
	for (i = 1; i < n; ++i)
		if (f[i]) ++Res;
	cout << Res << endl;
	
	return 0;
}

