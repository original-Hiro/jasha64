#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;

typedef const int& int_;
const int N = 100007;
int f[N << 1], l[N], r[N], e[N];

int Find(int_ x)
{
	if (f[x] != x) return f[x] = Find(f[x]);
	return x;
}

int main()
{
	int T, n, i;
	
	cin >> T;
	while (T--)
	{
		cin >> n;
		for (i = 1; i < N << 1; ++i) f[i] = i;
		for (i = 1; i <= n; ++i) scanf("%d%d%d", &l[i], &r[i], &e[i]);
		
		for (i = 1; i <= n; ++i)
			if (e[i]) f[Find(l[i])] = Find(r[i]);
		
		for (i = 1; i <= n; ++i)
			if (!e[i] && Find(l[i]) == Find(r[i])) break;
		if (i <= n && Find(l[i]) == Find(r[i])) {cout << "NO" << endl; continue;}
		cout << "YES" << endl;
	}
	
	return 0;
}

