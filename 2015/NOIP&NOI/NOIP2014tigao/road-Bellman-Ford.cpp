#include <fstream>
#include <algorithm>
using namespace std;

ifstream cin("road.in");
ofstream cout("road.out");
const int N = 10007, INF = 200007;
int f[N], l[INF], r[INF];
bool c1[N], c2[N];

int main()
{
	int n, m, s, t;
	int i, j, pos;
	bool done;
	
	cin >> n >> m;
	for (i = 0; i < m; i++)	cin >> l[i] >> r[i];
	cin >> s >> t;
	
	c1[t] = 1;
	do {
		done = 1;
		for (i = 0; i < m; i++)
			if (!c1[l[i]] && c1[r[i]])
			{
				done = 0;
				c1[l[i]] = 1;
			}
	} while (!done);
	copy(c1, c1 + n + 1, c2);
	do {
		done = 1;
		for (i = 0; i < m; i++)
			if (c2[l[i]] && !c1[r[i]])
			{
				done = 0;
				c2[l[i]] = 0;
			}
	} while (!done);
	fill(f + 1, f + s, INF);
	fill(f + s + 1, f + n + 2, INF);
	do {
		done = 1;
		for (i = 0; i < m; i++)
			if (c2[l[i]] && c2[r[i]] && f[l[i]] + 1 < f[r[i]])
			{
				done = 0;
				f[r[i]] = f[l[i]] + 1;
			}
	} while (!done);
	
	if (f[t] == INF) cout << -1 << endl;
	else cout << f[t] << endl;
	
	return 0;
}

