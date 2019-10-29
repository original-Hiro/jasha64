#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <cstdio>
using namespace std;

const long long N = 1000007, MOD = 100000007, BASE = 131;
long long h[N];
char s[N];

inline long long idx(char c) {return c - 'a' + 1;}

int main()
{
	while (scanf("%s", s) == 1)
	{
		if (s[0] == '.') break;
		int len = strlen(s), Res = 0;
		h[len] = 0;
		for (int i = len - 1; i >= 0; i--) h[i] = (h[i + 1] * BASE + idx(s[i])) % MOD;
		for (int i = sqrt(len) + 1; i > 0; i--)
			if (len % i == 0)
			{
				if (h[0] % h[len - len / i] == 0) Res = max(Res, i);
				if (h[0] % h[len - i] == 0) Res = max(Res, len / i);
			}
		cout << Res << endl;
	}
	
	return 0;
}

