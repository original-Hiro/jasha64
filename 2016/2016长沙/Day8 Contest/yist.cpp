#include <fstream>
#include <cmath>
#include <iomanip>
#include <ctime>
#include <cstdlib>
using namespace std;

ifstream cin("yist.in");
ofstream cout("yist.out");
const int N = 3000;
const double delta = 0.97, eps = 1e-6, pi = acos(-1);
int a[7], n;
double Res;
struct Point
{
	int n;
	double theta;
	Point(int a = 0, double b = 0) {n = a; theta = b;}
} f[2][N + 7];

inline double S(Point b, Point c)
{
	double bx = a[b.n] * cos(b.theta), by = a[b.n] * sin(b.theta);
	double cx = a[c.n] * cos(c.theta), cy = a[c.n] * sin(c.theta);
	double x1 = bx - cx, x2 = bx - a[0], y1 = by - cy, y2 = by;
	return 0.5 * fabs(x1 * y2 - x2 * y1);
}

int main()
{
	srand(time(NULL));
	
	bool Spc = true;
	
	cin >> n >> a[0];
	for (int i = 1; i < n; i++)
	{
		cin >> a[i];
		if (a[i] != a[i - 1]) Spc = false;
	}
	
	if (Spc)
	{
		const double theta = 2 * pi / n;
		Res = n * 0.5 * a[0] * a[0] * sin(theta);
	}
	else if (n <= 3)
	{
		for (int i = 1; i <= N; i++) f[0][i] = Point(1, pi * rand() / RAND_MAX);
		for (int i = 1; i <= N; i++)
		{
			f[1][i] = Point(2, pi * rand() / RAND_MAX);
			double temp = pi;
			while (temp > eps)
			{
				const double dt = temp * rand() / RAND_MAX * temp;
				if (S(f[0][i], Point(2, f[1][i].theta + dt)) > S(f[0][i], f[1][i]))
					f[1][i] = Point(2, f[1][i].theta + dt);
				temp *= delta;
			}
			Res = max(Res, S(f[0][i], f[1][i]));
		}
	}
	
	cout << setiosflags(ios::fixed) << setprecision(6) << Res + eps << endl;
	
	return 0;
}

