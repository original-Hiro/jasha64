//记忆化以后，可以推导出运行时间T(n, m) = 8nm 
#include <iostream>
using namespace std;

const int dx[8] = {1, -1, -2, -2, -1, 1, 2, 2}, dy[8] = {2, 2, 1, -1, -2, -2, -1, 1};
int viscnt, n, m;
int vis[7][7];
bool Search(int x, int y)
{
	if (viscnt == n*m) return 1;
	for (int i = 0; i < 8; i++)
	{
		int tx = x + dx[i], ty = y + dy[i];
		if (tx < 1 || tx > n || ty < 1 || ty > m) continue;
		if (vis[tx][ty]) continue;
		vis[tx][ty] = vis[x][y] + 1; viscnt++;
		if (Search(tx, ty)) return 1;
		vis[tx][ty] = 0; viscnt--;
	}
	return 0;
}

int main()
{
	cin >> n >> m;
	vis[1][1] = 1; viscnt = 1;
	bool sol = Search(1, 1);
	if (sol)
		for (int i = 1; i <= n; i++)
		{
			cout << vis[i][1];
			for (int j = 2; j <= m; j++) cout << ' ' << vis[i][j];
			cout << endl;
		}
	else cout << "QAQ" << endl;
	return 0;
}

