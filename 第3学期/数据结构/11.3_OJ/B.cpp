#include <iostream>
#include <algorithm>
using namespace std;

int a[100001];

int main()
{
	ios::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> a[i];
	
	sort(a, a+n);
	int cnt = 0;
	for (int i = 0, l = 1; i < n; i++)
		if (a[i] >= l) {cnt++; l = a[i] + m;}
	cout << cnt << endl;
	
	return 0;
}

