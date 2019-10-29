#include <iostream>
#include <cmath>
using namespace std;

int f(int x)
{
	int l = sqrt(x), i, r = 0;
	
	for (i = 1; i <= l; ++i)
		if (x % i == 0)
			if (i * i == x || i == 1) r += i;
			else r += i + x / i;
	
	return r;
}

int main()
{
	int a, b;
	
	cin >> a >> b;
	
	if (f(a) == b && f(b) == a) cout << "yes" << endl;
	else cout << "no" << endl;
	
	return 0;
}

