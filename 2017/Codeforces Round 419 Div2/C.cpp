#include <iostream>
#include <algorithm>
using namespace std;

const int N = 107;
int a[N][N], n, m;
int b[N]; //每行最小值 
int c[N]; //每列最小值 
int d; //全局最小值 
int s[3]; //全局 行 列操作步数 

void Row()
{
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++) a[i][j] -= b[i];
		s[1] += b[i];
	}
}
void Col()
{
	for (int i = 1; i <= m; i++)
	{
		for (int j = 1; j <= n; j++) a[j][i] -= c[i];
		s[2] += c[i];
	}
}
void Solve()
{
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++) a[i][j] -= d;
	s[0] = min(n, m) * d;
	for (int i = 1; i <= n; i++) b[i] -= d;
	for (int j = 1; j <= m; j++) c[j] -= d;
	Row(); Col();
}
void Print()
{
	bool Unsolved = 0;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++) Unsolved |= a[i][j];
	if (Unsolved) {cout << -1 << endl; return;}
	cout << s[0] + s[1] + s[2] << endl;
	if (n <= m)
		for (int i = 1; i <= n; i++)
			for (int k = 1; k <= d; k++) cout << "row " << i << endl;
	else for (int i = 1; i <= m; i++)
			for (int k = 1; k <= d; k++) cout << "col " << i << endl;
	for (int i = 1; i <= n; i++)
		for (int k = 1; k <= b[i]; k++) cout << "row " << i << endl;
	for (int j = 1; j <= m; j++)
		for (int k = 1; k <= c[j]; k++) cout << "col " << j << endl;
}

int main()
{
	ios::sync_with_stdio(false);
	
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++) cin >> a[i][j];
	for (int i = 1; i <= n; i++)
	{
		b[i] = a[i][1];
		for (int j = 2; j <= m; j++) b[i] = min(b[i], a[i][j]);
	}
	for (int i = 1; i <= m; i++)
	{
		c[i] = a[1][i];
		for (int j = 2; j <= n; j++) c[i] = min(c[i], a[j][i]);
	}
	d = a[1][1];
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++) d = min(d, a[i][j]);
	
	Solve();
	Print();
	
	return 0;
}

