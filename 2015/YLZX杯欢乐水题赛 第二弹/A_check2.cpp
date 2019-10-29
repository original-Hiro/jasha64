#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cctype>
using namespace std;

int a[10000007];

int main()
{
	int n, i;
	
	cin >> n;
	for (i = 1; i <= n; ++i) scanf("%d", &a[i]);
	for (i = n - 1; i > 0; --i) a[i] -= a[i + 1];
	
	sort(a + 1, a + n + 1, greater<int>());
	
	cout << a[1] << ' ' << a[2] << ' ' << a[3] << endl;
	
	return 0;
}

