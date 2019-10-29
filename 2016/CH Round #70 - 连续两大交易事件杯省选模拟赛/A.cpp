#include <iostream>
#include <algorithm>
#include <set>
#include <map>
using namespace std;

const int N = 1000007, BASE = 10;
int n, a[N];

namespace One
{
	int b[17], Res = 17;
	set<long long> vis;
	map<int, int> m;
	void Pre()
	{
		int c[17];
		copy(a, a + n, c);
		sort(c, c + n);
		int k = unique(c, c + n) - c;
		for (int i = 0; i < k; i++) m[c[i]] = i;
		for (int i = 0; i < n; i++) a[i] = m[a[i]];
	}
	inline long long Hash(int* a)
	{
		long long Ret = 0;
		for (int i = 0; i < n; i++) Ret = Ret * BASE + a[i];
		return Ret;
	}
	inline bool Equal(int* b, int* c)
	{
		for (int i = 0; i < n; i++)
			if (c[i] != b[i]) return false;
		return true;
	}
	void DFS(int x, int* a)
	{
		if (x > n) return;
		if (Equal(b, a)) {Res = min(Res, x); return;}
		int c[17], d[17];
		copy(a, a + n, c);
		copy(c, c + n, d);
		for (int i = 1; i < n; i++)
			if (c[i] < c[i - 1])
			{
				c[0] = d[i]; 
				copy(d, d + i, c + 1); copy(d + i + 1, d + n, c + i + 1);
				long long v = Hash(c);
				if (vis.count(v)) continue;
				vis.insert(v);
				DFS(x + 1, c);
				vis.erase(v);
				copy(d, d + n, c);
			}
		for (int i = 1; i < n; i++)
			if (c[i] > c[i + 1])
			{
				c[n - 1] = d[i];
				copy(d, d + i, c); copy(d + i + 1, d + n, c + i);
				long long v = Hash(c);
				if (vis.count(v)) continue;
				vis.insert(v);
				DFS(x + 1, c);
				vis.erase(v);
				copy(d, d + n, c);
			}
	}
	void Work()
	{
		for (int i = 0; i < n; i++) cin >> a[i];
		Pre();
		copy(a, a + n, b);
		sort(b, b + n);
		DFS(0, a);
		cout << Res << endl;
	}
}
namespace Two
{
	int f[N];
	void Work()
	{
		for (int i = 1; i <= n; i++) cin >> a[i];
		f[1] = 1;
		for (int i = 2; i <= n; i++)
		{
			f[i] = f[i - 1];
			for (int j = 1; j < i; j++)
				if (a[i] >= a[j]) f[i] = max(f[i], f[j] + 1);
		}
		cout << n - f[n] << endl;
	}
}
namespace Three
{
	int c[N], f[N], Top;
	void Work()
	{
		for (int i = 1; i <= n; i++) cin >> a[i];
		fill(c, c + N, N);
		for (int i = 1; i <= n; i++)
		{
			int k = upper_bound(c, c + n, a[i]) - c;
			if (k > Top) ++Top;
			c[Top] = a[i];
			f[i] = Top + 1;
		}
		cout << n - f[n] << endl;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	
	cin >> n;
	
	if (n <= 10) One::Work();
	else if (n <= 1000) Two::Work();
	else Three::Work();
	
	return 0;
}

