#include <cstdio>
#include <algorithm>
using namespace std;

const int N = 800007;
double a[N], f[N];

int main()
{
	freopen("cat.in", "r", stdin);
	freopen("cat.out", "w", stdout);
	
	int n, i;
	
	scanf("%d", &n);
	for (i = 1; i <= n; i++) scanf("%lf", &a[i]);
	
	f[1] = max(0.0, a[1]);
	for (i = 2; i <= n; i++) f[i] = max(f[i - 2] + a[i - 1] * a[i - 1], max(f[i - 1] + a[i], f[i - 1]));
	f[n] = max(f[n], f[n - 1] + a[n] * a[n]);
	
	printf("%.4lf\n", f[n]);
	
	return 0;
}

