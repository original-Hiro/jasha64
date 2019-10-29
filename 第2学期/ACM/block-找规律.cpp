#include <iostream>
#include <algorithm>
using namespace std;

const int N = 100007;
int a[N], b[N];

int main()
{
	ios::sync_with_stdio(false);
	
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	
	int res = 0;
	for (int i = 1; i <= n; i++)
		if (a[i] >= a[i-1]) res += a[i] - a[i-1];
	cout << res << endl;
	
	return 0;
}

