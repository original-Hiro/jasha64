#include <iostream>
#include <algorithm>
using namespace std;

int f[1007][1007];

int main()
{
	string s1, s2;
	int i, j;
	
	cin >> s1 >> s2;
	 
	for (i = 1; i <= s1.size(); i++)
		for (j = 1; j <= s2.size(); j++)
			if (s1[i - 1] == s2[j - 1]) f[i][j] = f[i - 1][j - 1] + 1;
			else f[i][j] = max(f[i - 1][j], f[i][j - 1]);
	
	cout << f[s1.size()][s2.size()] << endl;
	
	return 0;
}

