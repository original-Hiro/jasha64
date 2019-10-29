#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int a[30007];

int main()
{
	int w, n, i, c1 = 0, c2, Res = 0;
	
	cin >> w >> n;
	for (i = 0; i < n; i++) scanf("%d", &a[i]);
	
	sort(a, a + n);
	c2 = n - 1;
	while (c1 <= c2)
	{
		if (a[c1] + a[c2] <= w) c1++;
		c2--;
		Res++;
	}
	
	cout << Res << endl;
	
	return 0;
}

