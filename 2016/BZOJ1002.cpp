#include <iostream>
#include <iomanip>
#include <algorithm>
using namespace std;

class largeint
{
	public:
	largeint(int num = 0) {*this = num;}
	largeint operator = (int num)
	{
		fill(s, s + S, 0);
		size = 0;
		do {
			s[size++] = num % B;
			num /= B;
		} while (num > 0);
	}
	friend largeint operator + (const largeint& a, const largeint& b)
	{
		if (b.size > a.size) return b + a;
		largeint c;
		c.size = a.size;
		for (int i = 0; i < a.size; i++) c[i] = a[i] + b[i];
		for (int i = 0; i < a.size; i++)
			if (c[i] >= B)
			{
				c[i] -= B;
				c[i + 1]++;
				if (i == a.size - 1) ++c.size;
			}
		return c;
	}
	friend largeint operator - (largeint a, const largeint& b)
	{
		for (int i = 0; i < b.size; i++) a[i] -= b[i];
		for (int i = 0; i < b.size; i++)
			if (a[i] < 0)
			{
				a[i] += B;
				--a[i + 1];
				if (a[i + 1] == 0 && i == a.size - 1) --a.size;
			}
		return a;
	}
	friend ostream& operator << (ostream& cout, const largeint& a)
	{
		cout << a.s[a.size - 1];
		for (int i = a.size - 2; i >= 0; i--) cout << setw(W) << setfill('0') << a.s[i];
		return cout;
	}
	private:
	static const int B = 10000, W = 4, S = 17;
	int s[S], size;
	int& operator [] (int x) {return s[x];}
	const int& operator [] (int x) const {return s[x];}
} f[107];

int main()
{
	int n;
	
	cin >> n;
	
	f[1] = 1; f[2] = 5;
	for (int i = 3; i <= n; i++)
		f[i] = f[i - 1] + f[i - 1] + f[i - 1] - f[i - 2] + 2;
	
	cout << f[n] << endl;
	
	return 0;
}

