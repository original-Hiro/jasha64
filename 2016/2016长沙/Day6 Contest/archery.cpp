#include <fstream>
#include <algorithm>
#include <vector>
#include <cctype>
using namespace std;

ifstream cin("archery.in");
ofstream cout("archery.out");
const int N = 57, INF = 1073741823;
struct Edge {int s, t, v, Next;} e[N * N * N];
struct Tower
{
	int x, y, dir;
	Tower(int a = 0, int b = 0, char c = 0)
	{
		x = a; y = b;
		if (c == 'A') dir = 1;
		else if (c == '>') dir = 2;
		else if (c == 'V') dir = 3;
		else if (c == '<') dir = 4;
		else dir = 0;
	}
} tw[N * N];
struct Target
{
	int x, y, v;
	Target(int a = 0, int b = 0, int c = 0) {x = a; y = b; v = c;}
} t[N * N];
char a[N][N];
int X, Y, n, m = 1, k, tid[N][N];
int Head[N], Match[N * N], Lx[N * N], Ly[N * N], Slack[N];
bool S[N * N], T[N * N], vis[N][N], v[N][N];

inline bool Access(int i)
{
	copy(vis[0], vis[0] + N * N, v[0]);
	int Dir = tw[e[i].s].dir, x = tw[e[i].s].x, y = tw[e[i].s].y, xx = t[e[i].t].x, yy = t[e[i].t].y;
	if (Dir == 1)
		while (x >= xx)
		{
			if (v[x][y]) return false;
			v[x][y] = 1;
			--x;
		}
	else if (Dir == 2)
		while (y <= yy)
		{
			if (v[x][y]) return false;
			v[x][y] = 1;
			++y;
		}
	else if (Dir == 3)
		while (x <= xx)
		{
			if (v[x][y]) return false;
			v[x][y] = 1;
			++x;
		}
	else while (y >= yy)
		{
			if (v[x][y]) return false;
			v[x][y] = 1;
			--y;
		}
	copy(v[0], v[0] + N * N, vis[0]);
	return true;
}
bool DFS(int x)
{
	S[x] = true;
	for (int i = Head[x]; i; i = e[i].Next)
	{
		int y = e[i].t;
		if (T[y]) continue;
		int d = Lx[x] + Ly[y] - e[i].v;
		if (d == 0)
		{
			if (!Access(i)) continue;
			T[y] = true;
			if (!Match[y] || DFS(Match[y])) {Match[y] = x; return true;}
		}
		else Slack[y] = min(Slack[y], d);
	}
	return false;
}
void Update()
{
	int a = INF;
	for (int i = 1; i <= n; i++)
		if (!T[i]) a = min(a, Slack[i]);
	for (int i = 1; i <= n; i++)
		if (S[i]) Lx[i] -= a;
	for (int i = 1; i <= n; i++)
		if (T[i]) Ly[i] += a;
		else Slack[i] -= a;
}
void KM()
{
	for (int i = 1; i <= n; i++)
		for (int j = Head[i]; j; j = e[j].Next) Lx[i] = max(Lx[i], e[j].v);
	for (int i = 1; i <= k; i++)
		while (true)
		{
			fill(S, S + N, false); fill(T, T + N, false); fill(Slack, Slack + N, INF);
			fill(vis[0], vis[0] + N * N, 0);
			if (DFS(i)) break; else Update();
		}
}
inline void AddEdge(int a, int b)
{
	e[m].s = a; e[m].t = b; e[m].v = t[b].v;
	e[m].Next = Head[a]; Head[a] = m++;
}
void Work()
{
	for (int i = 1; i <= k; i++)
	{
		int x = tw[i].x, y = tw[i].y;
		AddEdge(i, tid[x][y]);
		if (tw[i].dir == 1)
		{
			for (int j = x - 1; j > 0; j--)
				if (isdigit(a[j][y])) AddEdge(i, tid[j][y]);
		}
		else if (tw[i].dir == 2)
		{
			for (int j = y + 1; j <= Y; j++)
				if (isdigit(a[x][j])) AddEdge(i, tid[x][j]);
		}
		else if (tw[i].dir == 3)
		{
			for (int j = x + 1; j <= X; j++)
				if (isdigit(a[j][y])) AddEdge(i, tid[j][y]);
		}
		else {
			for (int j = y - 1; j > 0; j--)
				if (isdigit(a[x][j])) AddEdge(i, tid[x][j]);
		}
	}
	KM();
}

int main()
{
	cin >> X >> Y;
	for (int i = 1; i <= X; i++)
		for (int j = 1; j <= Y; j++)
		{
			cin >> a[i][j];
			if (a[i][j] == 'A' || a[i][j] == 'V' || a[i][j] == '>' || a[i][j] == '<')
			{
				tw[++k] = Tower(i, j, a[i][j]);
				t[tid[i][j] = ++n] = Target(i, j, 0);
			}
			else if (isdigit(a[i][j])) t[tid[i][j] = ++n] = Target(i, j, a[i][j] - '0');
		}
	
	Work();
	
	int Res = 0;
	for (int i = 1; i <= n; i++) Res += Lx[i];
	for (int i = 1; i <= n; i++) Res += Ly[i];
	cout << Res << endl;
	
	return 0;
}

