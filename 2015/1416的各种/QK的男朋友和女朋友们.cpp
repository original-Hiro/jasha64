#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const long long N = 1000007;
long long f[N], Like[N];
char Name[N][100];

int main()
{
	long long n, MAXLOVE;
	long long i, Pos = 0, Cache, Love = 0;
	bool Flag = true;
	
	cin >> n >> MAXLOVE >> Name[1] >> f[1];
	Like[1] = f[1];
	if (f[1] < 0) Pos = 1;
	for (i = 2; i <= n; i++)
	{
		scanf(" %s%lld", &Name[i], &Cache);
		f[i] = f[i - 1] + Cache;
		Like[i] = max(Like[i - 1], f[i] - f[Pos]);
		if (f[i] < f[Pos]) Pos = i;
	}
	
	if (Like[1] >= 0) Flag = false;
	Love = (Like[1] << 1) % MAXLOVE;
	Pos = 2;
	for (i = 3; i <= n; i++)
		if (Like[i - 1] >= 0)
		{
			Love += Like[i - 1];
			if (Flag && Love >= Like[1]) Flag = false;
			Pos = i;
			if (Love > 0) Love %= MAXLOVE;
		}
	if (Flag && Like[1] > Love)
	{
		Love = Like[1] % MAXLOVE;
		Pos = 1;
	}
	
	cout << Name[Pos] << endl << Love << endl;
	
	return 0;
}

