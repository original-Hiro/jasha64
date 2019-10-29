#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	
	int T;
	cin >> T;
	while (T--)
	{
		int a, b;
		cin >> a >> b;
		if (a >= b) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	
	return 0;
}

