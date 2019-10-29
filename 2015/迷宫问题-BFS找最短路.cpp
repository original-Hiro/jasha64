#include <iostream>
#include <queue>
#include <utility>
#include <cstdlib>
#include <stack>
using namespace std;

typedef pair<int, int> Point;
const int dx[] = {-1, 0, 0, 1}, dy[] = {0, -1, 1, 0};
queue<Point> q;
stack<Point> Printer;
Point fa[5][5] = {};
char Map[5][5];

int main()
{
	int i, j;
	Point v(-1, -1);
	
	for (i = 0; i < 5; ++i)
		for (j = 0; j < 5; ++j) {cin >> Map[i][j]; fa[i][j] = v;}
	
	q.push(Point(0, 0));
	while (!q.empty())
	{
		v = q.front(); q.pop();
		const int& x = v.first, y = v.second;
		for (i = 0; i < 4; ++i)
			if (x + dx[i] >= 0 && y + dy[i] >= 0 && x + dx[i] < 5 && y + dy[i] < 5 &&
			x + dx[i] + y + dy[i] &&
			Map[x + dx[i]][y + dy[i]] == '0' && fa[x + dx[i]][y + dy[i]] == Point(-1, -1))
			{
				fa[x + dx[i]][y + dy[i]] = v;
				q.push(Point(x + dx[i], y + dy[i]));
			}
	}
	
	v = Point(4, 4);
	while (v.first != -1 && v.second != -1)
	{
		Printer.push(v);
		v = fa[v.first][v.second];
	}
	while (!Printer.empty())
	{
		v = Printer.top(); Printer.pop();
		cout << '(' << v.first << ',' << ' ' << v.second << ')' << endl;
	}
	
	return 0;
}

