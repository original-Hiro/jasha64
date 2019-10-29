#include <iostream>
#include <algorithm>
#include <string>
#include <sstream>
using namespace std;

const int N = 1007;
int n, h[N], f[N], g[N];

int main()
{
	int i, j;
	string s;
	istringstream ss;
	
	while (getline(cin, s))
	{
		fill(f, f + N, 1);
		fill(g, g + N, 1);
		n = 0;
		ss.str(s);
		while (ss >> h[n]) n++;
		ss.clear();
		
		for (i = 1; i < n; i++)
			for (j = 0; j < i; j++)
				if (h[i] <= h[j]) f[i] = max(f[i], f[j] + 1);
		for (i = 1; i < n; i++)
			for (j = 0; j < i; j++)
				if (h[i] > h[j]) g[i] = max(g[i], g[j] + 1);
		
		cout << *max_element(f, f + n) << endl << *max_element(g, g + n) << endl;
	}
	
	return 0;
}

