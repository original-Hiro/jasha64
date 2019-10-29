#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

const int N = 10007, M = 1007, INF = 10000007;
int f[N][M], a[N], b[N], h[N], l[N];
bool p[N];

inline void Relax(int& a, int b) {if (a > b) a = b;}

int main()
{
	int n, m, k;
	
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++) scanf("%d%d", &a[i], &b[i]);
	for (int i = 0, c; i < k; i++) {scanf("%d", &c); p[++c] = true; scanf("%d%d", &l[c], &h[c]);}
	
	fill(f[2], f[2] + (N - 2) * M, INF);
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
			if (f[i][j] < INF) f[i + 1][min(j + a[i], m)] = f[i][j] + 1;
		for (int j = 1; j <= m; j++) Relax(f[i + 1][min(j + a[i], m)], f[i + 1][j] + 1);
		for (int j = b[i] + 1; j <= m; j++)
			Relax(f[i + 1][j - b[i]], f[i][j]);
		if (p[i + 1])
		{
			fill(f[i + 1] + 1, f[i + 1] + l[i + 1] + 1, INF);
			fill(f[i + 1] + h[i + 1], f[i + 1] + m + 1, INF);
		}
	}
	
	int Ans = INF;
	for (int j = 1; j <= m; j++) Ans = min(Ans, f[n + 1][j]);
	if (Ans == INF)
	{
		Ans = 0;
		cout << 0 << endl;
		for (int i = 1; i <= n; i++)
		{
			bool Pass = false;
			for (int j = 1; j <= m; j++)
				if (f[i][j] < INF) {Pass = true; break;}
			if (!Pass) {cout << Ans << endl; break;}
			if (p[i]) Ans++;
		}
	}
	else cout << 1 << endl << Ans << endl;
	
	return 0;
}

