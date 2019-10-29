#include <iostream>
using namespace std;

const int N = 2007;
int n;
bool f[N], f1[N];
struct Vector
{
	int d[N], Top;
	
	void push(const int& x) {d[Top++] = x;}
	int size() {return Top;}
	int& operator [] (const int& x) {return d[x];}
} G[N], Solutions;

void DFS(const int& x)
{
	if (x == n)
	{
		for (int i = 2; i < n; i++)
			if (f[i] && !f1[i]) f[i] = false;
		return;
	}
	f1[x] = true;
	for (int i = 0; i < G[x].size(); i++)
		if (!f1[G[x][i]]) DFS(G[x][i]);
	f1[x] = false;
}

int main()
{
	int e, l, r, c, i;
	
	cin >> n >> e;
	while (e--)
	{
		cin >> l >> r;
		if (l == r) continue;
		G[l].push(r); G[r].push(l);
	}
	
	fill(f + 2, f + n, true);
	DFS(1);
	
	for (i = n - 1; i > 1; i--)
		if (f[i]) Solutions.push(i);
	cout << Solutions.size() << endl;
	if (Solutions.size()) cout << Solutions[Solutions.size() - 1];
	for (i = Solutions.size() - 2; i >= 0; i--) cout << ' ' << Solutions[i];
	cout << endl;
	
	return 0;
}

