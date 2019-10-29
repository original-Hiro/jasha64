#include <iostream>
using namespace std;

int gcd(int a, int b)
{
	if (b == 0) return a;
	return gcd(b, a%b);
}

int main()
{
	ios::sync_with_stdio(false);
	int n, x;
	cin >> n >> x;
	
	int a, b;
	cin >> a;
	for (int i = 1; i < n; i++)
	{
		cin >> b;
		a = gcd(a, b);
	}
	if (x % a == 0) cout << "YES" << endl;
	else cout << "NO" << endl;
	
	return 0;
}

