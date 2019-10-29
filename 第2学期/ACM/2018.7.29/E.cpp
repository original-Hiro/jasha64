#include <iostream>
#include <string>
#include <map>
#include <cstring>
using namespace std;

map<string, int> m;
const int N = 507;
bool G[N][N][2];

int main()
{
	ios::sync_with_stdio(false);
	
	int t, q;
	cin >> t >> q;
	string a, op, b;
	int n = 0;
	while (t--)
	{
		cin >> a >> op >> b;
		if (m.find(a) == m.end()) m[a] = ++n;
		if (m.find(b) == m.end()) m[b] = ++n;
		int u = m[a], v = m[b];
		if (op[0] == 'i') G[u][v][0] = 1;
		else if (op[0] == 'h') G[u][v][1] = 1;
	}
	for (int i = 1; i <= n; i++) G[i][i][0] = 1;
	
	for (int k = 1; k <= n; k++)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
			{
				G[i][j][1] |= G[i][k][1] & G[k][j][1];
				G[i][j][1] |= G[i][k][0] & G[k][j][1];
				G[i][j][1] |= G[i][k][1] & G[k][j][0];
				G[i][j][0] |= G[i][k][0] & G[k][j][0];
			}
	
	for (int i = 1; i <= q; i++)
	{
		cin >> a >> op >> b;
		cout << "Query " << i << ": ";
		int u = m[a], v = m[b];
		if ((op[0] == 'i' && G[u][v][0]) || (op[0] == 'h' && G[u][v][1])) cout << "true" << endl;
		else cout << "false" << endl;
	}
	
	return 0;
}

