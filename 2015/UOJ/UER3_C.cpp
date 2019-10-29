#include <iostream>
using namespace std;

typedef const int& int_;
int f[37];

struct Edge
{
	int l, r;
	
	friend istream& operator >> (istream& cin, Edge& a)
	{
		cin >> a.l >> a.r;
		return cin;
	}
} e[37];

int Find(int_ x)
{
	if (f[x] != x) return f[x] = Find(f[x]);
	return x;
}

int main()
{
	int n, k, i, Res = 0, S;
	bool OK;
	
	cin >> n >> k;
	if (n + k > 30) {cout << 0 << endl; return 0;}
	for (i = 0; i < n + k - 1; i++) cin >> e[i];
	
	for (S = 0; S < (1 << (n + k - 1)); ++S)
	{
		for (i = 1; i <= n; ++i) f[i] = i;
		for (i = 0; i < n + k - 1; ++i)
			if (!(S & (1 << i))) f[Find(e[i].l)] = Find(e[i].r);
		OK = false;
		for (i = 1; i <= n; ++i)
			if (Find(i) == i)
			{
				if (OK) {OK = false; break;}
				else OK = true;
			}	
		if (OK) Res = (Res + 1) % 998244353;
	}
	
	cout << Res << endl;
	
	return 0;
}

