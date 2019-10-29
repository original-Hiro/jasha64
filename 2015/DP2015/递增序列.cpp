#include <iostream>
#include <string>
#include <stack>
using namespace std;

const int N = 87;
int n;
string s;
struct Number
{
	string s;
	
	Number operator = (const string& str)
	{
		int i = 0, len = str.size();
		while (str[i] == '0' && i < len - 1) ++i;
		s = str.substr(i);
		return *this;
	}
	friend bool operator < (const Number& a, const Number& b)
	{
		if (a.s.size() != b.s.size()) return a.s.size() < b.s.size();
		int i, len = a.s.size();
		for (i = 0; i < len; ++i)
			if (a.s[i] != b.s[i]) return a.s[i] < b.s[i];
		return false;
	}
} a[N][N];
int f[N][N];

bool DP(int s, int t)
{
	if (f[s][t] || s == 1) return true;
	
	int i;
	bool Ret = false;
	
	for (i = 1; i <= s; ++i)
		if (DP(i, s - 1)) {f[s][t] = i; Ret = true;}
	
	return Ret;
}
void Print(int x)
{
	stack<int> Printer;
	int i = n - 1, j = 0;
	
	while (i)
	{
		Printer.push(i);
		i = f[x][i];
	}
	
	while (!Printer.empty())
	{
		i = Printer.top(); Printer.pop();
		if (j) cout << ',';
		for (; j <= i; ++j) cout << s[j];
	}
	cout << endl;
}

int main()
{
	int i, j, len;
	
	cin >> s;
	len = s.size();
	for (i = 0;  i < len; ++i)
		for (j = i; j < len; ++j) a[i + 1][j + 1] = s.substr(i, j - i + 1);
	
	for (i = len - 1; i >= 0; --i)
		if (DP(i, len)) {Print(i); return 0;}
	cout << s << endl;
	
	return 0;
}

