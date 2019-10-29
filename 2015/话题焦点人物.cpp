#include <iostream>
#include <cstdio>
using namespace std;

int Count[107];
bool t[107][107];

int main()
{
	int n, i, j, a, c, cc, m, p = 1;
	bool First = true;
	
	cin >> n;
	for (i = 0; i < n; ++i)
	{
		scanf("%d%d", &a, &m);
		while (m--) {scanf("%d", &c); t[a][c] = true; ++Count[c];}
	}
	
	c = 0;
	for (i = 2; i <= 100; ++i)
		if (Count[i] > c) {c = Count[i]; p = i;}
	
	cout << p << endl;
	for (i = 1; i <= 100; ++i)
		if (t[i][p])
		{
			if (!First) cout << ' ';
			cout << i;
			First = false;
		}
	cout << endl;
	
	return 0;
}

