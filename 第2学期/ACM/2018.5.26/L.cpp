#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	
	int T;
	cin >> T;
	while (T--)
	{
		int x;
		cin >> x;
		cout << (x+1)/2 << ' ' << x/2 << endl;
	}
}

