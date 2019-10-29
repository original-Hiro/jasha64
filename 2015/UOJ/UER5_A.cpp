#include <iostream>
#include <cstdio>
#include <cstring>
#include <utility>
#include <queue>
using namespace std;

typedef pair<int, int> pii;
const int N = 1007, dx[4] = {-1, 0, 0, 1}, dy[4] = {0, -1, 1, 0};
int n, m, fa[N][N];
bool a[N][N], b[N][N];

bool OK()
{
	int i, j, ty;
	queue<pii> q;
	pii v;
	
	for (i = 1; i <= n; ++i)
	{
		for (j = 0; j < m; ++j)
			if (!b[i][j]) {a[i][j] = true; fa[i][j] = -1; q.push(pii(i, j)); break;}
		if (!b[i][j]) break;
	}
	while (!q.empty())
	{
		v = q.front(); q.pop();
		const int &x = v.first, &y = v.second;
		for (i = 0; i < 4; ++i)
		{
			ty = (y + dy[i]) % m;
			if (ty < 0) ty += m;
			if (x + dx[i] > 0 && x + dx[i] <= n && !b[x + dx[i]][ty] && fa[x][y] != i)
				if (a[x + dx[i]][ty]) return false;
				else {
					a[x + dx[i]][ty] = true;
					q.push(pii(x + dx[i], ty));
					fa[x + dx[i]][ty] = i ^ 3;
				}
		}
	}
	
	for (i = 1; i <= n; ++i)
		for (j = 0; j < m; ++j)
			if (!a[i][j] && !b[i][j]) return false;
	
	return true;
}

int main()
{
	int T, k, i, x, y;
	
	cin >> T;
	while (T--)
	{
		memset(a, 0, sizeof(a));
		memset(b, 0, sizeof(b));
		
		cin >> n >> m >> k;
		if (k < m)
		{
			cout << "No" << endl;
			while (k--) scanf("%*d%*d");
			continue;
		}
		for (i = 0; i < k; ++i)
		{
			scanf("%d%d", &x, &y);
			b[x][--y] = true;
		}
		
		if (OK()) cout << "Yes" << endl;
		else cout << "No" << endl;
	}
	
	return 0;
}

