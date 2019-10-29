#include <iostream>
#include <algorithm>
using namespace std;

const int N = 107, M = 307;
struct Target {int Cost, Value;} a[N];
int f[M];

int main()
{
	int i, j, n, m, k, p, q, r, c, Res;
	
	cin >> n >> m >> k >> p >> q >> r;
	for (i = 1; i <= n; ++i)
	{
		cin >> a[i].Cost >> a[i].Value >> c;
		if (c) {cout << 0 << endl; return 0;}
	}
	
	for (i = 1; i <= n; ++i)
	{
		f[m] = max(f[m], f[m - a[i].Cost] + a[i].Value - k);
		for (j = m - 1; j >= a[i].Cost; --j)
			f[j] = max(f[j], f[j - a[i].Cost] + a[i].Value);
	}
	Res = max(f[m], f[m - 1]);
	if ((m -= p) >= 0)
	{
		fill(f, f + M, q);
		m += r;
		for (i = 1; i <= n; ++i)
		{
			f[m] = max(f[m], f[m - a[i].Cost] + a[i].Value - k);
			for (j = m - 1; j >= a[i].Cost; --j)
				f[j] = max(f[j], f[j - a[i].Cost] + a[i].Value);
		}
		Res = max(Res, max(f[m], f[m - 1]));
	}
	
	cout << Res << endl;
	
	return 0;
}

