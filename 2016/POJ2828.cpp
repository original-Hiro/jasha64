#include <iostream>
using namespace std;
#define lson o << 1, l, m
#define rson o << 1 | 1, m + 1, r

const int N = 200007;
int SG[1 << 19 | 1], p, v, Res[N], a[N], b[N];

inline void Pushup(int o) {SG[o] = SG[o << 1] + SG[o << 1 | 1];}
void Build(int o, int l, int r)
{
	if (l == r) {SG[o] = 1; return;}
	int m = (l + r) >> 1;
	Build(lson); Build(rson); Pushup(o);
}
void Insert(int o, int l, int r)
{
	if (l == r) {SG[o] = 0; Res[l] = v; return;}
	int m = (l + r) >> 1;
	if (SG[o << 1] < p) {p -= SG[o << 1]; Insert(rson);}
	else Insert(lson);
	Pushup(o);
}

int main()
{
	ios::sync_with_stdio(false);
	
	int n;
	while (cin >> n)
	{
		for (int i = 0; i < n; i++) {cin >> a[i] >> b[i]; ++a[i];}
		
		Build(1, 1, n);
		for (int i = n - 1; i >= 0; i--) {p = a[i]; v = b[i]; Insert(1, 1, n);}
		
		cout << Res[1];
		for (int i = 2; i <= n; i++) cout << ' ' << Res[i];
		cout << endl;
	}
	
	return 0;
}

