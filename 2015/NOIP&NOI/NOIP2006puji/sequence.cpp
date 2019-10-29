#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int Pow[17], f[1027];

int main()
{
	int i, j, t, k, n;
	
	cin >> Pow[1] >> n;
	
	Pow[0] = 1;
	for (i = 2; i < 10; ++i) Pow[i] = Pow[i - 1] * Pow[1];
	
	f[i = 1] = Pow[k = 0];
	while (i < n)
	{
		t = i; ++k;
		for (j = 0; j <= t; ++j) f[++i] = f[j] + Pow[k];
	}
	
	cout << f[n] << endl;
	
	return 0;
} 

