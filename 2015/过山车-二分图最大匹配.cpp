#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

typedef const int& int_;
const int N = 507;
int n2, Match[N];
bool G[N][N], u[N];

bool Calc(int_ x)
{
	for (int i = 1; i <= n2; ++i)
		if (G[x][i] && !u[i])
		{
			u[i] = true;
			if (!Match[i] || Calc(Match[i]))
			{
				Match[i] = x;
				return true;
			}
		}
	return false;
}

int main()
{
	int i, k, n1, a, b, Res;
	
	while (cin >> k && k)
	{
		Res = 0;
		fill(Match, Match + N, 0);
		memset(G, 0, sizeof(G));
		
		cin >> n1 >> n2;
		while (k--)
		{
			scanf("%d%d", &a, &b);
			G[a][b] = true;
		}
		
		for (i = 1; i <= n1; ++i)
		{
			fill(u + 1, u + n2 + 1, false);
			if (Calc(i)) ++Res;
		} 
		
		cout << Res << endl;
	}
	
	return 0;
}

