#include <iostream>
#include <cstdio>
#include <cctype>
#include <algorithm>
using namespace std;

inline int Read()
{
	int r = 0;
	char c = getchar();
	while (!isdigit(c)) c = getchar();
	while (isdigit(c)) {r = r * 10 + c - '0'; c = getchar();}
	return r;
}

const int N = 100007, M = 1000001;
int a[N], f[M];

int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		int n;
		cin >> n;
		for (int i = 1; i <= n; i++) a[i] = Read();

		sort(a+1, a+n+1);
		fill(f, f+M, M);
		for (int i = 1; i <= n; i++)
			if (a[i] != a[i-1] && f[a[i]] == M) //optimization
				for (int j = 2*a[i]; j < M; j += a[i]) f[j] = min(f[j], a[i]);
			else if (f[a[i]] != M) a[i] = f[a[i]];

		long long Res = 0;
		for (int i = 1; i <= n; i++) Res += a[i];
		cout << Res << endl;
	}

	return 0;
}

