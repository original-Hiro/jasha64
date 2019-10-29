#include <iostream>
#include <algorithm>
using namespace std;

const int N = 1007;
int Res, n, Match[N];
bool G[N][N], u[N];

bool Calc(int x)
{
	for (int i = 0; i < n; ++i)
		if (G[x][i] && !u[i])
		{
			u[i] = true;
			if (Match[i] == -1 || Calc(Match[i])) {Match[i] = x; return true;}
		}
	return false;
}

int main()
{
	int m, i, c1, c2;
	
	cin >> n >> m;
	for (i = 0; i < m; ++i)
		{cin >> c1 >> c2; G[i][c1] = G[i][c2] = true;}
	
	fill(Match, Match + N, -1);
	for (i = 0; i < m; ++i)
	{
		fill(u, u + N, false);
		if (Calc(i)) ++Res;
		else break;
	}
	
	cout << Res << endl;
	
	return 0;
}

