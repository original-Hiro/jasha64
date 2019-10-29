#include <iostream>
using namespace std;

int main()
{
	int n;
	char c;
	
	cin >> n;
	int res = 0;
	while (n--)
	{
		cin >> c;
		if (c == 'G') res++;
	}
	
	cout << res << endl;
	return 0;
}

