#include <iostream>
using namespace std;

int main()
{
	int x1, y1, x2, y2, x, y;
	
	cin >> x1 >> y1 >> x2 >> y2 >> x >> y;
	
	if (!((x1 - x2) % x == 0 && (y1 - y2) % y == 0)) {cout << "NO" << endl; return 0;}
	int a = (x1 - x2) / x, b = (y1 - y2) / y;
	if ((a - b) & 1) cout << "NO" << endl;
	else cout << "YES" << endl;
	
	return 0;
}

