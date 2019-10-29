#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;

const int N = 1007, M = 10007;
int d[N], Last[N], Come[N], Off[N], People[N], f[N], a[M], b[M], t[M];

int main()
{
	int n, m, k, i, j, p, Res = 0;
	
	cin >> n >> m >> k;
	for (i = 1; i < n; ++i) cin >> d[i];
	for (i = 0; i < m; ++i) {scanf("%d%d%d", &t[i], &a[i], &b[i]); Last[a[i]] = max(Last[a[i]], t[i]);}
	
	for (i = 1; i < n; ++i) Off[i] = max((Come[i] = Off[i - 1] + d[i - 1]), Last[i]);
	Come[n] = Off[n - 1] + d[n - 1];
	for (i = n - 1; i > 0; --i)
		if (Off[i + 1] == Last[i + 1]) f[i] = i + 1;
		else f[i] = f[i + 1];
	for (i = 0; i < m; ++i) ++People[b[i]];
	for (i = 1; i <= n; ++i) People[i] += People[i - 1];
	while (k--)
	{
		p = 0;
		for (i = 1; i <= n; ++i)
			if (d[i] > 0 && People[f[i]] - People[i] > People[f[p]] - People[p]) p = i;
		if (!p) break;
		--d[p];
		for (i = p + 1; i < f[p]; ++i) {--Come[i]; --Off[i];}
		--Come[f[p]];
		for (--i; i >= p; --i)
			if (Off[i + 1] == Last[i + 1]) f[i] = i + 1;
			else f[i] = f[i + 1];
	}
	
	for (i = 0; i < m; ++i) Res += Come[b[i]] - t[i];
	cout << Res << endl;
	
	return 0;
}

