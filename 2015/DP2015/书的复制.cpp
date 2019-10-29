#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

const int N = 107;
int a[N], s[N], f[N][N], fa[N][N];
stack<int> Printer;

int main()
{
    int n, t, k, i, j, c;
    
	fill(f[0], f[0] + N * N, 10007);
	cin >> n >> t;
	if (n == 0 && t == 0) return 0;
	for (i = 1; i <= n; ++i)
	{
		cin >> a[i];
		s[i] = s[i - 1] + a[i];
	}
	
	for (i = 1; i <= n; ++i) f[i][0] = 0;
	for (i = 1; i <= n; ++i) f[1][i] = f[1][i - 1] + a[i];
	for (i = 1; i <= t; ++i)
		for (j = i; j <= n; ++j)
			for (k = j + 1; k <= n; ++k)
				if ((c = max(f[i - 1][j], s[k] - s[j])) < f[i][k]) {f[i][k] = c; fa[i][k] = j;}
	
	Printer.push(c = n);
	for (i = t; i > 1; --i) {c = fa[i][c]; Printer.push(c);}
	i = 1;
	while (!Printer.empty())
	{
		c = Printer.top(); Printer.pop();
		cout << i << ' ' << c << endl;
		i = c + 1;
	}
	
	return 0;
}

