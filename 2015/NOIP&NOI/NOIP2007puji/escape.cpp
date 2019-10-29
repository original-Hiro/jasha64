#include <iostream>
#include <algorithm>
using namespace std;

int f[2][17];

int main()
{
	int i = 0, j, d = 0, m, s, t, c;
	
	cin >> m >> s >> t;
	
	while (m >= 10)
	{
		m -= 10; ++i; d += 60;
		if (d >= s) {cout << "Yes" << endl << i << endl; return 0;}
		if (i >= t) {cout << "No" << endl << d << endl; return 0;}
	}
	
	fill(f[i & 1], f[i & 1] + 14, 0xcfffffff);
	f[i & 1][m] = d;
	for (++i; i <= t; ++i)
	{
		c = i & 1;
		for (j = 0; j < 4; ++j) f[c][j] = max(f[c ^ 1][j] + 17, f[c ^ 1][j + 10] + 60);
		for (j = 4; j <= 13; ++j) f[c][j] = max(f[c ^ 1][j] + 17, f[c ^ 1][j - 4]);
		if (*max_element(f[c], f[c] + 14) >= s) {cout << "Yes" << endl << i << endl; return 0;}
	}
	cout << "No" << endl << *max_element(f[c], f[c] + 14) << endl;
	
	return 0;
}

