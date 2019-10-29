//#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

struct Node
{
	Node* ch[2];
	int p, v, s, c;
	Node() {}
	Node(int x):v(x) {s = c = 1; p = rand(); ch[0] = ch[1] = NULL;}
	int cmp(int x) const
	{
		if (x == v) return -1;
		return x < v ? 0 : 1;
	}
	void Maintain()
	{
		s = c;
		if (ch[0] != NULL) s += ch[0]->s;
		if (ch[1] != NULL) s += ch[1]->s;
	}
} *Root;

inline void Rotate(Node* &o, int d)
{
	Node* k = o->ch[d^1]; o->ch[d^1] = k->ch[d]; k->ch[d] = o;
	o->Maintain(); k->Maintain(); o = k;
}
void Insert(Node* &o, const int x)
{
	if (o == NULL) {o = new Node(x); return;}
	int d = o->cmp(x);
	if (d == -1) {++(o->c); o->Maintain(); return;}
	Insert(o->ch[d], x); if (o->ch[d]->p > o->p) Rotate(o, d^1); o->Maintain();
}
inline void _Remove(Node* &o, int d) {Node* k = o; o = o->ch[d^1]; delete k;}
void Remove(Node* &o, const int x)
{
	int d = o->cmp(x);
	if (d == -1)
	{
		if (o->c == 0 || o->c == 1)
		{
			o->c = 0;
			if (o->ch[0] == NULL) _Remove(o, 0);
			else if (o->ch[1] == NULL) _Remove(o, 1);
			else {
				int d2 = (o->ch[1]->p > o->ch[0]->p ? 0 : 1);
				Rotate(o, d2); Remove(o->ch[d2], x);
			}
		}
		else --(o->c);
	}
	else Remove(o->ch[d], x);
	if (o) o->Maintain();
}
int Kth(Node* o, const int k)
{
	int c = o->ch[0] == NULL ? 0 : o->ch[0]->s;
	if (c < k && k <= c+o->c) return o->v;
	else if (k <= c) return Kth(o->ch[0], k);
	else return Kth(o->ch[1], k-c-o->c);
}
int Rank(Node* o, const int x)
{
	int d = o->cmp(x), c1 = o->ch[0] == NULL ? 0 : o->ch[0]->s;
	if (d == -1) return c1+1;
	else return Rank(o->ch[d], x) + (c1+o->c) * d;
}
const int INF = 2147483647;
int Prev(Node* o, const int x)
{
	int Ret = -INF;
	while (o != NULL)
	{
		if (o->v > Ret && o->v < x) Ret = o->v;
		if (x <= o->v) o = o->ch[0];
		else o = o->ch[1];
	}
	return Ret;
}
int Next(Node* o, const int x)
{
	int Ret = INF;
	while (o != NULL)
	{
		if (o->v < Ret && o->v > x) Ret = o->v;
		if (x < o->v) o = o->ch[0];
		else o = o->ch[1];
	}
	return Ret;
}

int main()
{
	srand(19260817);
//	ios::sync_with_stdio(false);
	
	int q;
	scanf("%d", &q);
//	cin >> q;
	while (q--)
	{
		int a, b;
		scanf("%d%d", &a, &b);
//		cin >> a >> b;
		if (a == 1) Insert(Root, b);
		else if (a == 2) Remove(Root, b);
		else if (a == 3) printf("%d\n", Rank(Root, b));//cout << Rank(Root, 3) << endl;
		else if (a == 4) printf("%d\n", Kth(Root, b));//cout << Kth(Root, b) << endl;
		else if (a == 5) printf("%d\n", Prev(Root, b));//cout << Prev(Root, b) << endl;
		else printf("%d\n", Next(Root, b));//cout << Next(Root, b) << endl;
	}
	
	return 0;
}

