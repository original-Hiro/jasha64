#include <iostream>
#include <algorithm>
#include <cstdio>
#include <string>
#include <cctype>
#include <stack>
using namespace std;

class largeint
{
	public:
	largeint() {*this = 0;}
	largeint(long long num) {*this = num;}
	
	operator bool () {return !(s[0] == 0 && size == 1);}
	largeint operator = (long long num)
	{
		fill(s, s + S, 0);
		size = 0;
		do {s[size++] = num % B; num /= B;} while (num > 0);
		return *this;
	}
	friend largeint operator + (largeint a, const largeint& b)
	{
		if (a.size < b.size) return b + a;
		int i;
		for (i = b.size - 1; i >= 0; --i)
			if ((a[i] += b[i]) >= B)
			{
				a[i] -= B; ++a[i + 1];
				if (i == a.size - 1) ++a.size;
			}
		return a;
	}
	largeint operator += (const largeint& that) {*this = *this + that; return *this;}
	friend largeint operator * (largeint a, const long long& b)
	{
		int i;
		for (i = a.size - 1; i >= 0; --i)
			if ((a[i] *= b) >= B)
			{
				a[i + 1] += a[i] / B; a[i] %= B;
				if (i == a.size - 1) ++a.size;
			}
		return a;
	}
	largeint operator *= (const long long& that) {*this = *this * that; return *this;}
	friend largeint operator / (const largeint& a, const long long& b)
	{
		largeint c;
		long long Cache = 0;
		int i;
		c.size = a.size;
		for (i = a.size - 1; i >= 0; --i)
		{
			Cache = Cache * B + a[i];
			c[i] = Cache / b;
			Cache %= b;
		}
		if (!c[c.size - 1] && c.size != 1) --c.size;
		return c;
	}
	largeint operator /= (const long long& that) {*this = *this / that; return *this;}
	friend long long operator % (largeint a, const long long& b)
	{
		long long c = 0;
		for (int i = a.size - 1; i >= 0; --i) c = (c * B + a[i]) % b;
		return c;
	}
	
	private:
	static const long long S = 17, B = 1000000000;
	long long s[S], size;
	
	long long& operator [] (int x) {return s[x];}
	const long long& operator [] (int x) const {return s[x];}
} c, Pow;
inline void Read(string& s)
{
	s = "";
	getchar();
	char c = getchar();
	while (c != ',') {s += c; c = getchar();}
}
inline long long Map(char c) {return isdigit(c) ? c - '0' : c - 55;}
inline char Map(long long a) {return a < 10 ? a + '0' : a + 55;}

stack<char> Printer;

int main()
{
	long long T, r1, r2, i;
	string s;
	
	cin >> T;
	while (T--)
	{
		cin >> r1; Read(s); cin >> r2;
		
		Pow = 1; c = Map(s[s.size() - 1]);
		for (i = s.size() - 2; i >= 0; --i)
		{
			Pow *= r1;
			c += Pow * Map(s[i]);
		}
		
		do {Printer.push(Map(c % r2)); c /= r2;} while (c);
		while (!Printer.empty()) {cout << Printer.top(); Printer.pop();}
		cout << endl;
	}
	
	return 0;
}

