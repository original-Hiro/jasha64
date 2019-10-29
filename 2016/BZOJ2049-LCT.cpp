#include <iostream>
#include <cstdio>
#include <stack>
using namespace std;

const int N = 10007;
struct Link_Cut_Tree
{
	int fa[N], ch[N][2];
	bool rev[N];
	
	inline bool isRoot(int x) {return ch[fa[x]][0] != x && ch[fa[x]][1] != x;}
	inline void Pushdown(int o)
	{
		if (!rev[o]) return;
		rev[o] = 0; swap(ch[o][0], ch[o][1]);
		rev[ch[o][0]] ^= 1; rev[ch[o][1]] ^= 1;
	}
	inline void Splay(int x)
	{
		stack<int> s; s.push(x);
		for (int v = x; !isRoot(v); v = fa[v]) s.push(fa[v]);
		while (!s.empty()) {Pushdown(s.top()); s.pop();}
		while (!isRoot(x))
		{
			int y = fa[x], z = fa[y];
			if (!isRoot(y))
			{
				if (ch[y][0] == x ^ ch[z][0] == y) Rotate(x);
				else Rotate(y);
			}
			Rotate(x);
		}
	}
	inline void Rotate(int x)
	{
		int y = fa[x], z = fa[y], l = ch[y][0] == x ? 0 : 1, r = l ^ 1;
		if (!isRoot(y)) {if (ch[z][0] == y) ch[z][0] = x; else ch[z][1] = x;}
		fa[x] = z; fa[y] = x; fa[ch[x][r]] = y; ch[y][l] = ch[x][r]; ch[x][r] = y;
	}
	inline void Access(int x)
	{
		int t = 0;
		while (x)
		{
			Splay(x);
			ch[x][1] = t;
			t = x; x = fa[x];
		}
	}
	inline void MakeRoot(int x) {Access(x); Splay(x); rev[x] ^= 1;}
	inline int FindRoot(int x)
	{
		Access(x); Splay(x);
		int v = x;
		while (ch[v][0]) v = ch[v][0];
		return v;
	}
	inline void Link(int a, int b) {MakeRoot(a); fa[a] = b;}
	inline void Cut(int a, int b)
	{
		MakeRoot(a); Access(b); Splay(b);
		ch[b][0] = fa[a] = 0;
	}
	inline bool Connected(int a, int b) {return FindRoot(a) == FindRoot(b);}
} LCT;

int main()
{
	int n, q;
	cin >> n >> q;
	while (q--)
	{
		char cmd[8];
		int a, b;
		scanf("%s%d%d", cmd, &a, &b);
		if (cmd[0] == 'Q')
		{
			if (LCT.Connected(a, b)) printf("Yes\n");
			else printf("No\n");
		}
		else if (cmd[0] == 'C') LCT.Link(a, b);
		else LCT.Cut(a, b);
	}
	
	return 0;
}

