#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

const int N = 20007;
struct Edge
{
	int s, t, w;
	friend bool operator < (const Edge& a, const Edge& b) {return a.w > b.w;}
} e[100007];
int f[N << 1];

int Find(int x)
{
	if (f[x] != x) return f[x] = Find(f[x]);
	return x;
}
inline void Merge(int a, int b) {f[Find(a)] = Find(b);}

int main()
{
	int n, m;
	
	cin >> n >> m;
	for (int i = 0; i < m; i++) scanf("%d%d%d", &e[i].s, &e[i].t, &e[i].w);
	
	sort(e, e + m);
	for (int i = 1; i <= (n << 1); i++) f[i] = i;
	for (int i = 0; i < m; i++)
	{
		if (Find(e[i].s) == Find(e[i].t)) {cout << e[i].w << endl; return 0;}
		else {Merge(e[i].s, e[i].t + n); Merge(e[i].s + n, e[i].t);}
	}
	cout << 0 << endl;
	
	return 0;
}

