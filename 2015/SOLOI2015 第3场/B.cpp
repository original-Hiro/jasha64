#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;

const int N = 107;
int n, k, f[N][N][307], DFN[N], Low[N], idx;
bool ins[N], Del[N], G[N][N];
struct Target
{
	int Cost, Value, Left, Right;
	Target() {Left = Right = -1;}
} a[N];
stack<int> s;

void Tarjan(int x)
{
	int i = a[x].Left;
	
	DFN[x] = Low[x] = ++idx;
	s.push(x); ins[x] = true;
	for (i = 1; i <= n; ++i)
		if (G[x][i])
			if (!DFN[i]) {Tarjan(i); Low[x] = min(Low[x], Low[i]);}
			else if (ins[i]) Low[x] = min(Low[x], DFN[i]);
	if (Low[x] == DFN[x])
		do {i = s.top(); s.pop(); Del[i] = true;} while (i != x);
}
int DP(int x, int n, int m)
{
	if (x < 0 || !n) return 0;
	if (f[x][n][m]) return f[x][n][m];
	if (m <= a[x].Cost) return 0;
	for (int i = 0; i < n; ++i)
		for (int j = 1; j < m; ++j)
			f[x][n][m] = min(f[x][n][m], a[x].Value + DP(a[x].Left, i, m - j) + DP(a[x].Right, n - i - 1, j));
	if (!m) f[x][n][m] += k;
	return f[x][n][m];
}

int main()
{
	int i, j, m, p, q, r, c, c1, Res = 0;
	
	cin >> n >> m >> k >> p >> q >> r;
	for (i = 1; i <= n; ++i)
	{
		cin >> a[i].Cost >> a[i].Value >> c;
		while (c--) {cin >> c1; G[c][c1] = true;}
	}
	
	for (i = 1; i <= n; ++i)
		if (!DFN[i]) Tarjan(i);
	n = 0;
	for (i = 1; i <= n; ++i)
		if (!Del[i]) ++n;
	for (i = 1; i <= n; ++i)
		if (!Del[i])
			for (j = 1; j <= n; ++j)
				if (!Del[j] && G[i][j]) {a[j].Right = a[i].Left; a[i].Left = j;}
	
	if (m <= p)
		cout << max(Res - DP(0, n + 1, m), Res + q - DP(0, n + 1, m - p + r)) << endl;
	else cout << Res - DP(0, n, m) << endl;
	
	return 0;
}

