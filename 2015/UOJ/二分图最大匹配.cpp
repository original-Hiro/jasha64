#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

typedef const int& int_;
const int N = 507;
int n2, Match[N], m_[N];
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
	int n1, m, a, b, i, Res = 0;
	
	cin >> n1 >> n2 >> m;
	while (m--)
	{
		scanf("%d%d", &a, &b);
		G[a][b] = true;
	}
	
	for (i = 1; i <= n1; ++i)
	{
		fill(u + 1, u + n2 + 1, false);
		if (Calc(i)) ++Res;
	}
	
	for (i = 1; i <= n2; ++i) m_[Match[i]] = i;
	cout << Res << endl << m_[1];
	for (i = 2; i <= n1; ++i) cout << ' ' << m_[i];
	cout << endl;
	
	return 0;
}

