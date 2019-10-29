#include <cstdio>
#include <algorithm>
using namespace std;

const int N = 100001;
int f[N][18], dep[N];

int Query(int a, int b)
{
	while (true)
	{
		if (dep[a] < dep[b]) swap(a, b);
		int i;
		for (i = 17; i >= 0; i--)
			if (dep[f[a][i]] > dep[b]) break;
		a = f[a][i + 1];
		if (a == b) break;
	}
	return a;
}

int main()
{
	freopen("squirrel.in", "r", stdin);
	freopen("squirrel.out", "w", stdout);
	
	int n, q;
	scanf("%d%d", &n, &q);
	for (int i = 2; i <= n; i++) {scanf("%d", &f[i][0]); dep[i] = dep[f[i][0]] + 1;}
	
	for (int k = 1; k < 18; k <<= 1)
		for (int i = 1; i <= n; i++) f[i][k] = f[f[i][k - 1]][k - 1];
	
	int a, b;
	while (q--) {scanf("%d%d", &a, &b); printf("%d\n", Query(a, b));}
	
	return 0;
}

