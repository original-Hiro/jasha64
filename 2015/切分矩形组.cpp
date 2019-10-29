#include <iostream>
#include <cstdio>
using namespace std;

int n, Low = 1100000, High;
struct Rectangle
{
	int x0, x1, h;
	friend istream& operator >> (istream& cin, Rectangle& a)
	{
		int b0, w;
		cin >> a.x0 >> b0 >> w >> a.h;
		a.x1 = a.x0 + w;
		Low = min(Low, a.x0); High = max(High, a.x1);
		return cin;
	}
} a[10007];

inline long long Abs(long long x) {return x < 0 ? -x : x;}
inline long long f(int k)
{
	long long r = 0;
	for (int i = 0; i < n; ++i)
		if (a[i].x0 < k && k < a[i].x1) r += a[i].h * (a[i].x0 + a[i].x1 - (k << 1));
		else if (k <= a[i].x0) r += a[i].h * (a[i].x1 - a[i].x0);
		else r -= a[i].h * (a[i].x1 - a[i].x0);
	return r;
}

int main()
{
	int i, Mid;
	long long c;
	
	cin >> n;
	for (i = 0; i < n; ++i) cin >> a[i];
	
	while (Low <= High)
	{
		c = f(Mid = (Low + High) >> 1);
		if (c <= 0) High = Mid - 1;
		else Low = Mid + 1;
	}
	
	if (Abs(f(Low)) < Abs(f(High))) cout << Low << endl;
	else cout << High << endl;
	
	return 0;
}

