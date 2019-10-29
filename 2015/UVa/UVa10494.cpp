#include <iostream>
#include <iomanip>
#include <algorithm>
#include <string>
#include <sstream>
using namespace std;

class largeint
{
	public:
	largeint() {size = S; *this = "0";}
	largeint(const string& s) {*this = s;}
	
	largeint operator = (const string& str)
	{
		int i, len = str.size();
		istringstream ss;
		
		fill(s, s + size, 0);
		size = len / W;
		for (i = 1; i <= size; i++)
		{
			ss.str(str.substr(len - i * W, W));
			ss >> s[i - 1];
			ss.clear();
		}
		if (len % B)
		{
			ss.str(str.substr(0, len % W));
			ss >> s[size++];
		}
		
		return *this;
	}
	friend largeint operator / (const largeint& a, const long long& b)
	{
		largeint res;
		int i;
		long long cache = 0;
		
		for (i = a.size - 1; i >= 0; i--)
		{
			cache = cache * B + a[i];
			res[i] = cache / b;
			cache %= b;
		}
		for (i = a.size - 1; i > 0; i--)
			if (res[i]) break;
		res.size = i + 1;
		
		return res;
	}
	friend long long operator % (const largeint& a, const long long& b)
	{
		long long res = 0;
		for (int i = a.size - 1; i >= 0; i--) res = (res * B + a[i]) % b;
		return res;
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
		cout << a[a.size - 1];
		for (int i = a.size - 2; i >= 0; i--) cout << setw(W) << setfill('0') << a[i];
		return cout;
	}
	
	private:
	static const long long S = 207, B = 1000000000, W = 9;
	long long s[S], size;
	
	long long& operator [] (const int& a) {return s[a];}
	const long long& operator [] (const int& a) const {return s[a];}
} x;

int main()
{
	char op;
	long long y;
	
	while (cin >> x >> op >> y)
		if (op == '/') cout << x / y << endl;
		else cout << x % y << endl;
	
	return 0;
}

