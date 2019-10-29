#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

const int N = 1007;
int a[N][N], f[N][N];

int solve(int i, int j)
{
	if (!i || !j) return f[i][j] = 0;
	if (f[i][j] >= 0) return f[i][j];
	else return f[i][j] = a[i][j] + max(solve(i - 1, j), solve(i - 1, j - 1));
}

int main()
{
	int n;
	int i, j;
	
	cin >> n;
	for (i = 1; i <= n; i++)
		for (j = 1; j <= i; j++) cin >> a[i][j];
	
	memset(f, -1, sizeof(f));
	for (i = 1; i <= n; i++) solve(n, i);
	
	cout << *max_element(f[n] + 1, f[n] + n + 1) << endl;
	
	return 0;
}

