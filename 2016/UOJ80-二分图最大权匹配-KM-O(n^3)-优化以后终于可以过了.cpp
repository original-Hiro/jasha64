#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <queue>
using namespace std;

const int N = 507, INF = 0x7fffffff;
int n, Match_[N], Match[N], fa[N], G[N][N], Lx[N], Ly[N], Slack[N];
bool S[N], T[N];
queue<int> q;

bool Check(int x, int y)
{
	T[y] = true; fa[y] = x;
	if (!Match[y])
	{
		while (x)
		{
			int tmp = Match_[x];
			Match_[x] = y; Match[y] = x;
			y = tmp; x = fa[tmp];
		}
		return true;
	}
	S[Match[y]] = true; q.push(Match[y]);
	return false;
}
void BFS(int s)
{
	fill(S + 1, S + n + 1, false);
	fill(T + 1, T + n + 1, false);
	fill(Slack + 1, Slack + n + 1, INF);
	
	while (!q.empty()) q.pop();
	q.push(s);
	S[s] = true;
	while (true)
	{
		int x = q.front(); q.pop();
		for (int y = 1; y <= n; y++)
			if (!T[y])
			{
				int t = Lx[x] + Ly[y] - G[x][y];
				if (t == 0 && Check(x, y)) return;
				if (t && t < Slack[y]) {Slack[y] = t; fa[y] = x;}
			}
		if (q.empty())
		{
			int d = INF;
			for (int i = 1; i <= n; i++)
				if (!T[i]) d = min(d, Slack[i]);
			for (int i = 1; i <= n; i++)
				if (S[i]) Lx[i] -= d;
			for (int i = 1; i <= n; i++)
				if (T[i]) Ly[i] += d;
				else Slack[i] -= d;
			for (int i = 1; i <= n; i++)
				if (!T[i] && Slack[i] == 0 && Check(fa[i], i)) return;
		}
	}
}
void KM()
{
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++) Lx[i] = max(Lx[i], G[i][j]);
	for (int i = 1; i <= n; i++) BFS(i);
}

int main()
{
	ios::sync_with_stdio(false);
	
	int nl, nr, m;
	cin >> nl >> nr >> m; n = max(nl, nr);
	while (m--)
	{
		int x, y, z;
		cin >> x >> y >> z;
		G[x][y] = z;
	}
	
	KM();
	
	long long Res = 0;
	for (int i = 1; i <= n; i++) Res += Lx[i];
	for (int i = 1; i <= n; i++) Res += Ly[i];
	cout << Res << endl;
	for (int i = 1; i <= nl; i++)
		if (G[i][Match_[i]]) cout << Match_[i] << ' ';
		else cout << "0 ";
	cout << endl;
	
	return 0;
}

