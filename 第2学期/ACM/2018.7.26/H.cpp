#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	int x1, y1, r1;
	cin >> x1 >> y1 >> r1;
	int x2, y2, r2;
	cin >> x2 >> y2 >> r2;

	double dx = x2 - x1, dy = y2 - y1;
	double len = hypot(dx, dy);
	dx /= len; dy /= len;

	if (r1 >= len) cout << x2 << ' ' << y2 << endl;
	else if (r2 >= len) cout << x1 << ' ' << y1 << endl;
	else {
		double dr = (r1 + (len-r2)) / 2;
		double rx = x1 + dx * dr;
		double ry = y1 + dy * dr;
		cout << rx << ' ' << ry << endl;
	}

	return 0;
}

