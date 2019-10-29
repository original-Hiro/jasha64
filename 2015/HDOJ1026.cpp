#include <iostream>
#include <queue>
#include <cctype>
#include <stack>
using namespace std;

const int N = 107, INF = 1000007, dx[] = {-1, 0, 0, 1}, dy[] = {0, -1, 1, 0};
int f[N][N], fa[N][N], a[N][N], n, m;
bool Done[N][N];
struct HeapNode
{
	int x, y;
	HeapNode() {}
	HeapNode(int a, int b) {x = a; y = b;}
	friend bool operator < (const HeapNode& a, const HeapNode& b) {return f[a.x][a.y] > f[b.x][b.y];}
};
priority_queue<HeapNode> pq;

void Dijkstra()
{
	int i;
	HeapNode c;
	
	fill(f[0], f[0] + N * N, INF);
	f[0][0] = 0;
	fill(Done[0], Done[0] + N * N, false);
	pq.push(HeapNode(0, 0));
	while (!pq.empty())
	{
		c = pq.top(); pq.pop();
		if (Done[c.x][c.y]) continue;
		Done[c.x][c.y] = true;
		for (i = 0; i < 4; ++i)
			if (c.x + dx[i] >= 0 && c.x + dx[i] < n && c.y + dy[i] >= 0 && c.y + dy[i] < m && a[c.x + dx[i]][c.y + dy[i]] != INF)
				if (f[c.x + dx[i]][c.y + dy[i]] > f[c.x][c.y] + a[c.x][c.y]) 
				{
					f[c.x + dx[i]][c.y + dy[i]] = f[c.x][c.y] + a[c.x][c.y];
					fa[c.x + dx[i]][c.y + dy[i]] = i ^ 3;
					pq.push(HeapNode(c.x + dx[i], c.y + dy[i]));
				}
	}
}
void Print()
{
	if (f[n - 1][m - 1] == INF) {cout << "God please help our poor hero." << endl << "FINISH" << endl; return;}
	
	int x = n - 1, y = m - 1, tx, ty, Time = 0;
	stack<HeapNode> Printer;
	
	cout << "It takes " << f[n - 1][m - 1] + a[n - 1][m - 1] - 1 << " seconds to reach the target position, let me show you the way." << endl;
	while (x || y)
	{
		Printer.push(HeapNode(x, y));
		tx = x + dx[fa[x][y]]; ty = y + dy[fa[x][y]];
		x = tx; y = ty;
	}
	while (!Printer.empty())
	{
		cout << ++Time << "s:(" << x << ',' << y << ")->(";
		x = Printer.top().x; y = Printer.top().y; Printer.pop();
		cout << x << ',' << y << ')' << endl;
		while (a[x][y] > 1)
		{
			cout << ++Time << "s:FIGHT AT (" << x << ',' << y << ')' << endl;
			--a[x][y];
		}
	}
	cout << "FINISH" << endl;
}

int main()
{
	int i, j, t;
	char c;
	
	while (cin >> n >> m)
	{
		for (i = 0; i < n; ++i)
			for (j = 0; j < m; ++j)
			{
				cin >> c;
				if (isdigit(c)) {a[i][j] = c - '0' + 1;}
				else if (c == 'X') a[i][j] = INF;
				else a[i][j] = 1;
			}
		
		Dijkstra();
		
		Print();
	}
	
	return 0;
}

