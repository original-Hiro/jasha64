#include <iostream>
#include <algorithm>
using namespace std;

const int N = 5007;
int f[N], s1[N], s2[N];

int main()
{
	int n, s, i, j;
	
	cin >> n >> s;
	fill(f + 1, f + N, 0x3fffffff);
	for (i = 1; i <= n; ++i)
	{
		cin >> s1[i] >> s2[i];
		s1[i] += s1[i - 1]; s2[i] += s2[i - 1];
	}
	
	for (i = 1; i <= n; ++i)
		for (j = 1; j <= i; ++j)
			f[i] = min(f[i], f[j - 1] + s * (s2[n] - s2[j - 1]) + s1[i] * (s2[i] - s2[j - 1]));
	
	cout << f[n] << endl;
	
	return 0;
}

