#include <iostream>
#include <cstdio>
using namespace std;

const int N = 100007;
int n, a[N], f[N];
struct Node* null;
struct Node
{
	int v, sz;
	Node* ch[2];
	
	Node(int v = 0):v(v) {ch[0] = ch[1] = null; sz = 1;}
	void Pushup() {sz = ch[0] -> sz + ch[1] -> sz + 1;}
	int cmp(int x) const
	{
		int d = x - ch[0] -> sz;
		if (d == 1) return -1;
		return d < 1 ? 0 : 1;
	}
} *Root[N];
inline Node* Newnode(int v = 0) {return new Node(v);}
inline void Rotate(Node*& o, int d)
{
	Node* k = o -> ch[d ^ 1]; o -> ch[d ^ 1] = k -> ch[d]; k -> ch[d] = o;
	o -> Pushup(); k -> Pushup(); o = k;
}
void Splay(Node*& o, int k)
{
	int d = o -> cmp(k);
	if (d == 1) k -= o -> ch[0] -> sz + 1;
	if (d != -1)
	{
		Node*& p = o -> ch[d];
		int d2 = p -> cmp(k);
		int k2 = d2 == 1 ? k - p -> ch[0] -> sz - 1 : k;
		if (d2 != -1)
		{
			Splay(p -> ch[d2], k2);
			if (d == d2) Rotate(o, d ^ 1); else Rotate(p, d);
		}
		Rotate(o, d ^ 1);
	}
}
Node* Insert(Node* o, int v)
{
	if (o == null) {o = Newnode(v); return o;}
	int d = o -> v < v ? 1 : 0;
	o -> ch[d] = Insert(o -> ch[d], v);
	o -> Pushup();
	return o;
}
Node* Merge(Node*& a, Node*& b)
{
	if (a == null) return b;
	while (a -> sz > 0)
	{
		Splay(a, 1);
		Insert(b, a -> v);
		Node* o = a -> ch[1];
		delete a; a = o;
	}
	return b;
}
int fa[N];
int Find(int x)
{
	if (fa[x] == x) return x;
	fa[x] = Find(fa[x]);
	Root[fa[x]] = Merge(Root[x], Root[fa[x]]);
	return fa[x];
}
void Unite(int a, int b)
{
	int aa = Find(a), bb = Find(b);
	if (aa == bb) return;
	fa[aa] = bb; Find(aa);
}
int Query(int c, int b)
{
	int aa = Find(c);
	Node*& o = Root[aa];
	if (o -> sz < b) return -1;
	Splay(o, b);
	return f[o -> v];
}

int main()
{
	null = Newnode(); null -> sz = 0;
	
	int m, q;
	
	cin >> n >> m;
	for (int i = 1; i <= n; i++) fa[i] = i;
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
		Root[i] = Newnode(a[i]); f[a[i]] = i;
	}
	for (int i = 0, a, b; i < m; i++) {scanf("%d%d", &a, &b); Unite(a, b);}
	cin >> q;
	char cmd;
	int a, b;
	while (q--)
	{
		scanf(" %c%d%d", &cmd, &a, &b);
		if (cmd == 'B') Unite(a, b);
		else printf("%d\n", Query(a, b));
	}
	
	return 0;
}

