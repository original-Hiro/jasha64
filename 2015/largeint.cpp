#include <iostream>
#include <algorithm>
#include <string>
#include <sstream>
using namespace std;

class largeint
{		
	public:
	largeint () {*this = 0;}
	largeint (const long long& num) {*this = num;}
	largeint (const string& s) {*this = s;}
	static largeint Half(largeint a)
	{
		a[0] >>= 1;
		for (int i = 1; i < a.size; ++i)
		{
			if (a[i] & 1)
				if ((a[i - 1] += B >> 1) >= B) {a[i - 1] -= B; ++a[i];}
			a[i] >>= 1;
		}
		return a;
	}
	static largeint MAX() {largeint c; c.size = S - 7; c[c.size - 1] = 1; return c;}
	largeint operator = (long long a)
	{
		if (a < 0) {isNeg = 1; a = -a;}
		else isNeg = 0;
		fill(s, s + S, 0);
		size = 0;
		do {
			s[size++] = a % B;
			a /= B;
		} while (a > 0);
		return *this;
	}
	largeint operator = (const string& num)
	{
		isNeg = 0;
		fill(s, s + S, 0);
		if (num[0] == '-') {*this = -largeint(num.substr(1)); return *this;}
		size = num.size() / W;
		istringstream ss;
		for (int i = 1; i <= size; i++)
		{
			ss.str(num.substr(num.size() - i * W, W));
			ss >> s[i - 1];
			ss.clear();
		}
		if (num.size() % W)
		{
			ss.str(num.substr(0, num.size() % W));
			ss >> s[size++];
			ss.clear();
		}
		return *this;
	}
	friend largeint operator - (largeint a) {a.isNeg = !a.isNeg; return a;}
	friend largeint operator + (largeint a, const largeint& b)
	{
		if (a.isNeg  && !b.isNeg) return b - (-a);
		if (!a.isNeg &&  b.isNeg) return a - (-b);
		if (a.isNeg  &&  b.isNeg) return -(-a + (-b));
		if (a.size < b.size) return b + a;
		int i;
		for (i = 0; i < b.size; i++)
		{
			a.s[i] += b.s[i];
			if (a.s[i] >= B)
			{
				a.s[i + 1] += a.s[i] / B;
				a.s[i] %= B;
			}
		}
		for (i = a.size + 1;;i--) if (a.s[i] != 0) break;
		a.size = i + 1;
		return a;
	}
	largeint operator += (const largeint& that) {*this = *this + that; return *this;}
	friend largeint operator ++ (largeint& a)
	{
		if (a.isNeg) {a = -a; --a; if (a == 0) return a; a = -a; return a;}
		else ++a.s[0];
		if (a.s[0] >= B) {a.s[1] += a.s[0] / B; a.s[0] %= B; if (a.size == 1) a.size++;}
		return a;
	}
	friend largeint operator ++ (largeint& a, int b)
	{
		largeint c(a);
		if (a.isNeg) {a = -a; a--; if (a == 0) return c; a = -a; return c;}
		else a.s[0]++;
		if (a.s[0] >= B) {a.s[1] += a.s[0] / B; a.s[0] %= B; if (a.size == 1) a.size++;}
		return c;
	}
	friend largeint operator - (largeint a, const largeint& b)
	{
		if (a.isNeg  && !b.isNeg) return -(-a + b);
		if (!a.isNeg &&  b.isNeg) return a + (-b);
		if (a.isNeg  &&  b.isNeg) return (-b) - (-a);
		if (a < b) return -(b - a);
		int i;
		bool done;
		for (i = 0; i < b.size; i++) a.s[i] -= b.s[i];
		do {
			done = 1;
			for (i = 0; i < a.size - 1; i++)
				while (a.s[i] < 0)
				{
					a.s[i] += B;
					a.s[i + 1]--;
					done = 0;
				}
		} while (!done);
		for (i = a.size - 1; i > 0; i--) if (a.s[i] != 0) break;
		a.size = i + 1;
		return a;
	}
	largeint operator -= (const largeint& that) {*this = *this - that; return *this;}
	friend largeint operator -- (largeint& a)
	{
		if (a.isNeg) {a = -a; ++a; if (a == 0) return a; a = -a; return a;}
		else --a.s[0];
		if (a.s[0] < 0)
			if (a.size > 1) {--a.s[1]; a.s[0] += B;}
			else {a.s[0] = -a.s[0]; a.isNeg = !a.isNeg;}
		return a;
	}
	friend largeint operator -- (largeint& a, int b)
	{
		largeint c(a);
		if (a.isNeg) {a = -a; a++; if (a == 0) return c; a = -a; return c;}
		else a.s[0]--;
		if (a.s[0] < 0)
			if (a.size > 1) {a.s[1]--; a.s[0] += B;}
			else {a.s[0] = -a.s[0]; a.isNeg = !a.isNeg;}
		return c;
	}
	friend largeint operator * (const largeint& a, const largeint& b)
	{
		largeint res;
		if (a.isNeg ^ b.isNeg) res.isNeg = 1;
		else res.isNeg = 0;
		int i;
		for (i = 0; i < a.size; i++)
			for (int j = 0; j < b.size; j++)
			{
				res.s[i + j] += a.s[i] * b.s[j];
				if (res.s[i + j] >= B)
				{
					res.s[i + j + 1] += res.s[i + j] / B;
					res.s[i + j] %= B;
				}
			}
		for (i = a.size + b.size;; i--) if (res.s[i] != 0) break;
		res.size = i + 1;
		return res;
	}
	largeint operator *= (const largeint& that) {*this = *this * that; return *this;}
	friend largeint operator / (const largeint& a, const largeint& b)
	{
		if (a.isNeg  && !b.isNeg) return -((-a) / b);
		if (!a.isNeg &&  b.isNeg) return -(a / (-b));
		if (a.isNeg  &&  b.isNeg) return (-a) / (-b);
		largeint Low = 0, Mid, High = MAX(), c;
		while (Low <= High)
		{
			largeint Mid = Half(Low + High);
			if ((c = Mid * b) == a) return Mid;
			if (c < a) Low = Mid + 1;
			else High = Mid - 1;
		}
		return High;
	}
	largeint operator /= (const largeint& that) {*this = *this / that; return *this;}
	friend largeint operator % (const largeint& a, const largeint& b)
	{
		largeint res, c;
		if (a.isNeg) res.isNeg = 1;
		else res.isNeg = 0;
		c = a / b;
		res = a - c * b;
		return res;
	}
	largeint operator %= (const largeint& that) {*this = *this % that; return *this;}
	friend bool operator < (const largeint& a, const largeint& b)
	{
		if (a.isNeg  && !b.isNeg) return true;
		if (!a.isNeg &&  b.isNeg) return false;
		if (a.isNeg  &&  b.isNeg) return !(-a < -b || -a == -b);
		if (a.size != b.size) return a.size < b.size;
		for (int i = a.size - 1; i >= 0; i--)
			if (a.s[i] != b.s[i]) return a.s[i] < b.s[i];
		return false;
	}
	friend bool operator > (const largeint& a, const largeint& b) {return b < a;}
	friend bool operator <= (const largeint& a, const largeint& b) {return !(b < a);}
	friend bool operator >= (const largeint& a, const largeint& b) {return !(a < b);}
	friend bool operator != (const largeint& a, const largeint& b)
	{
		return a < b || b < a;
	}
	friend bool operator == (const largeint& a, const largeint& b)
	{
		return !(a < b) && !(b < a);
	} 
	friend istream& operator >> (istream& cin, largeint& a)
	{
		string s;
		cin >> s;
		a = s;
		return cin;
	}
	friend ostream& operator << (ostream& cout, const largeint& a)
	{
		if (a.isNeg) cout << '-';
		int i, j;
		cout << a.s[a.size - 1];
		for (i = a.size - 2; i >= 0; i--)
		{
			for (j = 10; a.s[i] * j < B && j < B; j *= 10) cout << 0;
			cout << a.s[i];
		}
		return cout;
	}
	private:
	static const int S = 207, B = 1000000000, W = 9;
	long long size, s[S];
	bool isNeg;
	long long& operator [] (const int& x) {return s[x];}
};

int main()
{
	largeint a, b;
	
	cin >> a >> b;
	
	cout << a / b << endl;
	
	return 0;
}

