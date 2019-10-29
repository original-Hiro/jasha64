#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

long long a, b, c, m;
inline long long Next_Random(long long Prev) {return a * Prev * Prev + b * Prev + c;}

int main()
{
	freopen("1.in", "w", stdout);
	
	int i, j, n;
	long long k, x0;
	
	cin >> x0 >> a >> b >> c;
	
	cout << (n = 5) << ' ' << (m = 25) << endl;
	srand(k = Next_Random(x0));
	for (i = 1; i <= m; ++i)
	{
		for (j = 1; j <= 2; ++j) cout << (k = Next_Random(k) % n) + 1 << ' ';
		for (j = 1; j <= 2; ++j) cout << (k = Next_Random(k) % m) << ' ';
		cout << (k = rand() % m) << endl;
	}
	
	return 0;
}

