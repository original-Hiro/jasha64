#include <iostream>
#include <queue>
#include <string>
#include <vector>
#include <cstring>
using namespace std;

const int dx[] = {-1, 1, 0, 0}, dy[] = {0, 0, -1, 1};
int n, m, d;
string G[200007];
int* f[200007];
struct Point
{
	int x, y;
	Point() {x = y = 0;}
	Point(int a, int b):x(a), y(b) {}
} S, T;
vector<Point> Mon;

inline bool inb(int x, int y) {return 1 <= x && x <= n && 1 <= y && y <= m;}
inline int Abs(int x) {return x < 0 ? -x : x;}
inline int dist(Point a, Point b) {return Abs(a.x - b.x) + Abs(a.y - b.y);}
inline void proc(int x, int y) {if (inb(x, y)) G[x][y] = 'M';}
void BFS()
{
	queue<Point> q;
	q.push(S); f[S.x][S.y] = 0;
	
	while (!q.empty())
	{
		Point p = q.front(); q.pop();
		for (int i = 0; i < 4; i++)
		{
			int nx, ny;
			Point np = Point(nx = p.x + dx[i], ny = p.y + dy[i]);
			if (!inb(nx, ny)) continue;
			if (G[nx][ny] == 'M') continue;
			if (f[nx][ny] != -1) continue;
			f[nx][ny] = f[p.x][p.y] + 1;
			q.push(Point(np));
		}
	}
	cout << f[T.x][T.y] << endl;
}

int main()
{
	ios::sync_with_stdio(false);
	cin >> n >> m >> d;
	for (int i = 1; i <= n; i++)
	{
		f[i] = new int [m+1];
		memset(f[i], -1, (m+1)*sizeof(int));
		string s;
		cin >> s;
		s = ' ' + s;
		if (s.find('S') != string::npos) S = Point(i, s.find('S'));
		if (s.find('F') != string::npos) T = Point(i, s.find('F'));
		int pos = s.find('M');
		while (pos != string::npos)
		{
			Mon.push_back(Point(i, pos));
			pos = s.find('M', pos+1);
		}
		G[i] = s;
	}
	for (int i = 0; i < Mon.size(); i++)
	{
		if (dist(Mon[i], S) <= d || dist(Mon[i], T) <= d) {cout << -1 << endl; return 0;}
		int x = Mon[i].x - d, y = Mon[i].y;
		while (y < Mon[i].y + d) proc(++x, ++y);
		while (y > Mon[i].y) proc(++x, --y);
		while (y > Mon[i].y - d) proc(--x, --y);
		while (y < Mon[i].y) proc(--x, ++y);
	}
	Mon.clear();
	//Note that if starting point is in range of a monster, the player dies immediately.
	//If destination is in range of a monster, then there's no solution either.
	
	BFS();
	
	return 0;
}

