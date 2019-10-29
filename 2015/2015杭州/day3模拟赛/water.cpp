#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const int N = 1007;
long long a[N];
int t;
vector<int> f[N];

int main()
{
	int n, r, i, j;
	long long Res = 0;
	
	cin >> n >> r;
	for (i = 0; i < n; i++) cin >> a[i];
	
	sort(a, a + n);
	while (t < n)
		for (i = 0; i < r; i++)
		{
			f[i].push_back(a[t++]);
			if (t >= n) break;
		}
	for (i = 0; i < r; i++)
		for (j = 0; j < f[i].size(); j++) Res += f[i][j] * (f[i].size() - j);
	
	cout << Res << endl;
	
	return 0;
}

