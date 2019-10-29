#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int a[4], kase = 0;
	
	ios::sync_with_stdio(false);
	while (cin >> a[0] >> a[1] >> a[2] >> a[3])
	{
		sort(a, a+4);
		cout << "Case " << ++kase << ": " << a[2]+a[3] << endl;
	}
	
	return 0;
}

