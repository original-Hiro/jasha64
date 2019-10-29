#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

const long long N = 1000007;
long long f[N], Spc[N];

int main()
{
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	
	long long ChildrenN, MOD;
	long long i, Pos = 0, Cache, Sum = 0, Res = 0;
	bool Flag = true;
	
	cin >> ChildrenN >> MOD >> f[1];
	Spc[1] = f[1];
	if (f[1] < 0) Pos = 1;
	for (i = 2; i <= ChildrenN; i++)
	{
		scanf("%lld", &Cache);
		f[i] = f[i - 1] + Cache;
		Spc[i] = max(Spc[i - 1], f[i] - f[Pos]);
		if (f[i] < f[Pos]) Pos = i;
	}
	
	if (Spc[1] >= 0) Flag = false;
	Res = (Spc[1] << 1) % MOD;
	for (i = 3; i <= ChildrenN; i++)
		if (Spc[i - 1] > 0)
		{
			if (Flag && Res >= Spc[1]) Flag = false;
			Res += Spc[i - 1];
			if (Res > 0) Res %= MOD;
		}
	if (Flag) Res = max(Res, Spc[1]);
	Res %= MOD;
	
	cout << Res << endl;
	
	return 0;
}

