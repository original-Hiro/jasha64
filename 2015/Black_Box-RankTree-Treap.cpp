#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

const int N = 30007;
struct Node
{
	int p, v, s;
	Node* ch[2];
	
	Node(int v):v(v) {p = rand(); ch[0] = ch[1] = NULL; s = 1;}
	int cmp(int x) const
	{
		if (x == v) return -1;
		return x < v ? 0 : 1;
	}
	void Maintain()
	{
		s = 1;
		if (ch[0]) s += ch[0] -> s;
		if (ch[1]) s += ch[1] -> s;
	}
};
Node* Root;
int i, v, a[N];

void Rotate(Node* &o, int d)
{
	Node* k = o -> ch[d ^ 1]; o -> ch[d ^ 1] = k -> ch[d]; k -> ch[d] = o;
	o -> Maintain(); k -> Maintain(); o = k;
}
void Insert(Node* &o)
{
	if (o == NULL) {o = new Node(v); o -> Maintain(); return;}
	int d = o -> cmp(v);
	Insert(o -> ch[d]); if (o -> ch[d] -> p > o -> p) Rotate(o, d ^ 1); o -> Maintain();
}
void Remove(Node* &o)
{
	int d = o -> cmp(v);
	if (d == -1)
	{
		if (o -> ch[0] == NULL) o = o -> ch[1];
		else if (o -> ch[1] == NULL) o = o -> ch[0];
		else {
			int d2 = o -> ch[0] -> p > o -> ch[1] -> p ? 1 : 0;
			Rotate(o, d2); Remove(o -> ch[d2]);
		}
	}
	else Remove(o -> ch[d]);
	if (o) o -> Maintain();
}
bool Find(Node* o)
{
	int d;
	while (o)
	{
		d = o -> cmp(v);
		if (d == -1) return true;
		o = o -> ch[d];
	}
	return false;
}
int Kth(Node* o, int k)
{
	if (o == NULL || k <= 0 || k > o -> s) return 0;
	int s = o -> ch[0] == NULL ? 0 : o -> ch[0] -> s;
	if (s + 1 == k) return o -> v;
	else if (k <= s) return Kth(o -> ch[0], k);
	else return Kth(o -> ch[1], k - s - 1);
}

int main()
{
	int n, m, q, s = 0;
	
	srand(time(NULL));
	ios::sync_with_stdio(false);
	
	cin >> n >> q;
	for (int j = 1; j <= n; ++j) cin >> a[j];
	
	i = 0;
	while (q--)
	{
		cin >> m;
		while (s < m) {v = a[++s]; Insert(Root);}
		cout << Kth(Root, ++i) << endl;
	}
	
	return 0;
}

