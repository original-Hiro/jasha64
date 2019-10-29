#include <iostream>
#include <algorithm>
using namespace std;

const int N = 100007;
int a[N], Top, Temp;
bool f[N] = {1};

int main()
{
	int c, m, n, t, i, j;
	
	while (cin >> c >> m)
	{
		Top = 0;
		while (m--)
		{
			cin >> n >> t;
			Temp = Top;
			for (i = 0; i <= Temp; i++)
				for (j = 1; j <= n && a[i] + j * t <= c; j++)
					if (!f[a[i] + j * t])
					{
						f[a[i] + j * t] = true;
						a[++Top] = a[i] + j * t;
					}
		}
		for (i = c; i >= 0; i--)
			if (f[i]) {cout << i << endl; break;}
		fill(f + 1, f + c + 1, false);
	}
	
	return 0;
}

