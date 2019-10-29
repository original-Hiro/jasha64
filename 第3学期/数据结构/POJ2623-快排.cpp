#include <iostream>
#include <iomanip>
#include <algorithm>
using namespace std;

int a[250001];
void Quick_Sort(int beg, int end)
{
	int l = beg, r = end, w = a[(beg+end)/2];
	while (l <= r)
	{
		while (a[l] < w) l++;
		while (a[r] > w) r--;
		if (l <= r) swap(a[l++], a[r--]);
	}
	if (r > beg) Quick_Sort(beg, r);
	if (l < end) Quick_Sort(l, end);
}

int main()
{
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	
	Quick_Sort(1, n);
	if (n % 2 != 0) cout << setiosflags(ios::fixed) << setprecision(1) << (double)a[(n+1)/2] << endl;
	else cout << setiosflags(ios::fixed) << setprecision(1) << a[n/2] / 2.0 + a[n/2+1] / 2.0 << endl;
	return 0;
}

