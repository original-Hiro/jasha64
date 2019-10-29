#include <iostream>
#include <cstdio>
using namespace std;

const int N = 50007;
int fa[N];
struct Tree {int Num, Left, Right;} a[N];

int DFS(int x)
{
	if (!a[x].Left) return a[x].Num = 1;
	
	int Res = 1, i;
	
	for (i = a[x].Left; i; i = a[i].Right)
		Res += DFS(i);
	
	return a[x].Num = Res;
}

int main()
{
	int n, m, i, u, v, r, c;
	
	cin >> n >> m;
	for (i = 1; i <= n; ++i)
	{
		scanf("%d", &c);
		if (!c) r = i;
		else {fa[i] = c; a[i].Right = a[c].Left; a[c].Left = i;}
	}
	
	DFS(r);
	
	while (m--)
	{
		scanf("%d%d", &u, &v);
		if (!u)
			{a[fa[v]].Left = 0; fa[v] = r; a[v].Right = a[r].Left; a[r].Left = v; DFS(r);}
		else printf("%d\n", a[v].Num);
	}
	
	return 0;
}

