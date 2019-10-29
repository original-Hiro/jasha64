#include <cstdio>
#include <queue>
using namespace std;

const int N = 100007;
queue<int> q;
struct _
{
	int v[N], s[N], ch[N][2], fa[N], cnt, rt;
	bool rev[N];
	
	int Newnode(int a = 0) {++cnt; v[cnt] = a; s[cnt] = 1; return cnt;}
	void Pushdown(int v)
	{
		if (!rev[v]) return;
		swap(ch[v][0], ch[v][1]);
		rev[ch[v][0]] ^= 1; rev[ch[v][1]] ^= 1;
		rev[v] = false;
	}
	void Pushup(int v) {s[v] = s[ch[v][0]] + s[ch[v][1]] + 1;}
	int Build(int l, int r)
	{
		if (l > r) return 0;
		int m = (l + r) >> 1;
		int o = Newnode(m - 1);
		fa[ch[o][0] = Build(l, m - 1)] = o;
		fa[ch[o][1] = Build(m + 1, r)] = o;
		Pushup(o);
		return o;
	}
	int Find(int rk)
	{
		int o = rt, Ret = 1;
		while (o)
		{
			Pushdown(o);
			int d = rk - s[ch[o][0]] - 1;
			if (d == 0) return o;
			if (d < 0) o = ch[o][0];
			else {rk = d; o = ch[o][1];}
		}
		return -1;
	}
	void Rev(int l, int r)
	{
		Splay(rt, Find(l)); Splay(ch[rt][1], Find(r + 2));
		rev[ch[ch[rt][1]][0]] ^= 1;
	}
	void Print(int o)
	{
		if (!o) return;
		Pushdown(o);
		Print(ch[o][0]);
		q.push(v[o]);
		Print(ch[o][1]);
	}
	void Rotate(int& o, int x)
	{
		int y = fa[x], z = fa[y], l = ch[y][0] == x ? 0 : 1, r = l ^ 1;
		if (y == o) o = x;
		else if (ch[z][0] == y) ch[z][0] = x;
			else ch[z][1] = x;
		fa[x] = z; fa[y] = x; fa[ch[x][r]] = y;
		ch[y][l] = ch[x][r]; ch[x][r] = y;
		Pushup(y); Pushup(x);
	}
	void Splay(int& o, int x)
	{
		while (o != x)
		{
			int y = fa[x], z = fa[y];
			if (o != y)
				if (ch[y][0] == x ^ ch[z][0] == y) Rotate(o, x);
				else Rotate(o, y);
			Rotate(o, x);
		}
	}
} Splay;

int main()
{
	int n, m, a, b;
	
	scanf("%d%d", &n, &m);
	Splay.rt = Splay.Build(1, n + 2);
	while (m--) {scanf("%d%d", &a, &b); if (a != b) Splay.Rev(a, b);}
	
	Splay.Print(Splay.rt);
	while (!q.empty())
	{
		int x = q.front(); q.pop();
		if (x == 0 || x == n + 1) continue;
		printf("%d ", x);
	}
	printf("\n");
	
	return 0;
}

