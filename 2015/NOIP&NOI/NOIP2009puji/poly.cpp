#include <fstream>
using namespace std;

ifstream cin("poly.in");
ofstream cout("poly.out");

int main()
{
	int n, c;
	
	cin >> n;
	cin >> c;
	if (c)
	{
		if (c < 0) {cout << '-'; c = -c;}
		if (c != 1) cout << c;
		cout << 'x';
		if (n > 1) cout << '^' << n;
	}
	n--;
	while (n)
	{
		cin >> c;
		if (c)
		{
			if (c < 0) {cout << '-'; c = -c;}
			else cout << '+';
			if (c != 1) cout << c;
			cout << 'x';
			if (n > 1) cout << '^' << n;
		}
		n--;
	}
	cin >> c;
	if (c)
	{
		if (c < 0) {cout << '-'; c = -c;}
		else cout << '+';
		cout << c;
	}
	
	return 0;
}

