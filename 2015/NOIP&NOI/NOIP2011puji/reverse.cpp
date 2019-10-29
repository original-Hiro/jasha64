#include <fstream>
using namespace std;

ifstream cin("reverse.in");
ofstream cout("reverse.out");

int main()
{
	int c;
	
	cin >> c;
	if (c == 0)
	{
		cout << '0' << endl;
		return 0;
	}
	if (c < 0)
	{
		cout << '-';
		c = -c;
	}
	while (c % 10 == 0) c /= 10;
	do {
		cout << c % 10;
		c /= 10;
	} while (c > 0);
	cout << endl;
	
	return 0;
}

