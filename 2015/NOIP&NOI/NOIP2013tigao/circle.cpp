#include <fstream>
using namespace std;

ifstream cin("circle.in");
ofstream cout("circle.out");
int n;

inline long long Pow(const int& a, const int& b)
{
	if (b == 1) return a;
	long long c = Pow(a, b / 2) % n;
	if (b % 2) return c * c * a % n;
	else return c * c % n;
}

int main()
{
	int m, k, x;
	
	cin >> n >> m >> k >> x;
	
	cout << (x + m % n * Pow(10, k) % n) % n << endl;
	
	return 0;
}

