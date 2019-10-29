#include <iostream>
#include <algorithm>
#include <cstdio>
#include <queue>
using namespace std;

const int N = 50007;
int n, m;
struct Edge {int u, d, Next;} e[N << 1];
int Head[N];
struct Node {int p; long long d;} f[N][17];
struct Army
{
	int p;
	long long r;
	friend bool operator < (const Army& a, const Army& b) {return a.r < b.r;}
} a[N];
long long b[N], Top1;
int c[N], Top2;
bool Cont[N], Leaf[N];

void BFS_LCA()
{
	int v, i, j;
	queue<int> q;
	
	q.push(1);
	while (!q.empty())
	{
		v = q.front(); q.pop();
		i = Head[v];
		while (i)
		{
			if (!f[e[i].u][0].p && e[i].u != 1)
				{f[e[i].u][0].p = v; f[e[i].u][0].d = e[i].d; q.push(e[i].u);}
			i = e[i].Next;
		}
	}
	
	for (i = 1; (1 << i) <= n; ++i)
		for (j = 1; j <= n; ++j)
		{
			if (!(f[j][i].p = f[f[j][i - 1].p][i - 1].p)) continue;
			f[j][i].d = f[j][i - 1].d + f[f[j][i - 1].p][i - 1].d;
		}
}
void Sort_Army()
{
	int i, j, k;
	for (i = 1; i <= m; ++i)
	{
		k = a[i].p; 
		for (j = 16; j >= 0; --j)
			if (f[k][j].p) {a[i].r += f[k][j].d; k = f[k][j].p;}
	}
	sort(a + 1, a + n + 1);
	reverse(a + 1, a + n + 1);
}
bool DFS(int x)
{
	if (Cont[x]) return true;
	if (Leaf[x]) return false;
	int i = Head[x];
	while (i)
	{
		if (e[i].u != f[x][0].p && !DFS(e[i].u)) return false;
		i = e[i].Next;
	}
	return Cont[x] = true;
}
bool Can(const long long& t)
{
	int i, j, k;
	
	Top1 = Top2 = 0;
	fill(Cont + 1, Cont + n + 1, false);
	for (i = 1; i <= m; ++i)
	{
		k = a[i].p; a[i].r = t;
		for (j = 16; j >= 0; --j)
			if (a[i].r >= f[k][j].d && f[k][j].p > 1) {a[i].r -= f[k][j].d; k = f[k][j].p;}
		if (a[i].r >= (f[k][0].d << 1) || (a[i].r > f[k][0].d && DFS(k)))
			{a[i].r -= f[k][0].d; b[Top1++] = a[i].r;}
		else Cont[k] = true;
	}
	i = Head[1];
	while (i)
	{
		if (!DFS(e[i].u)) c[Top2++] = e[i].d;
		i = e[i].Next;
	}
	sort(b, b + Top1); sort(c, c + Top2);
	for (i = j = 0; i < Top1 && j < Top2; ++i, ++j)
	{
		while (i < Top1 && b[i] < c[j]) ++i;
		if (i == Top1) break;
	}
	
	if (i == Top1 && j < Top2) return false;
	return true;
}

int main()
{
	int i, j = 0, u, v, d, Root_Edge_Count = 0;
	cin >> n;
	for (i = 1; i < n; ++i)
	{
		scanf("%d%d%d", &u, &v, &d);
		if (u == 1 || v == 1) ++Root_Edge_Count;
		e[++j].u = v; e[j].Next = Head[u]; e[j].d = d; Head[u] = j;
		e[++j].u = u; e[j].Next = Head[v]; e[j].d = d; Head[v] = j;
		if (!Cont[u])
		{
			if (!Leaf[u]) Leaf[u] = true;
			else {Cont[u] = true; Leaf[u] = false;}
		}
		if (!Cont[v])
		{
			if (!Leaf[v]) Leaf[v] = true;
			else {Cont[v] = true; Leaf[v] = false;}
		}
	}
	BFS_LCA();
	cin >> m;
	if (m < Root_Edge_Count) {cout << -1 << endl; return 0;}
	for (i = 1; i <= m; ++i) scanf("%d", &a[i].p);
	Sort_Army();
	
	long long Low = 0, Mid, High = (n - 1) * 1000000000ll;
	while (Low <= High)
		if (Can(Mid = (Low + High) >> 1)) High = Mid - 1;
		else Low = Mid + 1;
	
	cout << Low << endl;
	
	return 0;
}

