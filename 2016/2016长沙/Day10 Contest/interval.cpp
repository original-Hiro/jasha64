#include <fstream>
#include <algorithm>
using namespace std;

ifstream cin("interval.in");
ofstream cout("interval.out");
const int N = 27, BASE = 20, MOD = 10007;
int n, a[N];
bool v[N], u[MOD];

inline bool Legal()
{
	int Ret = 0, s, t = n;
	for (int i = 1; i <= n; i++)
		if (v[i])
		{
			if (Ret == 1) return false;
			else if (!Ret) {s = i; Ret = -1;}
		}
		else if (Ret == -1) {t = i - 1; Ret = 1;}
	
	int val = 0;
	for (int i = s; i <= t; i++) val = (val * BASE + i) % MOD;
	if (u[val]) return false;
	return u[val] = true;
}
void Work()
{
	for (int i = 1; i <= n; i++) cin >> a[i];
	
	int Res = 0;
	
	for (int il = 1; il <= n; il++)
		for (int ir = il; ir <= n; ir++)
			for (int jl = ir + 1; jl <= n; jl++)
				for (int jr = jl; jr <= n; jr++)
				{
					fill(v, v + N, false);
					for (int k = il; k <= ir; k++) v[a[k]] = true;
					for (int k = jl; k <= jr; k++) v[a[k]] = true;
					if (Legal()) ++Res;
				}
	
	cout << Res << endl;
}

int main()
{
	ios::sync_with_stdio(false);
	
	cin >> n;
	
	if (n <= 20) Work();
	else cout << n * (n - 1) / 2 << endl;
	
	return 0;
}

