#include <iostream>
#include <cmath>
using namespace std;

const double eps = 1e-6, pi = acos(-1);
inline double Abs(double x) {return x < 0 ? -x : x;}

int main()
{
	int T, i, Area;
	double a, b, S;
	
	cin >> T;
	while (T--)
	{
		cin >> a >> b;
		S = (a * a + b * b) * pi / 2;
		
		Area = 50;
		for (i = 1; Area - S <= eps; ++i) Area += 50;
		
		cout << i << endl;
	}
	
	return 0;
}

