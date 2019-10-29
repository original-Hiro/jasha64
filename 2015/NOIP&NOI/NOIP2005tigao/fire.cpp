#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
using namespace std;

const int N = 50007;
int n, g1[N], g2[N], Pos[N], Num[N];
bool Visited[N];

bool Build(int x, int p)
{
	Visited[x] = true; Pos[p] = x;
	if (p == n) return true;
	if ((!Visited[g1[x]] && Build(g1[x], p + 1)) || (!Visited[g2[x]] && Build(g2[x], p + 1)))
		return true;
	Visited[x] = false; return false;
}

int main()
{
	int i, a, b, Max = 0;
	
	cin >> n;
 	for (i = 1; i <= n; ++i) scanf("%d%d", &g1[i], &g2[i]);
	
	if (!Build(1, 1)) {cout << -1 << endl; return 0;}
	for (i = 1; i <= n; ++i) ++Num[(n + Pos[i] - i) % n];
	for (i = 0; i < n; ++i) Max = max(Max, Num[i]);
	fill(Num, Num + n, 0);
	reverse(Pos + 1, Pos + n + 1);
	for (i = 1; i <= n; ++i) ++Num[(n + Pos[i] - i) % n];
	for (i = 0; i < n; ++i) Max = max(Max, Num[i]);
	
	cout << n - Max << endl;
	
	return 0;
}

