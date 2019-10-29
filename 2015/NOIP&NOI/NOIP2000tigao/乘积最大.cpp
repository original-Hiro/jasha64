#include <iostream>
#include <algorithm>
#include <string>
#include <sstream>
using namespace std;

long long f[47][7];

int main()
{
	long long n, m;
	long long i, j, k, cache;
	string s;
	istringstream ss;
	
	cin >> n >> m >> s;
	
	f[1][0] = s[0] - '0';
	for (i = 2; i <= n; i++)
	{
		ss.str(s.substr(0, i));
		ss >> f[i][0];
		ss.clear();
		for (j = 1; j < i; j++)
		{
			ss.str(s.substr(j, i - j));
			ss >> cache;
			ss.clear();
			for (k = 1; k < i && k <= m; k++) f[i][k] = max(f[i][k], f[j][k - 1] * cache);
		}
	}
	
	cout << f[n][m] << endl;
	
	return 0;
}

