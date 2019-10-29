#include <iostream>
#include <iomanip>
using namespace std;

class largeint
{
	public:
	largeint() {*this = 0;}
	largeint(long long num) {*this = num;}
	
	largeint operator = (long long num)
	{
		size = 0;
		do {
			s[size++] = num % B;
			num /= B;
		} while (num > 0);
		return *this;
	}
	friend largeint operator + (largeint a, const largeint& b)
	{
		if (a.size < b.size) return b + a;
		for (int i = 0; i < b.size; i++)
		{
			a[i] += b[i];
			if (a[i] >= B)
			{
				a[i] -= B; a[i + 1]++;
				if (i == a.size - 1) a.size++;
			}
		}
		return a;
	}
	friend ostream& operator << (ostream& cout, const largeint& a)
	{
		cout << a[a.size - 1];
		for (int i = a.size - 2; i >= 0; i--) cout << setw(W) << setfill('0') << a[i];
		return cout;
	}
	
	private:
	static const long long S = 107, B = 1000000000000000000, W = 18;
	long long s[S], size;
	
	long long& operator [] (const int& x) {return s[x];}
	const long long& operator [] (const int& x) const {return s[x];}
}
f[3007] = {0, 1, 2, 4};

int main()
{
	int i;
	
	for (i = 4; i <= 3000; i++) f[i] = f[i - 1] + f[i - 2] + f[i - 3];
	
	while (cin >> i) cout << f[i] << endl;
	
	return 0;
}

