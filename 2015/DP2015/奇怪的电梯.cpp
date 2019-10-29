#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

const int N = 207, INF = 10000007;
int a[N], f[N];
bool inq[N];
queue<int> q;

int main()
{
	int n, s, t, i, c;
	
	cin >> n >> s >> t;
	for (i = 1; i <= n; ++i) cin >> a[i];
	
	fill(f + 1, f + n + 1, INF);
	f[s] = 0; q.push(s); inq[s] = true;
	while (!q.empty())
	{
		c = q.front(); q.pop(); inq[c] = false;
		if (c + a[c] <= n && f[c + a[c]] > f[c] + 1)
		{
			f[c + a[c]] = f[c] + 1;
			if (!inq[c + a[c]]) {q.push(c + a[c]); inq[c + a[c]] = true;}
		}
		if (c - a[c] > 0 && f[c - a[c]] > f[c] + 1)
		{
			f[c - a[c]] = f[c] + 1;
			if (!inq[c - a[c]]) {q.push(c - a[c]); inq[c - a[c]] = true;}
		}
	}
	
	if (f[t] == INF) cout << -1 << endl;
	else cout << f[t] << endl;
	
	return 0;
}

