#include <iostream>
using namespace std;

long long f[37] = {0, 0, 1};

int main()
{
	int n;
	int i;
	
	cin >> n;
	
	for (i = 3; i <= n; i++) f[i] = f[i - 1] + f[i - 2];
	
	cout << f[n] << endl;
	
	return 0;
}

