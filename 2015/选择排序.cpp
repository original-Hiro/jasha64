#include <iostream>
using namespace std;

int a[5007];

int main()
{
	int n;
	int c, i, Pos, Top;
	
	cin >> n;
	for (i = 1; i <= n; i++) cin >> a[i];
	
	for (Top = 1; Top <= n; Top++)
	{
		Pos = Top;
		for (i = Top + 1; i <= n; i++)
			if (a[i] > a[Pos]) Pos = i;
		c = a[Pos]; a[Pos] = a[Top]; a[Top] = c;
	}
	
	cout << a[1];
	for (i = 2; i <= n; i++) cout << ' ' << a[i];
	cout << endl;
	
	return 0;
}

