#include <fstream>
#include <iomanip>
using namespace std;

ifstream cin("program1.in");
ofstream cout("program1.out");

class largeint
{
	public:
	largeint(long long num = 0) {*this = num;}
	largeint operator = (long long num)
	{
		fill(s, s + S, 0);
		size = 0;
		do {s[size++] = num % B; num /= B;} while (num > 0);
	}
	friend largeint operator * (const largeint& a, const largeint& b)
	{
		largeint c;
		int i, j, k;
		for (i = 0; i < a.size; i++)
			for (j = 0; j < b.size; j++)
			{
				c[i + j] += a[i] * b[j];
				if (c[i + j] >= B)
				{
					c[i + j + 1] += c[i + j] / B;
					c[i + j] %= B;
					for (k = i + j + 1; c[k] >= B; k++)
					{
						c[k + 1] += c[k] / B;
						c[k] %= B;
					}
				}
			}
		for (i = a.size + b.size; i > 0; i--)
			if (c[i]) break;
		c.size = i + 1;
		return c;
	}
	friend long long operator % (const largeint& a, long long b)
	{
		long long c = 0;
		for (int i = a.size - 1; i >= 0; i--) c = (c * B + a[i]) % b;
		return c;
	}
	friend istream& operator >> (istream& cin, largeint& a)
	{
		long long num;
		cin >> num;
		a = num;
		return cin;
	}
	
	private:
	static const int S = 27, B = 10000, W = 4;
	long long s[S], size;
	long long& operator [] (int x) {return s[x];}
	const long long& operator [] (int x) const {return s[x];}
};

int main()
{
	for (int t = 0; t < 10; t++)
	{
		largeint a, b;
		unsigned long long c;
		cin >> a >> b >> c;
		cout << a * b % c << endl;
	}
}

