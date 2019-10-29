#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

const int N = 5007;
int a[N], In[N], b[N];
bool G[N][N], C[N][N];

int main()
{
	ios::sync_with_stdio(false);
	
	int n, m;
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	cin >> m;
	for (int i = 0, c, d; i < m; i++) {cin >> c >> d; G[c][d] = G[d][c] = true;}
	for (int k = 1; k <= n; k++)
		for (int i = 2; i <= n; i++)
			for (int j = 1; j < i; j++)
				if (G[i][k] && G[j][k]) C[i][j] = C[j][i] = true;
	for (int i = 2; i <= n; i++)
		for (int j = 1; j < i; j++) C[i][j] = C[j][i] = G[i][j] || C[i][j];
	memset(G, 0, sizeof(G));
	for (int i = 2; i <= n; i++)
		for (int j = 1; j < i; j++)
			if (C[i][j])
				if (a[i] < a[j]) {G[i][j] = true; ++In[j];}
				else if (a[j] < a[i]) {G[j][i] = true; ++In[i];}
	
	int k = 1;
	queue<int> Exec, PreExec;
	for (int i = 1; i <= n; i++)
		if (In[i] == 0) PreExec.push(i);
	while (!PreExec.empty())
	{
		Exec = PreExec;
		while (!PreExec.empty()) PreExec.pop();
		while (!Exec.empty())
		{
			int v = Exec.front(); Exec.pop();
			b[v] = k;
			for (int u = 1; u <= n; u++)
				if (G[v][u] && --In[u] == 0) PreExec.push(u);
		}
		++k;
	}
	
	int Res = 0;
	for (int i = 1; i <= n; i++) Res += b[i];
	cout << Res << endl;
	
	return 0;
}

