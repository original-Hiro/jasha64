#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

const int N = 303, Tm = 1001, dx[] = {0, -1, 0, 0, 1}, dy[] = {0, 0, -1, 1, 0};
int G[N][N], d[N][N];
bool inq[N][N];

inline void Process(int x, int y, int t)
{
	for (int i = 0; i <= 4; i++)
	{
		int nx = x + dx[i], ny = y + dy[i];
		if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
		G[nx][ny] = min(G[nx][ny], t);
	}
}
struct Point
{
	int x, y;
	Point(int a, int b):x(a), y(b) {}
};
void SPFA()
{
	queue<Point> q;
	
	fill(d[0], d[0] + N*N, Tm);
	fill(inq[0], inq[0] + N*N, 0);
	if (G[0][0] > 0) {d[0][0] = 0; q.push(Point(0, 0)); inq[0][0] = 1;}
	
	while (!q.empty())
	{
		Point p = q.front(); q.pop();
		int px = p.x, py = p.y; inq[px][py] = 0;
		for (int i = 1; i <= 4; i++)
		{
			int x = px + dx[i], y = py + dy[i];
			if (x < 0 || x >= N || y < 0 || y >= N) continue;
			if (G[x][y] > d[px][py] + 1 && d[px][py] + 1 < d[x][y])
			{
				d[x][y] = d[px][py] + 1;
				if (!inq[x][y]) {q.push(Point(x, y)); inq[x][y] = 1;}
			}
		}
	}
}

int main()
{
	int T;
	
	cin >> T;
	while (T--)
	{
		fill(G[0], G[0] + N*N, Tm);
		
		int m;
		cin >> m;
		for (int x, y, t, i = 0; i < m; i++)
		{
			cin >> x >> y >> t;
			Process(x, y, t);
		}
		
		SPFA();
		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 5; j++) cout << (d[i][j] == Tm ? -1 : d[i][j]) << ' ';
			cout << endl;
		}
		
		int Ans = Tm;
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				if (i + j > 0 && G[i][j] == Tm) Ans = min(Ans, d[i][j]);
		cout << (Ans == Tm ? -1 : Ans) << endl;
	}
	
	return 0;
}

