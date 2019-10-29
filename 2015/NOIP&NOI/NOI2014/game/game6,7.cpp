#include <iostream>
#include <fstream>
#include <queue>
#include <cstring>
using namespace std;

ifstream fin("game6.in");
ofstream fout("game6.out");
const int N = 1007;
char a[N][N];
bool v[N][N];

struct point
{
	int x, y;
	point() {x = y = 0;}
	point(const int& a, const int& b) {x = a; y = b;}
	friend ostream& operator << (ostream& cout, const point& a)
	{
		cout << ' ' << a.x << ' ' << a.y;
		return cout;
	}
};
deque<point> ans, res;

inline void search(int x0, int y0)
{
	int x, y;
	memset(v, 0, sizeof(v));
	ans.clear();
	ans.push_back(point(x = x0, y = y0));
	v[x0][y0] = 1;
	if (y < 1000 && a[x][y + 1] == a[x0][y0]) ans.push_back(point(x, ++y));
	else if (x < 1000 && a[x + 1][y] == a[x0][y0]) ans.push_back(point(++x, y));
	else return;
	v[x][y] = 1;
	for (int i = 1; i < 500; i++)
	{
		ans.push_front(point(--x0, y0));
		v[x0][y0] = 1;
		if (y < 1000 && !v[x][y + 1] && a[x][y + 1] == a[x0][y0]) ans.push_back(point(x, ++y));
		else if (x < 1000 && !v[x + 1][y] && a[x + 1][y] == a[x0][y0]) ans.push_back(point(++x, y));
		else {
			v[x0][y0] = 0;
			ans.pop_front();
			++x0;
			ans.push_front(point(x0, --y0));
			v[x0][y0] = 1;
			if (y < 1000 && !v[x][y + 1] && a[x][y + 1] == a[x0][y0]) ans.push_back(point(x, ++y));
			else if (x < 1000 && !v[x + 1][y] && a[x + 1][y] == a[x0][y0]) ans.push_back(point(++x, y));
			else return;
		}
		v[x][y] = 1;
	}
}

int main()
{
	int n, m;
	int i, j, cache;
	
	fin >> n >> m;
	for (i = 0; i < 6; i++) fin >> cache;
	for (i = 1; i <= n; i++)
		for (j = 1; j <= m; j++) fin >> a[i][j];
	
	for (i = 1; i <= 1000; i++)
		for (j = 1; j <= 1000; j++)
		{
			search(i, j);	
			if (ans.size() > res.size()) res = ans;
		}
		
	if (res.size() < 1000) res.pop_front();
	fout << 1 << endl << res.size();
	while (!res.empty())
	{
		fout << res.front();
		res.pop_front();
	}
	fout << endl;
	
	return 0;
}

