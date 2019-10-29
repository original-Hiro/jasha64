#include <iostream>
#include <algorithm>
#include <string>
#include <sstream>
#include <cctype>
using namespace std;

class largeint
{
	public:
	largeint() {*this = "0";}
	largeint(const string& s) {*this = s;}
	
	largeint operator = (const string& num)
	{
		fill(s, s + S, 0);
		istringstream ss;
		size = num.size() / W;
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
	friend bool operator < (const largeint& a, const largeint& b)
	{
		if (a.size != b.size) return a.size < b.size;
		for (int i = a.size - 1; i >= 0; i--)
			if (a.s[i] != b.s[i]) return a.s[i] < b.s[i];
		return false;
	}
	
	private:
	static const long long S = 1117, B = 1000000000, W = 9; 
	long long s[S], size;
};
struct name
{
	string str;
	largeint num;
	
	friend bool operator < (const name& a, const name& b)
	{
		return a.num < b.num;
	}
} a[10007];

int main()
{
	int n;
	int i, j, begin, end;
	
	cin >> n;
	for (i = 0; i < n; i++)
	{
		cin >> a[i].str;
		for (j = 0; j < a[i].str.size(); j++)
		{
			if (isdigit(a[i].str[j]) && (j == 0 || !isdigit(a[i].str[j - 1]))) begin = j;
			else if (!isdigit(a[i].str[j]) && isdigit(a[i].str[j - 1]))
			{
				end = j;
				break;
			}
		}
		a[i].num = a[i].str.substr(begin, end - begin);
	}
	
	sort(a, a + n);
	for (i = 0; i < n; i++) cout << a[i].str << endl;
	
	return 0;
}

