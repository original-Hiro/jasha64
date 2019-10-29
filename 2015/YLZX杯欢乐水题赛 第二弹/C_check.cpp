#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

const int N = 2007;
int f[N][N];

int main()
{
	int l1, l2, i, j, k;
	string s1, s2;
	
	cin >> s1 >> s2;
	l1 = s1.size(); l2 = s2.size();
	
	for (i = 3; i <= l1; ++i)
		for (j = 3; j <= l2; ++j)
		{
			f[i][j] = max(f[i - 1][j], f[i][j - 1]);
			for (k = 3; k <= min(i, j); ++k)
				if (s1.substr(i - k, k) == s2.substr(j - k, k))
					f[i][j] = max(f[i][j], f[i - k][j - k] + k);
				else break;
		}
	
	cout << f[l1][l2] << endl;
	
	return 0;
}

