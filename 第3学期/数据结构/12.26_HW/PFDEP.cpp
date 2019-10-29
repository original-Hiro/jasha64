#include <iostream>
#include <vector>
#include <queue>
#include <cstdlib>
using namespace std;

const int N = 101;
vector<int> G[N];
int ind[N]; //inDegree

int main()
{
	int n, m;
	cin >> n >> m;
	while (m--)
	{
		int tar, k;
		cin >> tar >> k; ind[tar] = k;
		int dep;
		while (k--) {cin >> dep; G[dep].push_back(tar);}
	}
	
	priority_queue<int, vector<int>, greater<int>> Exec;
	for (int i = 1; i <= n; i++)
		if (ind[i] == 0) Exec.push(i);
	bool fir = 1;
	while (!Exec.empty())
	{
		int v = Exec.top(); Exec.pop();
		if (!fir) cout << ' ';
		else fir = 0;
		cout << v;
		for (auto u : G[v])
			if (--ind[u] == 0) Exec.push(u);
	}
	cout << endl;
	
	return 0;
}

