#include <iostream>
using namespace std;

const long long N = 10000;
int f[N + 7];

int main()
{
	long long n, k, i, j, Res = 0;
	
	cin >> n >> k;
	if (!k) {cout << 0 << endl; return 0;}
	if (k == 1 || k == 10 || k == 100 || k == 1000) {cout << n << endl; return 0;}
	
	for (i = 1; i <= N; ++i)
	{
		j = i;
		while (j) {f[i] += j % 10; j /= 10;}
	}
	for (i = 1; i <= n; ++i)
		if (f[i / N] + f[i % N] == f[i * k / (N * N)] + f[i * k / N % N] + f[i * k % N]) ++Res;
	
	cout << Res << endl;
	
	return 0;
}

