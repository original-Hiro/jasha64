//10.131.235.233 - 1036
//高精度 
#include <iostream>
#include <iomanip>
#include <algorithm>
using namespace std;

class largeint
{
public:
	largeint(int a = 0) {*this = a;}
	largeint operator = (int a)
	{
		siz = 0;
		do {
			s[siz++] = a % B;
			a /= B;
		} while (a > 0);
		return *this;
	}
	friend largeint operator * (const largeint& a, const largeint& b)
	{
		largeint res;
		fill(res.s, res.s + S, 0);
		for (int i = 0; i < a.siz; i++)
			for (int j = 0, c = 0; j < b.siz; j++)
			{
				res[i+j] += c + a[i] * b[j];
				c = res[i+j] / B; res[i+j] %= B;
				if (j == b.siz - 1 && c != 0) res[i+j+1] += c;
			}
		res.siz = a.siz + b.siz;
		while (res.siz > 1 && res[res.siz - 1] == 0) res.siz--;
		return res;
	}
	largeint operator *= (const largeint& that) {*this = *this * that; return *this;}
	friend largeint operator / (const largeint& a, int b)
	{
		largeint res;
		for (long long c = 0, i = a.siz - 1; i >= 0; i--)
		{
			c = c * B + a[i];
			res[i] = c / b; c %= b;
		}
		res.siz = a.siz;
		while (res.siz > 1 && res[res.siz-1] == 0) res.siz--;
		return res;
	}
	largeint operator /= (int that) {*this = *this / that; return *this;}
	friend ostream& operator << (ostream& output, const largeint& a)
	{
		output << a[a.siz-1];
		for (int i = a.siz-2; i >= 0; i--) output << setw(W) << setfill('0') << a[i];
		return output;
	}
private:
	static const int S = 1000, B = 10000, W = 4;
	int s[S], siz;
	int& operator [] (int x) {return s[x];}
	const int& operator [] (int x) const {return s[x];}
};
largeint C(int n, int m) //O(n)求组合数（但必须确保中间结果不会溢出） 
{
	if (m < n-m) m = n-m;
	largeint ret = 1;
	for (int i = m+1; i <= n; i++) ret *= i;
	for (int i = 1; i <= n-m; i++) ret /= i;
	return ret;
}

int main()
{
	int n;
	cin >> n; n--;
	cout << C(n+n, n) / (n+1) << endl; //套用公式即可 
	return 0;
}

