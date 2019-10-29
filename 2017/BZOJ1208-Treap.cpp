#include <iostream>
#include <cstdlib>
using namespace std;

const int MOD = 1000000;
struct Node
{
	Node* ch[2];
	int p, v, s;
	Node() {Node(0);}
	Node(int x):v(x) {s = 1; p = rand(); ch[0] = ch[1] = NULL;}
	int cmp(int x) const
	{
		if (x == v) return -1;
		return x < v ? 0 : 1;
	}
	void Maintain()
	{
		s = 1;
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
	Insert(o->ch[d], x); if (o->ch[d]->p > o->p) Rotate(o, d^1); o->Maintain();
}
inline void _Remove(Node* &o, int d) {Node* k = o; o = o->ch[d^1]; delete k;}
//特殊情况删除结点o：o的ch[d]为空 
void Remove(Node* &o, const int x)
{
	int d = o->cmp(x);
	if (d == -1)
	{
		if (o->ch[0] == NULL) _Remove(o, 0);
		else if (o->ch[1] == NULL) _Remove(o, 1);
		else {
			int d2 = (o->ch[1]->p > o->ch[0]->p ? 0 : 1);
			Rotate(o, d2); Remove(o->ch[d2], x);
		}
	}
	else Remove(o->ch[d], x);
	if (o) o->Maintain();
}
int Kth(Node* o, const int k)
{
	int c = (o->ch[0] == NULL ? 0 : o->ch[0]->s) + 1;
	if (c == k) return o->v;
	else if (k < c) return Kth(o->ch[0], k);
	else return Kth(o->ch[1], k-c);
}
int Rank(Node* o, const int x)
{
	int d = o->cmp(x), c = (o->ch[0] == NULL ? 0 : o->ch[0]->s) + 1;
	if (d == -1) return c;
	else return Rank(o->ch[d], x) + c*d;
}
int Prev(Node* o, const int x)
{
	int Ret = -1;
	while (o != NULL)
	{
		if ((Ret == -1 || o->v > Ret) && o->v <= x) Ret = o->v;
		if (x <= o->v) o = o->ch[0];
		else o = o->ch[1];
	}
	return Ret;
}
int Next(Node* o, const int x)
{
	int Ret = -1;
	while (o != NULL)
	{
		if ((Ret == -1 || o->v < Ret) && o->v > x) Ret = o->v;
		if (x < o->v) o = o->ch[0];
		else o = o->ch[1];
	}
	return Ret;
}
int Res = 0;
inline int Abs(int x) {return x < 0 ? -x : x;}
void Solve(Node* o, const int x)
{
	int c[] = {Prev(Root, x), Next(Root, x)};
	int d;
	if (c[0] == -1) d = 1;
	else if (c[1] == -1) d = 0;
	else {
		int d1 = x - c[0], d2 = c[1] - x;
		if (d1 <= d2) d = 0;
		else d = 1;
	}
	Res = (Res + Abs(c[d] - x)) % MOD; Remove(Root, c[d]);
}

int main()
{
	srand(19260817);
	ios::sync_with_stdio(false);
	
	int q;
	cin >> q;
	int sgn = -1;
	while (q--)
	{
		int a, b;
		cin >> a >> b;
		if (sgn == -1) {Root = new Node(b); sgn = a;}
		else if (sgn == a) Insert(Root, b);
		else {Solve(Root, b); if (Root == NULL) sgn = -1;}
	}
	cout << Res << endl;
	
	return 0;
}

