#include <iostream>
#include <algorithm>
using namespace std;

const int N = 100007;
int a[N], b[N], Cnt[N], n, m;

inline int Hash(int x) {return lower_bound(a, a + m, x) - a;}

int main()
{
	ios::sync_with_stdio(false);
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];
	
	copy(a, a + n, b);
	sort(a, a + n);
	m = unique(a, a + n) - a;
	for (int i = 0; i < n; i++) ++Cnt[Hash(b[i])];
	
	long long Res;
	const int c[] = {Hash(a[0]), Hash(a[1]), Hash(a[2])};
	if (Cnt[c[0]] == 1)
	{
		if (Cnt[c[1]] == 1) Res = (long long)Cnt[c[0]] * Cnt[c[1]] * Cnt[c[2]];
		else Res = (long long)Cnt[c[1]] * (Cnt[c[1]] - 1) / 2 * Cnt[c[0]];
	}
	else if (Cnt[c[0]] == 2) Res = (long long)Cnt[c[0]] * (Cnt[c[0]] - 1) / 2 * Cnt[c[1]];
	else Res = (long long)Cnt[c[0]] * (Cnt[c[0]] - 1) / 2 * (Cnt[c[0]] - 2) / 3;
	cout << Res << endl;
	
	return 0;
}

