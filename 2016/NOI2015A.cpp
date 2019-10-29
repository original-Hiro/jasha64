#include <iostream>
#include <cstdio>
#include <algorithm>
#include <map>
using namespace std;

const int N = 100007;
int a[N], b[N], c[N], d[N << 1], f[N << 1];
map<int, int> m;

int Find(int x)
{
	if (f[x] != x) return f[x] = Find(f[x]);
	return x;
}

int main()
{
	int T;
	
	cin >> T;
	while (T--)
	{
		int n;
		
		cin >> n;
		for (int i = 1; i <= n; i++) scanf("%d%d%d", &a[i], &b[i], &c[i]);
		
		copy(a + 1, a + n + 1, d);
		copy(b + 1, b + n + 1, d + n);
		sort(d, d + n + n);
		int k = unique(d, d + n + n) - d;
		m.clear();
		for (int i = 0; i < k; i++) m[d[i]] = i + 1;
		for (int i = 1; i <= n + n; i++) f[i] = i;
		for (int i = 1; i <= n; i++) {a[i] = m[a[i]]; b[i] = m[b[i]];}
		for (int i = 1; i <= n; i++)
			if (c[i] == 1) f[Find(a[i])] = Find(b[i]);
			
		int i;
		for (i = 1; i <= n; i++)
			if (c[i] == 0 && Find(a[i]) == Find(b[i])) {cout << "NO" << endl; break;}
		if (i == n + 1) cout << "YES" << endl;
	}
	
	return 0;
}

