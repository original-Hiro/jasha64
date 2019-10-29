#include <iostream>
#include <cstdio>
#include <cctype>
#include <cmath>
#include <queue>
#include <stack>
using namespace std;

inline int Read()
{
	int r = 0;
	char c = getchar();
	while (!isdigit(c)) c = getchar();
	while (isdigit(c)) {r = r*10 + c-'0'; c = getchar();}
	return r;
}

const int N = 1601;
int x[N], y[N];
inline double Dist(int a, int b) {return hypot(x[b]-x[a], y[b]-y[a]);}
double G[N][N];

int n, v1, v2;
double f[N];
int fa[N];
void Dijkstra(int s, int t)
{
	static bool vis[N];
	fill(f, f+N, 1e30); fill(vis, vis+N, 0);
	f[s] = 0; fa[s] = 0;
	while (!vis[t])
	{
		int u = 0;
		for (int i = 1; i <= n; i++)
			if (!vis[i] && (!u || f[u] > f[i])) u = i;
		vis[u] = 1;
		for (int v = 1; v <= n; v++)
			if (!vis[v] && f[u] + G[u][v] < f[v]) {f[v] = f[u] + G[u][v]; fa[v] = u;}
	}
}
/*struct HeapNode
{
	int v;
	double d;
	HeapNode(int V = 0, double D = 0): v(V), d(D) {}
	friend bool operator < (const HeapNode& a, const HeapNode& b) {return a.d > b.d;}
};
void Dijkstra(int s, int t)
{
	static bool vis[N];
	priority_queue<HeapNode> pq;
	fill(f, f+N, 1e30); fill(vis, vis+N, 0);
	f[s] = 0; fa[s] = 0; pq.push(HeapNode(s, 0));
	while (!vis[t])
	{
		int u = pq.top().v; pq.pop();
		if (vis[u]) continue;
		vis[u] = 1;
		for (int v = 1; v <= n; v++)
			if (f[u] + G[u][v] < f[v]) {f[v] = f[u] + G[u][v]; fa[v] = u; pq.push(HeapNode(v, f[v]));}
	}
}*/
queue<int> Printer;
double Res;
void Calc(int& Cur, int nx)
{
	Dijkstra(Cur, nx);
	Res += f[nx];
	stack<int> cc;
	int c = nx;
	while (c != Cur) {cc.push(c); c = fa[c];}
	while (!cc.empty()) {Printer.push(cc.top()); cc.pop();}
	Cur = nx;
}

int main()
{
	int m, k;
	cin >> n >> m >> k >> v1 >> v2;
	for (int i = 1; i <= n; i++) cin >> x[i] >> y[i];
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++) G[i][j] = Dist(i, j) / v2;
	for (int i = 0, a, b; i < m; i++)
	{
		a = Read(); b = Read();
		G[a][b] = G[b][a] = Dist(a, b) / v1;
	}

	int Cur = 1, nx; Printer.push(1);
	while (k--) {cin >> nx; Calc(Cur, nx);}
	Calc(Cur, n);

	printf("%.9lf\n%d", Res, Printer.front()); Printer.pop();
	while (!Printer.empty()) {printf(" %d", Printer.front()); Printer.pop();}
	cout << endl;
	return 0;
}

