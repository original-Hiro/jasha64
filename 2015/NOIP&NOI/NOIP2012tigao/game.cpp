#include <fstream>
#include <algorithm>
using namespace std;

ifstream cin("game.in");
ofstream cout("game.out");
const int N = 1007;
class largeint
{
	public:
	largeint() {*this = 0;}
	largeint(long long num) {*this = num;}
	
	largeint operator = (long long num)
	{
		fill(s, s + S, 0);
		size = 0;
		do {
			s[size++] = num % B;
			num /= B;
		} while (num > 0);
		return *this;
	}
	friend largeint operator * (largeint a, largeint b)
	{
		largeint res;
		int i, j;
		for (i = 0; i < a.size; i++)
			for (j = 0; j < b.size; j++)
			{
				res[i + j] += a[i] * b[j];
				if (res[i + j] >= B)
				{
					res[i + j + 1] += res[i + j] / B;
					res[i + j] %= B;
				}
			}
		for (i = a.size + b.size;; i--)
			if (res[i])
			{
				res.size = i + 1;
				return res;
			}
		res.size = 1;
		return res;
	}
	friend largeint operator / (largeint a, int b)
	{
		largeint res;
		int i;
		long long cache = 0;
		for (i = a.size - 1; i >= 0; i--)
		{
			cache = cache * 10 + a[i];
			res[i] = cache / b;
			cache %= b;
		}
		for (i = a.size - 1; i >= 0; i--)
			if (res[i]) break;
		res.size = i + 1;
		return res;
	}
	friend bool operator < (const largeint& a, const largeint& b)
	{
		if (a.size != b.size) return a.size < b.size;
		for (int i = a.size - 1; i >= 0; i--)
			if (a[i] != b[i]) return a[i] < b[i];
		return false;
	}
	friend ostream& operator << (ostream& cout, largeint a)
	{
		for (int i = a.size - 1; i >= 0; i--) cout << a[i];
		return cout;
	}
	
	private:
	static const int S = 4007, B = 10;
	short s[S];
	int size;
	
	short& operator [] (int a) {return s[a];}
	const short& operator [] (int a) const {return s[a];}
} f[N], c[N];
struct people
{
	int a, b, c;
	
	friend bool operator < (const people& a, const people& b) {return a.c < b.c;}
	friend istream& operator >> (istream& cin, people& a)
	{
		cin >> a.a >> a.b;
		a.c = a.a * a.b;
		return cin;
	}
} p[N];

int main()
{
	int n;
	int i, j, k, cache;
	
	cin >> n;
	for (i = 0; i <= n; i++) cin >> p[i];
	
	sort(p + 1, p + n + 1);
	c[0] = p[0].a;
	for (i = 1; i <= n; i++)
	{
		f[i] = c[i - 1] / p[i].b;
		c[i] = c[i - 1] * p[i].a;
	}
	
	cout << *max_element(f + 1, f + n + 1) << endl;
	
	return 0;
}

