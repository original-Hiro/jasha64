#include <iostream>
#include <iomanip>
#include <algorithm>
using namespace std;

struct largeint
{
	static const long long N = 2007, W = 16,
	B = 10000000000000000;
	long long s[N], size;
	
	largeint operator = (long long num)
	{
		fill(s, s + N, 0);
		size = 0;
		do {
			s[size++] = num % B;
			num /= B;
		} while (num > 0);
		return *this;
	}
	friend largeint operator + (largeint a,
	const largeint& b)
	{
		if (a.size < b.size) return b + a;
		int i;
		for (i = 0; i < a.size; i++)
		{
			a.s[i] += b.s[i];
			if (a.s[i] >= B)
			{
				a.s[i + 1] += a.s[i] / B;
				a.s[i] %= B;
				if (i == a.size - 1) a.size++;
			}
		}
		return a;
	}
	friend ostream& operator << (ostream& cout,
	const largeint& a)
	{
		cout << a.s[a.size - 1];
		for (int i = a.size - 2; i >= 0; i--)
			cout << setw(W) << setfill('0') << a.s[i];
		return cout;
	}
} x, y, z;

int main()
{
	int n;
	int i;
	
	while (cin >> n)
	{
		if (n == 1 || n == 2) cout << 1 << endl;
		else {
			x = y = 1ll;
			z = 2ll;
			for (i = 4; i <= n; i++)
			{
				x = y; y = z; z = x + y;
			}
			cout << z << endl;
		}
	}
	
	return 0;
}

