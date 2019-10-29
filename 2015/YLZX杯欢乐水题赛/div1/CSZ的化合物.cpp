#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

typedef const int& int_;
const int N = 5007;
int n, y, f[N], r[N], G[N][N], c[N][N];
bool d[N][N], v[N];
struct Arguments
{
	char c;
	int a, b;
} a[10007];

int Find(int_ x)
{
	if (f[x] != x) return f[x] = Find(f[x]);
	return x;
}
bool DFS(int_ x)
{
	if (G[r[x]][r[y]]) return true;
	
	v[r[x]] = true;
	for (int i = 1; i <= n; i++)
		if (!v[r[i]] && G[r[x]][r[i]])
		{
			v[r[i]] = true;
			if (DFS(r[i])) return true;
		}
	return false;
}

int main()
{
	int m, q, s, t, i, j, Res = 0;
	
	cin >> n >> m;
	while (m--)
	{
		scanf("%d%d", &s, &t);
		G[s][t] = G[t][s] = 1;
	}
	cin >> q;
	for (i = 0; i < q; ++i)
	{
		scanf(" %c", &a[i].c);
		if (a[i].c != 'Q') scanf("%d%d", &a[i].a, &a[i].b);
		if (a[i].c == 'D') d[a[i].a][a[i].b] = d[a[i].b][a[i].a] = true;
	}
	
	for (i = 1; i <= n; ++i) f[i] = i;
	for (i = 1; i <= n; ++i)
		for (j = 1; j <= n; ++j)
			if (G[i][j] && !d[i][j]) f[Find(i)] = Find(j);
	for (i = 1; i <= n; ++i) r[i] = Find(i);
	for (i = 1; i <= n; ++i) f[i] = i; 
	for (i = 1; i <= n; ++i)
		for (j = 1; j <= n; ++j)
			if (G[i][j]) f[Find(i)] = Find(j);
	for (i = 1; i <= n; ++i)
		if (Find(i) == i) ++Res;
	for (i = 1; i <= n; ++i)
		for (j = 1; j <= n; ++j)
			if (G[i][j] && r[i] != r[j]) ++c[r[i]][r[j]];
	memcpy(G, c, sizeof(G));
	
	for (i = 0; i < q; ++i)
		switch (a[i].c)
		{
			case 'A':
				y = r[a[i].b];
				memset(v, 0, sizeof(v));
				if (!DFS(r[a[i].a])) --Res;
				if (r[a[i].a] != r[a[i].b])
				{
					++G[r[a[i].a]][r[a[i].b]];
					++G[r[a[i].b]][r[a[i].a]];
				}
				break;
			case 'D':
				--G[r[a[i].a]][y = r[a[i].b]]; --G[r[a[i].b]][r[a[i].a]];
				memset(v, 0, sizeof(v));
				if (!DFS(r[a[i].a])) ++Res; break;
			case 'Q': printf("%d\n", Res);
		}
	
	return 0;
}

