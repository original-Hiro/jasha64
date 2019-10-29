#include <iostream>
using namespace std;

int f[1007] = {0, 2};

int main()
{
	int n;
	
	for (int i = 2; i <= 1000; i++) f[i] = f[i - 1] + ((i - 1) << 1);
	
	while (cin >> n) cout << f[n] << endl;
	
	return 0;
}

