#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <algorithm>
using namespace std;

class largeint
{
	public:
	largeint(string s = "0") {*this = s;}
	largeint operator = (string str)
	{
		while (str.size() % W) {str = "0" + str;}
		siz = 0;
		int len = str.size();
		istringstream ss;
		for (int i = 0; i*W < len; i++)
		{
			ss.clear();
			ss.str(str.substr(i*W, W));
			ss >> s[siz++];
		}
		reverse(s, s+siz);
		return *this;
	}
	friend largeint operator + (const largeint& a, const largeint& b)
	{
		largeint res;
		res.siz = max(a.siz, b.siz);
		for (int i = 0, c = 0; i < res.siz; i++)
		{
			res[i] = c;
			if (i < a.siz) res[i] += a[i];
			if (i < b.siz) res[i] += b[i];
			c = res[i]/B; res[i] %= B;
			if (i+1 == res.siz && c) res.siz++;
		}
		return res;
	}
	friend largeint operator - (const largeint& a, const largeint& b)
	{
		//±ØÐëÈ·±£a>=b 
		largeint res;
		res[0] = 0;
		for (int i = 0; i < a.siz; i++)
		{
			res[i] += a[i];
			if (i < b.siz) res[i] -= b[i];
			if (res[i] < 0) {res[i] += B; res[i+1] = -1;}
			else res[i+1] = 0;
		}
		res.siz = a.siz;
		while (res.siz > 1 && res[res.siz-1] == 0) res.siz--;
		return res;
	}
	friend largeint operator * (const largeint& a, const largeint& b)
	{
		largeint res;
		fill(res.s, res.s+S, 0);
		for (int i = 0; i < a.siz; i++)
			for (int j = 0, c = 0; j < b.siz; j++)
			{
				res[i+j] += c + a[i] * b[j];
				c = res[i+j]/B; res[i+j] %= B;
				if (j == b.siz-1 && c) res[i+j+1] += c;
			}
		res.siz = a.siz + b.siz;
		while (res.siz > 1 && res[res.siz-1] == 0) res.siz--;
		return res;
	}
	friend largeint operator / (const largeint& a, int b)
	{
		largeint res;
		for (long long i = a.siz-1, c = 0; i >= 0; i--)
		{
			c = c * B + a[i];
			res[i] = c / b; c %= b;
		}
		res.siz = a.siz;
		while (res.siz > 1 && res[res.siz-1] == 0) res.siz--;
		return res;
	}
	friend int operator % (const largeint& a, int b)
	{
		int res = 0;
		for (int i = a.siz-1; i >= 0; i--) res = ((long long)res * B + a[i]) % b;
		return res;
	}
	friend bool operator < (const largeint& a, const largeint& b)
	{
		if (a.siz != b.siz) return a.siz < b.siz;
		for (int i = a.siz-1; i >= 0; i--)
			if (a[i] != b[i]) return a[i] < b[i];
		return false;
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
		cout << a[a.siz-1];
		for (int i = a.siz-2; i >= 0; i--) cout << setw(W) << setfill('0') << a[i];
		return cout;
	}
	
	private:
	static const int S = 3007, B = 10000, W = 4;
	int s[S], siz;
	int& operator [] (int x) {return s[x];}
	const int& operator [] (int x) const {return s[x];}
};

int main()
{
	
	return 0;
}

