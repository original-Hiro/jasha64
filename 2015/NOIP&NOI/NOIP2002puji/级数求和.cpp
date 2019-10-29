#include <iostream>
using namespace std;

int main()
{
	int k, n;
	double c = 0;
	
	cin >> k;
	
	n = 0;
	while (c <= k)
	{
		n++;
		c += 1 / (double)n;
	}
	
	cout << n << endl;
	
	return 0;
}

