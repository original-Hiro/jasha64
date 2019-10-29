#include <iostream>
using namespace std;

int main()
{
    int T;
    cin >> T;
    while (T--) {
	int x1, y1, x2, y2;
	cin >> x1 >> y1 >> x2 >> y2;
	int x3, y3, x4, y4;
	cin >> x3 >> y3 >> x4 >> y4;

	bool a = x1 >= x3 && y1 >= y3;
	bool b = x2 <= x4 && y2 <= y4;
	if (a && b) {cout << "A in B" << endl; continue;}
	a = x1 <= x3 && y1 <= y3;
	b = x2 >= x4 && y2 >= y4;
	if (a && b) {cout << "B in A" << endl; continue;}
	a = x1 > x4 || y1 > y4;
	b = x2 < x3 || y2 < y3;
	if (a || b) {cout << "Separate" << endl; continue;}
	cout << "Intersect" << endl;
    }
    return 0;
}

