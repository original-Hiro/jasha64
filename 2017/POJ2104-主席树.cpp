#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

const int N = 100007, MAXM = 3500007;
int a[N], n;

int m, h[N];
void Init_Hash()
{
	copy(a + 1, a + n + 1, h + 1);
	sort(h + 1, h + n + 1);
	m = unique(h + 1, h + n + 1) - (h + 1);
}
inline int Hash(int x) {return lower_bound(h + 1, h + m + 1, x) - h;}

int Cnt, t[MAXM], rt[N], ls[MAXM], rs[MAXM];
int Build(int l, int r)
{
	int o = ++Cnt;
	t[o] = 0;
	if (l < r)
	{
		int m = (l + r) >> 1;
		ls[o] = Build(l, m); rs[o] = Build(m + 1, r);
	}
	return o;
}
int Modify(const int i, const int x)
{
	int New = ++Cnt;
	int Ret = New;
	int o = rt[i - 1], l = 1, r = m;
	while (l < r)
	{
		t[New] = t[o] + 1;
		int m = (l + r) >> 1;
		if (x <= m)
		{
			rs[New] = rs[o]; ls[New] = ++Cnt;
			New = ls[New]; o = ls[o];
			r = m;
		}
		else {
			ls[New] = ls[o]; rs[New] = ++Cnt;
			New = rs[New]; o = rs[o];
			l = m + 1;
		} 
	}
	t[New] = t[o] + 1;
	return Ret;
}
int Query(int ll, int rr, int k)
{
	int nr = rt[rr], nl = rt[ll];
	int l = 1, r = m;
	while (l < r)
	{
		int m = (l + r) >> 1;
		int d = t[ls[nr]] - t[ls[nl]];
		if (d >= k) {nr = ls[nr]; nl = ls[nl]; r = m;}
		else {k -= d; nr = rs[nr]; nl = rs[nl]; l = m + 1;}
	}
	return h[l];
}

int main()
{
	int q;
	
	while (cin >> n >> q)
	{
		Cnt = 0;
		
		for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
		
		Init_Hash();
		rt[0] = Build(1, m);
		for (int i = 1; i <= n; i++) rt[i] = Modify(i, Hash(a[i]));
		
		int a, b, c;
		while (q--)
		{
			scanf("%d%d%d", &a, &b, &c);
			printf("%d\n", Query(a - 1, b, c));
		}
	}
	
	return 0;
}

