#include <iostream>
using namespace std;

int f[10];
void Solve(int n, int d)
{
	for (int k = 0, pow10 = 1, s = 0; n > 0; pow10 *= 10, k++, n /= 10)
	{
		int c = n % 10;
		for (int i = 0; i < 10; i++) f[i] += pow10 / 10 * k * c * d;
		for (int i = 0; i < c; i++) f[i] += pow10 * d;
		f[c] += (s+1) * d;
		f[0] -= pow10 * d;
		s += c * pow10;
	}
}

int main()
{
	int l, r;
	cin >> l >> r;
	Solve(r, 1); Solve(l-1, -1);
	for (int i = 0; i < 10; i++) cout << f[i] << endl;
	return 0;
}

