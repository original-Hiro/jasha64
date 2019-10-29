#include <fstream>
#include <algorithm>
#include <string>
using namespace std;

ifstream cin("savour.in");
ofstream cout("savour.out");
const int N = 2007;
const long long INF = -1000000000000000007;
string s;
int a[N], f[N][N];

int main()
{
	int n, i, j, k;
	cin >> n;
	if (n > 2000) return 0;
	cin >> s;
	for (i = 0; i < n; i++) cin >> a[i];
	
	for (i = 0; i < n; i++)
		for (j = i + 1; j < n; j++)
		{
			if (f[i][j]) continue;
			for (k = 0; j + k < n && s[i + k] == s[j + k]; k++) f[i][j]++;
			for (k = 1; j + k < n && k <= f[i][j]; k++) f[i + k][j + k] = f[i][j] - k;
		}
	
	long long Res1, Res2;
	for (i = 0; i < n; i++)
	{
		Res1 = 0;
		Res2 = INF;
		for (j = 0; j < n; j++)
			for (k = j + 1; k < n; k++)
				if (f[j][k] >= i)
				{
					Res1++;
					Res2 = max(Res2, (long long)a[j] * a[k]);
				}
		cout << Res1 << ' ' << (Res2 == INF ? 0 : Res2) << endl;
	}
	
	return 0;
}

