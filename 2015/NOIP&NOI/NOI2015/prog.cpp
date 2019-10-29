#include <iostream>
#include <algorithm>
#include <cstdio>
#include <map>
using namespace std;

const int N = 100007;
int f[N << 1], l[N], r[N], e[N], d[N << 1];
map<int, int> m;

int Find(const int& x)
{
	if (f[x] != x) return f[x] = Find(f[x]);
	return x;
}

int main()
{
	int T, n, k;
	int i, j;
	
	cin >> T;
	while (T--)
	{
		j = 0;
		cin >> n;
		for (i = 1; i <= n << 1; i++) f[i] = i;
		for (i = 1; i <= n; i++)
		{
			scanf("%d%d%d", &l[i], &r[i], &e[i]);
			d[++j] = l[i]; d[++j] = r[i];
		}
		
		sort(d + 1, d + j + 1);
		k = unique(d + 1, d + j + 1) - d;
		for (i = 1; i < k; i++) m[d[i]] = i;
		for (i = 1; i <= n; i++) {l[i] = m[l[i]]; r[i] = m[r[i]];}
		for (i = 1; i <= n; i++)
			if (e[i]) f[Find(l[i])] = Find(r[i]);
		
		for (i = 1; i <= n; i++)
			if (!e[i] && Find(l[i]) == Find(r[i])) break;
		if (i <= n && Find(l[i]) == Find(r[i])) {cout << "NO" << endl; continue;}
		cout << "YES" << endl;
	}
	
	return 0;
}

