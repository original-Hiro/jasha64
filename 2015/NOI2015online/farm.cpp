#include <fstream>
#include <queue>
#include <stack>
using namespace std;

ifstream cin("farm.in");
ofstream cout("farm.out");
const int N = 17;
struct Tree
{
	int x, y, c;
	bool v[N];
	
	Tree() {x = y = c = 0;}
	Tree(const int& a, const int& b) {x = a; y = b;}
	Tree(const int& a, const int& b, const int& d) {x = a; y = b; c = d;}
} a[N], t;
int f[N][N];
queue<Tree> q1;
queue<Tree> q2;
stack<int> s;

int main()
{
	int n, i;
	cin >> n;
	for (i = 0; i < n; i++) cin >> a[i].x >> a[i].y;
	
	bool Cont;
	q1.push(Tree());
	while (!q1.empty())
	{
		t = q1.front(); q1.pop(); Cont = false;
		for (i = 0; i < n; i++)
			if (!t.v[i] && (a[i].x - t.x && !(a[i].y - t.y) || (!(a[i].x - t.x) &&
			a[i].y - t.y > 0) || ((a[i].x - t.x == a[i].y - t.y ||
			a[i].x - t.x == t.y - a[i].y) && a[i].x - t.x != 0)))
			{
				Cont = true;
				f[a[i].x][a[i].y] = i;
				t.x = a[i].x; t.y = a[i].y; ++t.c; t.v[i] = true;
				q1.push(t);
			}
		if (!Cont) q2.push(t);
	}
	
	int Res = 0;
	while (!q2.empty())
	{
		t = q2.front(); q2.pop();
		if (Res < t.c)
		{
			while (!q1.empty()) q1.pop();
			Res = t.c;
		}
		if (Res == t.c)
			q1.push(t);
	}
	int Steamroller = N, x, y, c = 1;
	Tree CurAns;
	while (!q1.empty())
	{
		t = q2.front(); q2.pop();
		x = t.x; y = t.y;
		while (f[x][y])
		{
			if (!(a[f[x][y]].y - t.y > 0 && (a[f[x][y]].x == t.x ||
			(a[f[x][y]].x - t.x == a[f[x][y]].y - t.y ||
			a[f[x][y]].x - t.x == t.y - a[f[x][y]].y)))) c++;
			x = a[f[x][y]].x; y = a[f[x][y]].y;
		}
		if (c < Steamroller) {Steamroller = c; CurAns = t;}
	}
	
	cout << CurAns.c << endl;
	x = CurAns.x; y = CurAns.y;
	for (i = 0; i < n; i++)
		if (a[i].x == x && a[i].y == y) {s.push(i); break;}
	while (f[x][y])
	{
		s.push(f[x][y]);
		x = a[f[x][y]].x; y = a[f[x][y]].y;
	}
	cout << s.top(); s.pop();
	while (!s.empty()) {cout << ' ' << s.top(); s.pop();}
	cout << endl << Steamroller << endl;
	
	return 0;
}

