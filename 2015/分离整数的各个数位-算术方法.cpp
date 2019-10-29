#include <iostream>
using namespace std;

int main()
{
	int n;
	
	cin >> n;
	
	cout << n % 10; n /= 10;
	while (n > 0)
	{
		cout << ' ' << n % 10;
		n /= 10;
	}
	
	return 0;
} 

