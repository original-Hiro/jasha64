#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstdio>
#include <cctype>
using namespace std;

const int N = 100007;
int n, x, y;
int a[N];
inline int Read()
{
	int r = 0;
	char c = getchar();
	while (!isdigit(c)) c = getchar();
	while (isdigit(c)) {r = r*10 + c-'0'; c = getchar();}
	return r;
}
int gcd(int a, int b) {return b ? gcd(b, a%b) : a;}
int lcm(int a, int b) {return a / gcd(a, b) * b;} //注意不能写成a*b/gcd，否则溢出 
int pre_gcd[N], pre_lcm[N], suf_gcd[N], suf_lcm[N];
bool Check(int i)
{
	int g, l;
	if (i == 0) {g = suf_gcd[1]; l = suf_lcm[1];}
	else if (i == n-1) {g = pre_gcd[n-2]; l = pre_lcm[n-2];}
	else {
		g = gcd(pre_gcd[i-1], suf_gcd[i+1]);
		l = lcm(pre_lcm[i-1], suf_lcm[i+1]);
	}
	return gcd(g/x, y/l) == 1; 
}
void Solve()
{
	if (y % x != 0) {cout << -1 << endl; return;}
	if (n == 1)
	{
		if (x != y) cout << -1 << endl;
		else if (a[0] == x) cout << 0 << endl;
		else cout << 1 << endl;
		return;
	}
	
	pre_gcd[0] = pre_lcm[0] = a[0];
	for (int i = 1; i < n; i++)
	{
		pre_gcd[i] = gcd(pre_gcd[i-1], a[i]);
		pre_lcm[i] = lcm(pre_lcm[i-1], a[i]);
	}
	suf_gcd[n-1] = suf_lcm[n-1] = a[n-1];
	for (int i = n-2; i >= 0; i--) //需要双向访问的就用闭区间，否则反向访问是不自然的 
	{
		suf_gcd[i] = gcd(suf_gcd[i+1], a[i]);
		suf_lcm[i] = lcm(suf_lcm[i+1], a[i]);
	}
	
	int c = 0;
	for (int i = 0; i < n; i++)
		if (y % a[i] != 0 || a[i] % x != 0) c++; //必须更改的元素个数 
	if (c == 0)
	{
		if (suf_gcd[0] == x && suf_lcm[0] == y) cout << 0 << endl;
		else {
			bool Zy = 0;
			for (int i = 0; !Zy && i < n; i++)
				if (Check(i)) Zy = 1;
			if (Zy) cout << 1 << endl;
			else cout << max(2, c) << endl;
		}
	}
	else if (c == 1)
	{
		int p;
		for (int i = 0; i < n; i++)
			if (y % a[i] != 0 || a[i] % x != 0) {p = i; break;}
		if (Check(p)) cout << 1 << endl;
		else cout << max(2, c) << endl;
	}
	else cout << max(2, c) << endl;
}

int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		cin >> n >> x >> y;
		for (int i = 0; i < n; i++) a[i] = Read();

		Solve();
	}

	return 0;
}

