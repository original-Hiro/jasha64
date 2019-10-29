#include <iostream>
#include <algorithm>
using namespace std;

int f[60007];

int main()
{
	int n, i;
	cin >> n;
	for (i = 1; i <= n; i++) cin >> f[i];
	
	int m = (n << 1) - 1, Res = 0, t1 = 1, t2 = n + 1, t, s[2] = {0};
	sort(f + 1, f + n + 1);
	for (i = n + 1; i <= m; i++)
	{
		for (t = 0; t < 2; t++)
			if ((t2 < i && f[t2] < f[t1]) || t1 > n) s[t] = f[t2++];
			else s[t] = f[t1++];
		Res += (f[i] = s[0] + s[1]);
	}
	
	cout << Res << endl;
	
	return 0;
}

