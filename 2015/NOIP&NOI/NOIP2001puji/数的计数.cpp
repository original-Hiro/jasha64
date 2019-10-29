#include <iostream>
using namespace std;

int f[1007];

int main()
{
	int n;
	
	cin >> n;
	
	f[0] = 1;
	for (int i = 1; i <= n; i++)
	{
		f[i] = f[i - 1];
		if (i % 2 == 0) f[i] += f[i / 2];
	}
	
	cout << f[n] << endl;
	
	return 0;
}

