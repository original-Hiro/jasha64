//SPOJ - labyrinth
//DFS 
//结合题面"任意两个自由块之间有唯一路径"的提示可以知道，自由块构成的图案是一棵树，然后就简单了 
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

typedef pair<int, int> pii;
const int N = 1001, dx[] = {0, -1, 1, 0}, dy[] = {-1, 0, 0, 1};
int c, r, res;
char G[N][N];
int len[N][N];
void DFS(int cx, int cy, int dir) //参数中的dir是为防止搜索到父节点 
{
	for (int i = 0; i < 4; i++)
	{
		if (i == dir) continue;
		int nx = cx + dx[i], ny = cy + dy[i];
		if (nx < 1 || nx > r || ny < 1 || ny > c) continue;
		if (G[nx][ny] == '#') continue;
		len[nx][ny] = len[cx][cy] + 1; DFS(nx, ny, 3-i);
	}
}
void Make_Tree(int x, int y) {len[x][y] = 0; DFS(x, y, -1);}

int main()
{
	ios::sync_with_stdio(false);
	int T;
	cin >> T;
	while (T--)
	{
		memset(len, 0, sizeof(len));
		cin >> c >> r;
		for (int x = 1; x <= r; x++)
			for (int y = 1; y <= c; y++) cin >> G[x][y];
		
		int rx = -1, ry = -1;
		for (int x = 1; x <= r; x++)
		{
			for (int y = 1; y <= c; y++)
				if (G[x][y] == '.') {rx = x; ry = y; break;}
			if (rx != -1) break;
		}
		if (rx != -1)
		{
			Make_Tree(rx, ry);
			for (int x = 1; x <= r; x++)
				for (int y = 1; y <= c; y++)
					if (len[x][y] > len[rx][ry]) {rx = x; ry = y;}
			Make_Tree(rx, ry);
		}
		
		int res = *max_element(len[0], len[0] + N * N);
		cout << "Maximum rope length is " << res << '.' << endl;
	}
	
	return 0;
}

