#include <iostream>
#include <algorithm>
using namespace std;

typedef const int& int_;
const int INF = 1000000000, N = 10007;
int a[N], b[N], h[N], l[N];
int f[N][1007];

inline void Calc(int& a, int_ b) {if (a > b) a = b;}

int main()
{
	int n, m, k, i, j, Ans = INF;
	
	cin >> n >> m >> k;
	for (i = 0; i < n; ++i) cin >> a[i] >> b[i];
	for (i = 0; i < k; ++i)
	{
		cin >> j;
		cin >> l[j] >> h[j];
	}
	for (i = 0; i <= n; ++i)
		if (h[i] == 0) h[i] = m + 1;
		
	for (i = 0; i < n; ++i)
	{
		fill(f[i], f[i] + l[i] + 1, INF);
		fill(f[i] + h[i], f[i] + m + 1, INF);
		fill(f[i + 1], f[i + 1] + m + 1, INF);
		for (j = l[i] + 1; j < h[i]; ++j) Calc(f[i + 1][min(j + a[i], m)], f[i][j] + 1);
		for (j = 1; j <= m; ++j) Calc(f[i + 1][min(j + a[i], m)], f[i + 1][j] + 1);
		for (j = b[i] + 1; j <= m; ++j) Calc(f[i + 1][j - b[i]], f[i][j]);
	}
	fill(f[n], f[n] + l[n] + 1, INF);
	fill(f[n] + h[n], f[n] + m + 1,INF);
	
	Ans = *min_element(f[n], f[n] + m + 1);
	if (Ans != INF) cout << 1 << endl << Ans << endl;
	else {
		Ans = 0;
		for (i = 0; i <= n; ++i)
		{
			j = *min_element(f[i], f[i] + m + 1);
			if (j == INF) break;
			if (j != INF && h[i] != m + 1) ++Ans;
		}
		cout << 0 << endl << Ans << endl;
	}
	
	return 0;
}

