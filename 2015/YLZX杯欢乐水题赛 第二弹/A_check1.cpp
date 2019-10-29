#include <iostream>
#include <cstdio>
#include <cctype>
using namespace std;

const int INF = -2147483648;
int a[10000007];

int main()
{
	int n, i, p1 = 0, p2 = 0, p3 = 0;
	
	cin >> n;
	for (i = 1; i <= n; ++i) scanf("%d", &a[i]);
	for (i = n - 1; i > 0; --i) a[i] -= a[i + 1];
	
	a[0] = INF;
	for (i = 1; i <= n; ++i)
		if (a[i] > a[p1]) {p3 = p2; p2 = p1; p1 = i;}
		else if (a[i] > a[p2]) {p3 = p2; p2 = i;}
		else if (a[i] > a[p3]) p3 = i;
	
	cout << a[p1] << ' ' << a[p2] << ' ' << a[p3] << endl;
	
	return 0;
}

