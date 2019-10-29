#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;

const int N = 200007;
long long a[N];
int n;

void Work1()
{
	const int N1 = 3007, INF = 1073741823;
	int f[N1];
	fill(f, f + N1, -INF);
	f[1] = -a[1];
	for (int i = 2; i <= n; i++)
		for (int k = i & 1; k <= i; k += 2)
			f[k] = max(f[k], max(f[k - 1] - (int)a[i], f[k + 1] + (int)a[i]));
	cout << f[n & 1] << endl;
}
void Work2()
{
	long long Res = 0;
	
}

int main()
{
	freopen("stock.in", "r", stdin);
	freopen("stock.out", "w", stdout);
	
	cin >> n;
	for (int i = 1, j; i <= n; i++) {scanf("%d", &j); a[i] = j;}
	
	if (n <= 3000) Work1();
	else Work2();
	
	return 0;
}

