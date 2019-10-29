#include <iostream>
using namespace std;

inline int Num2(int x)
{
	int r = 0;
	while (x > 0)
	{
		if (x % 10 == 2) ++r;
		x /= 10;
	}
	return r;
}

int main()
{
	int l, r, i, Res = 0;
	
	cin >> l >> r;
	
	for (i = l; i <= r; ++i) Res += Num2(i);
	
	cout << Res << endl;
	
	return 0;
}

