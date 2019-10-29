#include <iostream>
#include <cstdio>
using namespace std;

const int N = 100007;
int a[N], s[N], p[N];

int main()
{
	int T, n, i, j, Pos;
	
	cin >> T;
	for (j = 0; j < T;)
	{
		p[1] = 0; Pos = 1;
		
		cin >> n;
		for (i = 1; i <= n; i++)
		{
			scanf("%d", &a[i]);
			s[i] = s[i - 1] + a[i];
			if (s[i] < s[p[i]]) p[i + 1] = i;
			else p[i + 1] = p[i];
		}
		for (i = 2; i <= n; i++)
			if (s[i] - s[p[i]] > s[Pos] - s[p[Pos]]) Pos = i;
		
		if (j) cout << endl;
		cout << "Case " << ++j << ':' << endl << s[Pos] - s[p[Pos]] << ' ' << p[Pos] + 1 << ' ' << Pos << endl;
	}
	
	return 0;
}

