#include <iostream>
#include <algorithm>
using namespace std;

const int N = 507;
int G[N][N];

int main()
{
	int n, i, j, Res = 0, c;
	
	cin >> n;
	for (i = 1; i < n; ++i)
		for (j = i + 1; j <= n; ++j) {cin >> c; G[i][j] = G[j][i] = c;}
	
	for (i = 1; i <= n; ++i) sort(G[i] + 1, G[i] + n + 1, greater<int>());
	for (i = 1; i <= n; ++i) Res = max(Res, G[i][2]);
	
	cout << 1 << endl << Res << endl;
	
	return 0;
}

