#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

const int N = 1007;
int n, Low[N], DFN[N], Children[N], idx;
bool G[N][N], C[N];

inline int max(int a, int b, int c) {return max(a, max(b, c));}
void Tarjan(int x, int fa)
{
	Low[x] = DFN[x] = ++idx;
	for (int i = 1; i <= n; ++i)
		if (G[x][i])
			if (!DFN[i])
			{
				Tarjan(i, x); Low[x] = min(Low[x], Low[i]);
				if (Low[i] >= DFN[x]) ++Children[x];
			}
			else if (DFN[i] < DFN[x] && i != fa) Low[x] = min(Low[x], DFN[i]);
	if (fa < 0) --Children[x];
	if (Children[x]) ++Children[x];
}

int main()
{
	int T = 0, a, b, i;
	bool HaveC;
	
	while (cin >> a && a)
	{
		n = idx = 0;
		HaveC = false;
		memset(G, 0, sizeof(G));
		memset(Children, 0, sizeof(Children));
		memset(DFN, 0, sizeof(DFN));
		
		cin >> b; n = max(n, a, b); G[a][b] = G[b][a] = true;
		while (cin >> a && a) {cin >> b; n = max(n, a, b); G[a][b] = G[b][a] = true;}
		
		Tarjan(1, -1);
		
		cout << "Network #" << ++T << endl;
		for (i = 1; i <= n; ++i)
			if (Children[i])
			{
				HaveC = true;
				cout << "  SPF node " << i << " leaves " << Children[i] << " subnets" << endl;
			}
		if (!HaveC) cout << "  No SPF nodes" << endl;
		cout << endl;
	}
	
	return 0;
}

