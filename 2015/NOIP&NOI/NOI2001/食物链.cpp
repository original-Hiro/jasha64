#include <iostream>
#include <cstdio>
using namespace std;

const int N = 150007;
int f[N];

int Find(int x)
{
	if (f[x] != x) return f[x] = Find(f[x]);
	return x;
}

int main()
{
	int n, i, k, c1, c2, a, b, c, Res = 0;
	
	cin >> n >> k;
	for (i = 1; i <= n * 3; i++) f[i] = i;
	while (k--)
	{
		scanf("%d%d%d", &a, &b, &c);
		if (b > n || c > n || (a == 2 && b == c)) {Res++; continue;}
		b += n; c += n;
		if (a == 1)
		{
			if (Find(b) == Find(c - n) || Find(b) == Find(c + n)) {Res++; continue;}
			f[Find(b)] = Find(c); f[Find(b + n)] = Find(c + n); f[Find(b - n)] = Find(c - n);
		}
		else {
			if (Find(b) == Find(c) || Find(b) == Find(c + n)) {Res++; continue;}
			f[Find(b + n)] = Find(c); f[Find(c - n)] = Find(b); f[Find(b - n)] = Find(c + n); 
		}
	}
	
	cout << Res << endl;
	
	return 0;
}

