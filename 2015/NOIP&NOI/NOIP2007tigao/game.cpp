#include <fstream>
#include <algorithm>
#include <cstring>
using namespace std;

ifstream cin("game.in");
ofstream cout("game.out");

const int N = 87;
int a[N][N];
struct largeint
{
	static const long long S = 17, B = 1000000000;
	long long size, s[S];
	
	largeint() {size = 0; fill(s, s + S, 0);}
	largeint(long long num) {*this = num;}
	largeint Double() {return *this + *this;}
	
	largeint operator = (long long num)
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
		for (i = a.size + 1;; i--)
			if (a.s[i]) break;
		a.size = i + 1;
		return a;
	}
	largeint operator += (const largeint& that) {*this = *this + that; return *this;}
	friend bool operator < (const largeint& a, const largeint& b)
	{
		if (a.size != b.size) return a.size < b.size;
		for (int i = a.size - 1; i >= 0; i--)
			if (a.s[i] != b.s[i]) return a.s[i] < b.s[i];
		return false;
	}
	friend bool operator > (const largeint& a, const largeint& b)
	{
		return b < a;
	}
	friend ostream& operator << (ostream& cout, const largeint& a)
	{
		cout << a.s[a.size - 1];
		int i, j;
		for (i = a.size - 2; i >= 0; i--)
		{
			if (a.s[i] * 10 < B)
				for (j = 10; a.s[i] * j < B && j <= B; j *= 10) cout << '0';
			cout << a.s[i];
		}
		return cout;
	}
} f[N][N], ans;

int main()
{
	int n, m;
	int i, j, k;
	
	cin >> n >> m;
	for (i = 1; i <= n; i++)
		for (j = 1; j <= m; j++) cin >> a[i][j];
	
	for (i = 1; i <= n; i++)
	{
		memset(f, 0, sizeof(f));
		for (j = 1; j <= m; j++) f[j][j] = a[i][j] * 2;
		for (j = 1; j < m; j++)
			for (k = 1; k + j <= m; k++)
					f[k][k + j] = max((f[k + 1][k + j] + a[i][k]).Double(),
					(f[k][k + j - 1] + a[i][k + j]).Double());
		
		ans += *max_element(f[1] + 1, f[1] + m + 1);
	}
	
	cout << ans << endl;
	
	return 0;
}

