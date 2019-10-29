#include <iostream>
#include <algorithm>
using namespace std;

int f[30005];

int main()
{
	int N, m, v, p;
	int i, j;
	
	cin >> N >> m;
	
	for (i = 0; i < m; i++)
	{
		cin >> v >> p;
		
		for (j = N; j >= v; j--)
			f[j] = max(f[j], f[j - v] + v * p);
	}
	
	cout << f[N] << endl;
	
	return 0;
}

