#include <iostream>
using namespace std;

const int N = 100007, MAXM = 1 << 18 | 1;
int a[N];
int ll, rr, v;

#define lo o << 1
#define ro o << 1 | 1
#define lson o << 1, l, (l + r) >> 1
#define rson o << 1 | 1, ((l + r) >> 1) + 1, r
long long sumv[MAXM];
int addv[MAXM];
void Maintain(int o, int l, int r)
{
	sumv[o] = 0;
	if (r > l) sumv[o] = sumv[lo] + sumv[ro];
	else sumv[o] = a[l];
	sumv[o] += (long long)addv[o] * (r-l+1);
}
void Build(int o, int l, int r)
{
	addv[o] = 0;
	if (l == r) sumv[o] = a[l];
	else {
		Build(lson); Build(rson);
		sumv[o] = sumv[lo] + sumv[ro];
	}
}
void Add(int o, int l, int r)
{
	if (ll <= l && r <= rr) addv[o] += v;
	else {
		int m = (l + r) >> 1;
		if (ll <= m) Add(lson);
		if (rr >  m) Add(rson);
	}
	Maintain(o, l, r);
}
long long sum;
void Query(int o, int l, int r, long long add)
{
	if (ll <= l && r <= rr) {sum += sumv[o] + add * (r-l+1); return;}
	int m = (l + r) >> 1;
	if (ll <= m) Query(lson, add + addv[o]);
	if (rr >  m) Query(rson, add + addv[o]);
}

int main()
{
	int n, q;
	
	ios::sync_with_stdio(false);
	while (cin >> n >> q)
	{
		for (int i = 1; i <= n; i++) cin >> a[i];
		Build(1, 1, n);
		
		while (q--)
		{
			char argv;
			cin >> argv;
			if (argv == 'C')
			{
				cin >> ll >> rr >> v;
				Add(1, 1, n);
			}
			else {
				cin >> ll >> rr;
				sum = 0; Query(1, 1, n, 0);
				cout << sum << endl;
			}
		}
	}
	
	return 0;
}

