#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
using namespace std;

const int N = 1007;
int a[N], d[N], s[N];

int main()
{
	int n, i, j, p, tot = 0;
	long long Res = 0x7fffffffffffffff, c;
	
	cin >> n;
	for (i = 1; i <= n; ++i) {scanf("%d%d", &a[i], &d[i]); tot += d[i]; s[i] = s[i - 1] + d[i];}
	
	for (i = 1; i <= n; ++i)
	{
		c = 0;
		for (j = 1; j <= n; ++j)
			c += min(abs(s[j - 1] - s[i - 1]), tot - abs(s[i - 1] - s[j - 1])) * a[j];
		if (c < Res) {Res = c; p = i;}
	}
	
	cout << p - 1 << ',' << Res << endl;
	
	return 0;
}

