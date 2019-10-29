#include <iostream>
#include <algorithm>
using namespace std;

int p[1312], Top;
bool isp[10007];

int main()
{
	int n, i, j, t;
	bool First = true;
	
	cin >> n;
	
	fill(isp + 2, isp + 10001, true);
	for (i = 2; i <= 10000; ++i)
		if (isp[i])
			for (j = i << 1; j <= 10000; j += i) isp[j] = false;
	for (i = 2; i <= 10000; ++i)
		if (isp[i]) p[Top++] = i;
	
	cout << n << "=";
	for (i = 0; i < Top; ++i)
		if (n % p[i] == 0)
		{
			if (!First) cout << '*';
			t = 0;
			while (n % p[i] == 0) {n /= p[i]; ++t;}
			cout << p[i];
			if (t > 1) cout << '^' << t;
			First = false;
		}
	cout << endl;
	
	return 0;
}

