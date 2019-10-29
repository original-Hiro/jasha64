#include <iostream>
#include <algorithm>
#include <cstdio> 
#include <cmath>
using namespace std;

const int N = 500007;
const double ln2 = log(2);
int a[N], f[N][20];

int main()
{
	int i, j, n, q, l, r;
	
	cin >> n;
	for (i = 1; i <= n; i++) scanf("%d", &a[i]);
	
	for (i = 1; i <= n; i++) f[i][0] = a[i];
	for (j = 1; (1 << j) <= n; j++)
		for (i = 1; i - 1 + (1 << j) <= n; i++)
			f[i][j] = max(f[i][j - 1], f[i + (1 << (j - 1))][j - 1]);
	
	cin >> q;
	while (q--)
	{
		scanf("%d%d", &l, &r);
		if (l > r) swap(l, r);
		j = log(r - l + 1) / ln2;
		printf("%d\n", max(f[l][j], f[r - (1 << j) + 1][j]));
	}
	
	return 0;
}

