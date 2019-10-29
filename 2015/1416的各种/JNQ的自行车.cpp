#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

const int N = 507;
int h[N][N], n, m;
int idx[N][N], l[N], r[N], f[N];

void DFS(const int& r, const int& c, const int& id)
{
	if (r <= 0 || r > n || c <= 0 || c > m) return;
	if (idx[r][c] && r != m) return;
	idx[r][c] = id;
	if (h[r - 1][c] < h[r][c]) DFS(r - 1, c, id);
	if (h[r][c - 1] < h[r][c]) DFS(r, c - 1, id);
	if (h[r + 1][c] < h[r][c]) DFS(r + 1, c, id);
	if (h[r][c + 1] < h[r][c]) DFS(r, c + 1, id);
}
void Print1()
{
	cout << 0 << endl;
	int i, cnt = 0;
	for (i = 1; i <= m; i++)
		if (!idx[n][i]) cnt++;
	cout << cnt << endl;
}
void Print2()
{
	cout << 1 << endl;
	memset(idx, 0, sizeof(idx)); 
	int i, j;
	for (i = 1; i <= m; i++)
	{
		DFS(1, i, 1); 
		for (j = 1; j <= m; j++)
		{
			if (idx[n][j] && !idx[n][j - 1]) l[i] = j;
			if (idx[n][j] && !idx[n][j + 1]) {r[i] = j; break;}
		}
		memset(idx, 0, sizeof(idx));
	}
	fill(f + 1, f + N, 0x7fffffff);
	for (i = 1; i <= m; i++)
		for (j = 1; j <= m; j++)
			if (l[j] <= i && i <= r[j]) f[i] = min(f[i], f[l[j] - 1] + 1);
	cout << f[m] << endl;
}

int main()
{
	int i, j, cnt = 0, pos = 0;
	bool done;
	
	cin >> n >> m;
	for (i = 1; i <= n; i++)
		for (j = 1; j <= m; j++) cin >> h[i][j];
	
	while (pos != -1)
	{
		pos = -1;
		for (i = 1; i <= m; i++)
			if (h[1][i] > h[1][pos] && !idx[1][i]) pos = i;
		DFS(1, pos, ++cnt);
	}
	
	done = 1;
	for (i = 1; i <= m; i++)
		if (!idx[n][i]) {done = 0; break;}
	if (!done) Print1(); 
	else Print2();
	
	return 0;
}

