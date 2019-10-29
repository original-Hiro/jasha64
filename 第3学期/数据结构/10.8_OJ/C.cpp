#include <iostream>
using namespace std;

int f[100001];

int main()
{
	ios::sync_with_stdio(false);
	int n, s;
	cin >> n >> s;
	for (int i = 1, c; i <= n; i++) {cin >> c; f[i] = f[i-1] + c;}
	
	int res = 0;
	int l = 0;
	for (int r = 1; r <= n; r++)
	{
		while (f[r] - f[l] > s) l++;
		if (f[r] - f[l] == s) res++;
	}
	
	cout << res << endl;
	return 0;
}

