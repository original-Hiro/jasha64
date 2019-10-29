#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;

const int N = 1001, S = 50001;
int f[S], g[S];
bool f2[S], g2[S];
queue<int> q[N];

int main()
{
	int n, s;
	cin >> n >> s;
	for (int i = 0, a, b; i < n; i++) {cin >> a >> b; q[a].push(b);}

	memset(f, -1, sizeof(f)); f[0] = 0;
	for (int i = 1; i < N; i++) {
        memset(f2, 0, sizeof(f2));
		while (!q[i].empty()) {
            memset(g, -1, sizeof(g)); memset(g2, 0, sizeof(g2));
			int c = q[i].front(); q[i].pop();
			for (int j = 0; j <= s; j++) {
				if (j+c <= s && f[j] != -1 && g[j+c] < f[j] + !f2[j]) {g[j+c] = f[j] + !f2[j]; g2[j+c] = 1;}
				if (g[j] <= f[j]) {g[j] = f[j]; g2[j] = f2[j];}
			}
			memcpy(f, g, sizeof(g)); memcpy(f2, g2, sizeof(g2));
		}
    }

	if (f[s] == -1) cout << "Impossible" << endl;
	else cout << f[s] << endl;
	return 0;
}

