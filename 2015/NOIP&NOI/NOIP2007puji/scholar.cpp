#include <iostream>
using namespace std;

struct Student
{
	int Chi, Tot, Num;
	
	friend istream& operator >> (istream& cin, Student& a)
	{
		int b, c;
		cin >> a.Chi >> b >> c;
		a.Tot = a.Chi + b + c;
		return cin;
	}
	friend ostream& operator << (ostream& cout, const Student& a)
	{
		cout << a.Num << ' ' << a.Tot;
		return cout;
	}
	friend bool operator > (const Student& a, const Student& b)
	{
		if (a.Tot != b.Tot) return a.Tot > b.Tot;
		if (a.Chi != b.Chi) return a.Chi > b.Chi;
		return a.Num < b.Num;
	}
} s[307], c;

int main()
{
	int n;
	int i, Pos, Top;
	
	cin >> n;
	for (i = 1; i <= n; i++)
	{
		cin >> s[i];
		s[i].Num = i;
	}
	
	for (Top = 1; Top <= 5; Top++)
	{
		Pos = Top;
		for (i = Top + 1; i <= n; i++)
			if (s[i] > s[Pos]) Pos = i;
		c = s[Pos]; s[Pos] = s[Top]; s[Top] = c;
	}
	
	for (i = 1; i <= 5; i++) cout << s[i] << endl;
	
	return 0;
}

