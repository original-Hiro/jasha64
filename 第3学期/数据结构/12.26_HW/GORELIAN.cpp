#include <iostream>
#include <queue>
using namespace std;

const int N = 22, INF = 1073741823;
const int dx[] = {-1, 0, 0, 1}, dy[] = {0, -1, 1, 0}; //0: 向上 1: 向左 2: 向右 3: 向下 
int dist[N][N], G[N][N][4];
inline int len(int spd) {return spd == 0 ? INF : 2520 / spd;}
struct HeapNode
{
	int x, y, d;
	HeapNode(int x, int y): x(x), y(y), d(dist[x][y]) {}
	friend bool operator < (const HeapNode& a, const HeapNode& b) {return a.d > b.d;}
};

int main()
{
	int n, m;
	while (cin >> n >> m && n != 0)
	{
		fill(G[0][0], G[0][0] + N * N * 4, INF);
		for (int i = 0; i <= n; i++)
		{
			int spd; char dir;
			for (int j = 0; j < m; j++)
			{
				cin >> spd >> dir;
				if (dir != '<') G[i][j][2] = len(spd);
				if (dir != '>') G[i][j+1][1] = len(spd);
			}
			if (i == n) break;
			for (int j = 0; j <= m; j++)
			{
				cin >> spd >> dir;
				if (dir != '^') G[i][j][3] = len(spd);
				if (dir != 'v') G[i+1][j][0] = len(spd);
			}
		}
		
		fill(dist[0], dist[0] + N * N, INF); dist[0][0] = 0;
		priority_queue<HeapNode> pq;
		pq.push(HeapNode(0, 0));
		while (!pq.empty())
		{
			int x = pq.top().x, y = pq.top().y, d = pq.top().d; pq.pop();
			if (d > dist[x][y]) continue;
			for (int i = 0; i < 4; i++)
			{
				int nx = x + dx[i], ny = y + dy[i];
				if (nx < 0 || nx > n || ny < 0 || ny > m) continue;
				if (d + G[x][y][i] < dist[nx][ny])
				{
					dist[nx][ny] = dist[x][y] + G[x][y][i];
					pq.push(HeapNode(nx, ny));
				}
			}
		}
		if (dist[n][m] == INF) cout << "Holiday" << endl;
		else cout << dist[n][m] << " blips" << endl;
	}
	
	return 0;
}

