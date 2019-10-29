#include <iostream>
#include <algorithm>
using namespace std;

int a[17], f[1007];

int main()
{
	int i, j, l;
	
	while (cin >> a[1])
	{
		for (i = 2; i <= 10; ++i) cin >> a[i];
		cin >> l;
		
		fill(f + 1, f + l + 1, 100007);
		for (i = 1; i <= l; ++i)
			for (j = 1; j <= min(i, 10); ++j) f[i] = min(f[i], f[i - j] + a[j]);
		
		cout << f[l] << endl;
	}
	
	return 0;
}

