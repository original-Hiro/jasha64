#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;

const int N = 100007;
int Depth[N], Head[N], f[27];
bool Leaf[N], v[N], Black[27];
struct Edge {int s, t, Next;} e[N << 1];

void BFS()
{
	int i, t;
	queue<int> q;
	
	q.push(1);
	while (!q.empty())
	{
		t = q.front(); q.pop(); v[t] = true;
		i = Head[t];
		while (i)
		{
			if (!v[e[i].t])
			{
				q.push(e[i].t);
				Depth[e[i].t] = Depth[e[i].s] + 1;
				Leaf[e[i].s] = false;
			}
			i = e[i].Next;
		}
	}
}
void BFS2()
{
	int i, t;
	queue<int> q;
	
	fill(f + 1, f + 21, 0);
	fill(v + 1, v + 21, 0);
	q.push(1);
	if (Black[1]) f[1] = 1;
	while (!q.empty())
	{
		t = q.front(); q.pop(); v[t] = true;
		i = Head[t];
		while (i)
		{
			if (!v[e[i].t])
			{
				q.push(e[i].t);
				if (Black[e[i].t]) f[e[i].t] = f[e[i].s] + 1;
				else f[e[i].t] = f[e[i].s];
			}
			i = e[i].Next;
		}
	}
}

int main()
{
	int Res, Num = 0, i, j, n, c, ALL_BITS;
	
	cin >> n;
	for (i = 1; i < ((n - 1) << 1); ++i)
	{
		scanf("%d%d", &e[i].s, &e[i].t);
		e[i].Next = Head[e[i].s]; Head[e[i].s] = i; ++i;
		e[i].s = e[i - 1].t; e[i].t = e[i - 1].s;
		e[i].Next = Head[e[i].s]; Head[e[i].s] = i;
	}
	
	fill(Leaf + 1, Leaf + n + 1, true);
	BFS();
	
	Res = N;
	for (i = 1; i <= n; ++i)
		if (Leaf[i]) {++Num; Res = min(Res, Depth[i]);}
	if (n > 20) cout << Res * Num << endl;
	else {
		ALL_BITS = 1 << n;
		Res = 0;
		for (i = 1; i < ALL_BITS; ++i)
		{
			Num = 0;
			fill(Black + 1, Black + n + 1, false);
			for (j = 1; j <= n; ++j)
				if (i & (1 << (j - 1))) Black[j] = true;
			BFS2();
			for (j = 1; j <= n; ++j)
				if (Leaf[j]) {c = f[j]; break;}
			for (j = 1; j <= n; ++j)
				if (Leaf[j] && f[j] != c) break;
			if (j <= n && Leaf[j] && f[j] != c) continue;
			for (j = 1; j <= n; ++j)
				if (Black[j]) ++Num;
			Res = max(Res, Num);
		}
		cout << Res << endl;
	}
	
	return 0;
}

