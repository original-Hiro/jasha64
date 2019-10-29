#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;
const ll N = 200007, INF = 9223372036854775807;
ll f[N], s[N], p[N], q[N], l[N], ans[N];

int main()
{
	ll n, t;
	ll i, j, dist;
	
	cin >> n >> t;
	for (i = 2; i <= n; i++) cin >> f[i] >> s[i] >> p[i] >> q[i] >> l[i];
	
	fill(ans + 2, ans + n + 1, INF);
	for (i = 2; i <= n; i++)
	{
		j = i;
		dist = 0;
		do {
			dist += s[j];
			j = f[j];
			if (dist > l[i]) break;
			ans[i] = min(ans[i], dist * p[i] + q[i] + ans[j]);
		} while (f[j] != j);
	}
	
	for (i = 2; i <= n; i++) cout << ans[i] << endl;
	
	return 0;
}

