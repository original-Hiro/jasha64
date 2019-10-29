#include <iostream>
using namespace std;

int main()
{
	int T, n, ans;
	
	cin >> T;
	while (T--)
	{
		cin >> n;
		
		if (n % 3 == 1) n--;
		ans = n / 3 * 2;
		if (n % 3 == 2) ans++;
		
		cout << ans << endl;
	}
	
	return 0;
}

