#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

const int N = 100007;
long long a[N], l[N], r[N];

int main()
{
	int i, n, x;
	long long Res;
	
	cin >> n >> x;
	for (i = 1; i <= n; ++i) {scanf("%lld", &a[i]); l[i] = l[i - 1] | a[i];}
	for (i = n; i > 0; --i) r[i] = r[i + 1] | a[i];
	
	Res = (a[1] * x) | r[2];
	for (i = 2; i <= n; ++i) Res = max(Res, l[i - 1] | (a[i] * x) | r[i + 1]);
	
	cout << Res << endl;
	
	return 0;
}

