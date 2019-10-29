#include <iostream>
#include <cstring>
using namespace std;

const int N = 27, dx[] = {-1, 0, 0, 1}, dy[] = {0, -1, 1, 0};
int w, h, cnt;
char G[N][N];
bool e[N][N];

void DFS(int x, int y)
{
	if (x < 1 || x > h || y < 1 || y > w) return;
	if (G[x][y] == '#') return;
	if (e[x][y]) return;
	
	e[x][y] = true; ++cnt;
	
	for (int i = 0; i < 4; ++i) DFS(x + dx[i], y + dy[i]);
}

int main()
{
	int i, j, x, y;
	
	while (cin >> w >> h && (w || h))
	{
		memset(e, 0, sizeof(e));
		cnt = 0;
		
		for (i = 1; i <= h; ++i)
			for (j = 1; j <= w; ++j)
			{
				cin >> G[i][j];
				if (G[i][j] == '@') {x = i; y = j;}
			}
		
		DFS(x, y);
		
		cout << cnt << endl;
	}
	
	return 0;
}

