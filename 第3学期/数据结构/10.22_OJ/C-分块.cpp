//区间信息查询的O(n*n)都可以考虑通过分块降低到O(n*sqrt(n)) 
#include <iostream>
#include <algorithm>
using namespace std;

const int N = 100001, B = 3000;
int a[N], b[4001];

inline int Query(int p, int k) //查询[p, p+k)的最大值 
{
	int ret = 0;
	for (int i = (p-1)/B+1; i < (p+k)/B; i++) ret = max(ret, b[i]);
	for (int i = p; i < ((p-1)/B+1)*B && i < p+k; i++) ret = max(ret, a[i]);
	for (int i = (p+k)/B*B+1; p <= i && i < p+k; i++) ret = max(ret, a[i]);
	return ret;
}

int main()
{
	ios::sync_with_stdio(false);
	int n, k;
	cin >> n >> k;
	for (int i = 0; i < n; i++) {cin >> a[i]; b[i / B] = max(b[i / B], a[i]);}
	
	long long res = 0;
	for (int i = 0; i + k <= n; i++) res += Query(i, k);
	cout << res << endl;
	return 0;
}

