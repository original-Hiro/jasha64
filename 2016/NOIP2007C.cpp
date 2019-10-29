#include <iostream>
#include <algorithm>
#include <iomanip>
#include <cstring>
using namespace std;

const int N = 87;
int a[N][N];
struct largeint
{
	public:
	largeint() {*this = 0;}
	largeint(int num) {*this = num;}
	largeint operator = (int num)
	{
		fill(s, s + S, 0);
		size = 0;
		do {
			s[size++] = num % B;
			num /= B;
		} while (num > 0);
		return *this;
	}
	friend largeint operator + (largeint a, const largeint& b)
	{
		if (a.size < b.size) return b + a;
		for (int i = 0; i < b.size; i++)
		{
			a[i] += b[i];
			if (a.s[i] >= B)
			{
				a[i] -= B; a[i + 1]++;
				if (i == a.size - 1) a.size++;
			}
		}
		return a;
	}
	largeint operator += (const largeint& that) {*this = *this + that; return *this;}
	friend bool operator < (const largeint& a, const largeint& b)
	{
		if (a.size != b.size) return a.size < b.size;
		for (int i = a.size - 1; i >= 0; i--)
			if (a[i] != b[i]) return a[i] < b[i];
		return false;
	}
	friend ostream& operator << (ostream& cout, const largeint& c)
	{
		cout << c[c.size - 1];
		for (int i = c.size - 2; i >= 0; i--) cout << setw(W) << setfill('0') << c[i];
		return cout;
	}
	
	private:
	static const int B = 10000, S = 17, W = 4;
	int s[S], size;
	int& operator [] (int x) {return s[x];}
	const int& operator [] (int x) const {return s[x];}
} f[N][N];

int main()
{
	int n, m;
	
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++) cin >> a[i][j];
	
	largeint Ans;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++) f[j][j] = a[i][j];
		for (int k = 1; k < m; k++)
			for (int j = 1; j + k <= m; j++)
				f[j][j + k] = max(f[j][j + k - 1] + f[j][j + k - 1] + a[i][j + k],
				f[j + 1][j + k] + f[j + 1][j + k] + a[i][j]);
		Ans += f[1][m];
	}
	
	cout << Ans + Ans << endl;
	
	return 0;
}

