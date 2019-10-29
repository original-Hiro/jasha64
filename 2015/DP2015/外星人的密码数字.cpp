#include <iostream>
#include <algorithm>
#include <string>
#include <map>
using namespace std;

const int N = 257;
int a[N], f[N];

int main()
{
	int i, j, Len;
	string s;
	map<char, int> m;
	
	cin >> s;
	Len = s.size();
	for (i = 1; i <= Len; i++) m[s[i - 1]] = i;
	
	while (cin >> s)
	{
		fill(f, f + N, 1);
		Len = s.size();
		for (i = 0; i < Len; i++) a[i] = m[s[i]];
		for (i = 1; i < Len; i++)
			for (j = 0; j < i; j++)
				if (a[i] >= a[j]) f[i] = max(f[i], f[j] + 1);
		cout << f[Len - 1];
	}
	cout << endl;
	
	return 0;
}

