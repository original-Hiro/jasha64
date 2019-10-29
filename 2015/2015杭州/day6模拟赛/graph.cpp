#include <fstream>
using namespace std;

ifstream cin("graph.in");
ofstream cout("graph.out");
const int N = 507;
int n, a[N][N], b[N][N], fa[N], fb[N];

void DFS(const int& x)
{
	if (a[x][n]) {fa[n] = max(fa[x], a[x][n]); fb[n] = max(fb[x], b[x][n]); return;}
	for (int i = x + 1; i <= n; i++)
		if (a[x][i]) {fa[i] = max(fa[x], a[x][i]); fb[i] = max(fb[x], b[x][i]); DFS(i);}
}

int main()
{
	int m, i, l, r, a0, b0;
	
	cin >> n >> m;
	if (n > 500) {cout << -1 << endl; return 0;}
	for (i = 0; i < m; i++)
	{
		cin >> l >> r >> a0 >> b0;
		a[l][r] = a[r][l] = a0; b[l][r] = b[r][l] = b0;
	}
	
	DFS(1);
	
	cout << fa[n] + fb[n] << endl;
	
	return 0;
}

