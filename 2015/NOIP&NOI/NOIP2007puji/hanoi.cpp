#include <iostream>
#include <iomanip>
#include <algorithm>
using namespace std;

struct largeint
{
	static const long long S = 27, B = 1000000000000000000, W = 18;
	long long s[S], size;
	
	largeint() {*this = 0;}
	largeint(long long num) {*this = num;}
	largeint operator = (long long num)
	{
		size = 0;
		fill(s, s + S, 0);
		do {
			s[size++] = num % B;
			num /= B;
		} while (num > 0);
		return *this;
	}
	friend largeint operator + (largeint a, largeint b)
	{
		if (a.size < b.size) return b + a;
		for (int i = 0; i < a.size; i++)
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
	friend ostream& operator << (ostream& cout, largeint a)
	{
		cout << a.s[a.size - 1];
		for (int i = a.size - 2; i >= 0; i--) cout << setw(W) << setfill('0') << a.s[i];
		return cout;
	}
} f[207];

int main()
{
	int n;
	int i;
	
	cin >> n;
	
	f[0] = 0;
	for (i = 1; i <= n; i++) f[i] = f[i - 1] + f[i - 1] + 2;
	
	cout << f[n] << endl;
	
	return 0;
}

