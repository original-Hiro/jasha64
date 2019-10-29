#include <fstream>
#include <algorithm>
using namespace std;

ifstream cin("river.in");
ofstream cout("river.out");
const int N = 10007;
int a[107], f[N], res, l, s, t, m;
bool exist[N];

inline void Calc()
{
	int ofs = 0, k = s * t, dist, i, j;
	a[m + 1] = l;
	for (i = 1; i <= m + 1; i++)
	{
		dist = a[i] - a[i - 1] - ofs;
		if (dist > k) ofs += dist - k;
		a[i] -= ofs;
		exist[a[i]] = 1;
	}
	fill(f + 1, f + a[m + 1] + t + 1, 105);
	for (i = 0; i < a[m + 1]; i++)
		for (j = s; j <= t; j++)
			f[i + j] = min(f[i + j], f[i] + exist[i + j]);
	
	res = *min_element(f + a[m + 1], f + a[m + 1] + t);
	cout << res << endl;
}

int main()
{
	int i;
	
	cin >> l >> s >> t >> m;
	
	for (i = 1; i <= m; i++) cin >> a[i];
	sort(a + 1, a + m + 1);
	
	if (s == t)
	{
		for (i = 1; i <= m; i++) if (a[i] % s == 0) res++;
		cout << res << endl;
	}
	else Calc();
	
	return 0;
}

