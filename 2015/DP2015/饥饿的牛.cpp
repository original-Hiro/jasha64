#include <iostream>
#include <algorithm>
using namespace std;

const int N = 1007;
int l[N], r[N], f[N];

int main()
{
	int n, i, j, c;
	
	cin >> n;
	for (i = 1; i <= n; i++) cin >> l[i] >> r[i];
	
	for (i = 1; i <= n; i++)
	{
		c = 0;
		for (j = 1; j < i; j++)
			if (l[j] <= r[i] && l[i] <= r[j]) c += r[j] - l[j] + 1;
		f[i] = max(f[i - 1], f[i - 1] - c + r[i] - l[i] + 1);
	}
	
	cout << f[n] << endl;
	
	return 0;
}

