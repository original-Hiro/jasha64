#include <iostream>
#include <algorithm>
#include <cstdio>
#include <queue>
#include <cctype>
using namespace std;

const int N = 10007, M = 1000007;
struct Edge
{
	int s, t, a, b, c, Next;
} e[M];
struct C_Edge
{
	int t, Next;
} ce[M];
const int INF = 0x7fffffff;
int Head[N], ch[N], n, a, b, c, Res = INF;
bool v[N];

inline int Read()
{
	int r = 0;
	char c = getchar();
	while (!isdigit(c)) c = getchar();
	while (isdigit(c)) {r = r * 10 + c - '0'; c = getchar();}
	return r;
}
void BFS()
{
	int i, t;
	queue<int> q;
	
	fill(v + 1, v + n + 1, true);
	q.push(n);
	v[n] = false;
	while (!q.empty())
	{
		t = q.front(); q.pop();
		i = ch[t];
		while (i)
		{
			if (v[ce[i].t]) {v[ce[i].t] = false; q.push(ce[i].t);}
			i = ce[i].Next;
		}
	}
}
void DFS(int x)
{
	if (x == n) {Res = min(Res, a + b + c); return;}
	if (a + b + c >= Res) return;
	
	const int ca = a, cb = b, cc = c;
	int i = Head[x];
	
	v[x] = true;
	while (i)
	{
		if (v[e[i].t]) {i = e[i].Next; continue;}
		a = max(a, e[i].a); b = max(b, e[i].b); c = max(c, e[i].c);
		DFS(e[i].t);
		i = e[i].Next;
		a = ca; b = cb; c = cc;
	}
	v[x] = false;
}

int main()
{
	int m, i;
	
	cin >> n >> m;
	for (i = 1; i <= m; ++i)
	{
		e[i].s = Read(); e[i].t = Read(); e[i].a = Read(); e[i].b = Read(); e[i].c = Read();
		ce[i].t = e[i].s;
		e[i].Next = Head[e[i].s]; Head[e[i].s] = i;
		ce[i].Next = ch[e[i].t]; ch[e[i].t] = i;
	}
	
	BFS();
	if (!v[1]) DFS(1);
	
	if (Res == INF) cout << -1 << endl;
	else cout << Res << endl;
	
	return 0;
}

