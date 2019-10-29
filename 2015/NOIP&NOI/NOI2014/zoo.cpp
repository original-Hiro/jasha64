#include <iostream>
#include <algorithm>
using namespace std;

const long long N = 207, MOD = 1000000007;
long long num[N];

int main()
{
	int n;
	int i, j, k, res;
	bool OK;
	string s;
	
	cin >> n;
	while (n--)
	{
		cin >> s;
		fill(num, num + N, 0);
		
		for (i = 1; i <= s.size(); i++)
			for (j = 1; 2 * j <= i; j++)
			{
				OK = 1;
				for (k = 0; k < j; k++)
					if (s[k] != s[i - j + k]) {OK = 0; break;}
				if (OK) num[i]++;
			}
		
		res = 1;
		for (i = 1; i <= s.size(); i++) res = res * (num[i] + 1) % MOD;
		cout << res << endl;
	}
	
	return 0;
}

