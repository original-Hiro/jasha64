#include <iostream>
#include <cmath> 
#include <algorithm>
using namespace std;

int cnt;
int a[100000007];

void find(int x)
{
	for (int i = 1; i <= sqrt(x); ++i)
	    if (x % i == 0)
		{
			a[++cnt] = i;
			if (i != x / i) a[++cnt] = x / i;
		}
}

int main()
{
	int n, k, i, x, tmp = 1;
	
	cin >> n >> k;
	for (int i = 1; i <= n; ++i)
	{
	    cin >> x;
	    find(x);
	}
	
	sort(a + 1, a + cnt + 1);
	for (i = cnt; i > 0; --i)
	{
		if (a[i] == a[i+1]) ++tmp;
		else {
		    if (tmp >= k) {cout << a[i + 1] << endl; return 0;}
			tmp = 1;
		}
	}
	cout << 1 << endl;
	
	return 0;
}

