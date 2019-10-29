#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int n;
class largeint
{
	public:
	largeint() {*this = "0";}
	largeint(const int& num) {*this = num;}
	largeint(const string& s) {*this = s;}
	
	largeint operator = (int num)
	{
		fill(s, s + S, 0);
		size = 0;
		do {
			s[size++] = num % 10;
			num /= 10;
		} while (num > 0);
		return *this;
	}
	largeint operator = (const string& str)
	{
		int i, len = str.size();
		size = min(len, n);
		fill(s, s + S, 0);
		for (i = 0; i < size; ++i) s[i] = str[len - i - 1] - '0';
		for (i = size - 1; i > 0; --i)
			if (s[i]) break;
		size = i + 1;
		return *this;
	}
	friend largeint operator * (const largeint& a, const largeint& b)
	{
		int i, j, k;
		largeint Res;
		
		for (i = a.size - 1; i >= 0; --i)
			for (j = b.size - 1; j >= 0; --j)
				if (i + j < n && (Res[i + j] += a[i] * b[j]) >= 10)
					{
						if (i + j < n - 1)
						{
							for (k = i + j; k < n - 1; ++k)
							{
								if (Res[k] < 10) break;
								Res[k + 1] += Res[k] / 10;
								Res[k] %= 10;
							}
							Res[n - 1] %= 10;
						}
						Res[i + j] %= 10;
					}
		for (i = min(n, a.size + b.size) - 1; i > 0; --i)
			if (Res[i]) break;
		Res.size = i + 1;
		
		return Res;
	}
	largeint operator *= (const largeint& that) {*this = *this * that; return *this;}
	friend istream& operator >> (istream& cin, largeint& a)
	{
		string s;
		cin >> s;
		a = s;
		return cin;
	}
	friend ostream& operator << (ostream& cout, const largeint& a)
	{
		for (int i = a.size - 1; i >= 0; --i) cout << a[i];
		return cout;
	}
	short& operator [] (int x) {return s[x];}
	const short& operator [] (int x) const {return s[x];}
	
	private:
	static const long long S = 207;
	short s[S];
	int size;
} c1, c2;
int Time[107];

int main()
{
	int i;
	string s;
	
	cin >> s >> n; c1 = c2 = s;
	
	c2 = c1;
	for (i = 1; i <= 10; ++i)
	{
		c2 *= c1;
		if (c2[0] == c1[0]) break;
	}
	if (i == 11) {cout << -1 << endl; return 0;}
	Time[0] = i; c2 = c1;
	for (i = 2; i <= Time[0]; ++i) c1 *= c2;
	for (i = 1; i < n; ++i)
	{
		c2 = c1;
		for (Time[i] = 1; Time[i] <= 10; ++Time[i])
		{
			c2 *= c1;
			if (c2[i] == c1[i]) break;
		}
		if (Time[i] == 11) {cout << -1 << endl; return 0;}
		c2 = c1;
		for (int j = 2; j <= Time[i]; ++j) c1 *= c2;
	}
	
	c1 = 1;
	for (i = 0; i < n; ++i) c1 *= Time[i];
	cout << c1 << endl;
	
	return 0;
}

