#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const int N = 307, INF = 300007;
int f[N][N], n, d, e[N][N];
bool G[N][N], v[N];
vector<int> r;
vector<vector<int> > Roadlist;

bool DFS(int x)
{ 
	v[x] = true;
	if (G[x][d]) {r.push_back(x); return true;}
	for (int i = 1; i <= n; i++)
		if (G[x][i] && !v[i] && DFS(i)) {r.push_back(x); return true;}
	return false;
}

int main()
{
	int s, a, b, c, i;
	cin >> n;
	for (i = 1; i <= n; i++)
	{
		fill(f[i] + 1, f[i] + i, INF);
		fill(f[i] + i + 1, f[i] + n + 1, INF);
	}
	cin >> s;
	for (i = 1; i < n; i++)
	{
		cin >> a >> b >> c;
		f[a][b] = f[b][a] = c; G[a][b] = G[b][a] = true;
	}
	
	int j, k, t;
	for (k = 1; k <= n; k++)
		for (i = 1; i <= n; i++)
			for (j = 1; j <= n; j++) f[i][j] = min(f[i][j], f[i][k] + f[k][j]);
	k = 0;
	for (i = 1; i <= n; i++)
		for (j = i + 1; j <= n; j++)
			if (f[i][j] < INF) k = max(k, f[i][j]);
	for (i = 1; i <= n; i++)
		for (j = i + 1; j <= n; j++)
			if (f[i][j] == k)
			{
				r.push_back(j); d = j;
				fill(v, v + N, 0); DFS(i);
				Roadlist.push_back(r); r.clear();
			}
	int l, Res = INF;
	while (!Roadlist.empty())
	{
		r = Roadlist.back(); Roadlist.pop_back(); t = r.size();
		for (i = 0; i < t; i++)
			for (j = i; j < t; j++)
			{
				a = r[i]; b = r[j];
				if (f[a][b] > s) break;
				if (!e[a][b])
				{
					for (k = 1; k <= n; k++)
					{
						c = min(f[k][a], f[k][b]);
						for (l = i + 1; l <= j; l++) c = min(c, f[k][r[l]]);
						e[a][b] = max(e[a][b], c);
					}
				}
				Res = min(Res, e[a][b]);
			}
	}
	
	cout << Res << endl;
	
	return 0;
}

