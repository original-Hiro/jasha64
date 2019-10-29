#include <iostream>
#include <algorithm>
using namespace std;

const int N = 100007, M = 420007;
int n, t[M], Next[M], Head[N], Low[N], DFN[N], idx;
bool C[M];

void Tarjan(int x, int fa)
{
	int i = Head[x], Child = 0;
	DFN[x] = Low[x] = ++idx;
	while (i)
	{
		if (!DFN[t[i]])
		{
			++Child; Tarjan(t[i], x); Low[x] = min(Low[x], Low[t[i]]);
			if (Low[t[i]] > DFN[x]) C[i] = true;
		}
		else if (DFN[t[i]] < DFN[x] && t[i] != fa) Low[x] = min(Low[x], DFN[t[i]]);
		i = Next[i];
	}
}

int main()
{
	int m, a, b, Res, T = 0, i;
	
	while (cin >> n >> m && n)
	{
		Res = idx = 0;
		fill(C, C + M, 0);
		fill(DFN, DFN + N, 0);
		fill(Head, Head + N, 0);
		m <<= 1;
		for (i = 1; i <= m; ++i)
		{
			scanf("%d%d", &a, &b);
			t[i] = b; Next[i] = Head[a]; Head[a] = i;
			t[++i] = a; Next[i] = Head[b]; Head[b] = i;
		}
		Tarjan(1, -1);
		for (i = 1; i <= m; ++i)
			if (C[i]) ++Res;
		cout << "Case " << ++T << ':' << endl << Res << endl << endl;
	}
	
	return 0;
}

