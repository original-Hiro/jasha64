#include <fstream>
#include <algorithm>
#include <iomanip>
using namespace std;

ifstream cin("calc.in");
ofstream cout("calc.out");
typedef long long ll;
const int N = 1007;
const ll MOD = 1000000007;
int q, n, k, a, b, mod;

template <typename T>
inline T gcd(T a, T b)
{
	if (a < b) swap(a, b);
	T c = a % b;
	while (c != 0) {a = b; b = c; c = a % b;}
	return b;
}
template <typename T>
inline T lcm(T a, T b) {return a / gcd(a, b) * b;}
namespace One
{
	void Work()
	{
		const int T[11][11] =
		{
			{0},
			{0, 1},
			{0, 2,  2},
			{0, 3,  6,  3},
			{0, 4,  12, 12,  4},
			{0, 5,  20, 30,  20,  5},
			{0, 6,  30, 60,  60,  30,   6},
			{0, 7,  42, 105, 140, 105,  42,   7},
			{0, 8,  56, 168, 280, 280,  168,  56,  8},
			{0, 9,  72, 252, 504, 630,  504,  252, 72,  9},
			{0, 10, 90, 360, 840, 1260, 1260, 840, 360, 90, 10}
		};
		
		int Res = T[n][1];
		for (int i = 2; i <= k; i++) Res = lcm(Res, T[n][i]);
		cout << Res << endl;
		int c[N], d[N];
		for (int i = 1; i < q; i++) cin >> c[i];
		for (int i = 1; i < q; i++) cin >> d[i];
		for (int i = 1; i < q; i++)
		{
			n = (a * Res + c[i]) % mod + 1; k = (b * Res + d[i]) % n + 1; Res = T[n][1];
			for (int i = 2; i <= k; i++) Res = lcm(Res, T[n][i]);
			cout << Res << endl;
		}
	}
}
namespace Two
{
	class largeint
	{
		public:
		largeint(int num = 0) {*this = num;}
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
		friend largeint operator + (const largeint& a, const largeint& b)
		{
			if (a < b) return b + a;
			largeint c;
			c.size = a.size;
			for (int i = 0; i < a.size; i++) c[i] = a[i] + b[i];
			for (int i = 0; i < c.size; i++)
				if (c[i] >= B)
				{
					c[i] -= B;
					++c[i + 1];
					if (i == c.size - 1) ++c.size;
				}
			return c;
		}
		friend largeint operator - (const largeint& a, const largeint& b)
		{
			largeint c;
			c.size = a.size;
			for (int i = 0; i < a.size; i++) c[i] = a[i] - b[i];
			for (int i = 0; i < c.size; i++)
				if (c[i] < 0)
				{
					c[i] += B;
					--c[i + 1];
					if (c[i + 1] == 0 && i == c.size - 1) --c.size;
				}
			return c;
		}
		friend largeint operator * (const largeint& a, const largeint& b)
		{
			largeint c;
			c.size = a.size + b.size;
			for (int i = 0; i < a.size; i++)
				for (int j = 0; j < b.size; j++)
				{
					c[i + j] += a[i] * b[j];
					if (c[i + j] >= B) {c[i + j + 1] += c[i + j] / B; c[i + j] %= B;}
				}
			for (int i = 0; i < c.size; i++)
				if (c[i] >= B) {c[i + 1] += c[i] / B; c[i] %= B;}
			int i;
			for (i = c.size - 1; i > 0; i--)
				if (c[i]) break;
			c.size = i + 1;
			return c;
		}
		friend largeint operator / (const largeint& a, int b)
		{
			if (b != 2) {cout << "ERROR!" << endl; return 0;}
			largeint c;
			c.size = a.size;
			for (int i = a.size - 1; i > 0; i--)
			{
				if (a[i] & 1) c[i - 1] += B >> 1;
				c[i] += a[i] >> 1;
				if (i == a.size - 1 && !c[i]) --c.size;
			}
			c[0] += a[0] >> 1;
			return c;
		}
		friend largeint operator / (const largeint& a, const largeint& b)
		{
			largeint Low = 1, Mid, High = a, c, Ret;
			while (Low <= High)
			{
				Mid = (Low + High) / 2;
				c = Mid * b;
				if (c == a) return Mid;
				if (c < a) {Low = Mid + 1; Ret = Mid;}
				else High = Mid - 1;
			}
			return Ret;
		}
		friend ll operator % (const largeint& a, const ll& b)
		{
			ll Ret = 0;
			for (int i = a.size - 1; i >= 0; i--) Ret = (Ret * B + a[i]) % b;
			return Ret;
		}
		friend largeint operator % (const largeint& a, const largeint& b) {return a - a / b * b;}
		friend bool operator < (const largeint& a, const largeint& b)
		{
			if (a.size != b.size) return a.size < b.size;
			for (int i = a.size - 1; i >= 0; i--)
				if (a[i] != b[i]) return a[i] < b[i];
			return false;
		}
		friend ostream& operator << (ostream& cout, const largeint& a)
		{
			cout << a[a.size - 1];
			for (int i = a.size - 2; i >= 0; i--) cout << setw(W) << setfill('0') << a[i];
			return cout;
		}
		friend bool operator == (const largeint& a, const largeint& b) {return !(b < a) && !(a < b);}
		friend bool operator <= (const largeint& a, const largeint& b) {return !(b < a);}
		friend bool operator != (const largeint& a, const largeint& b) {return b < a || a < b;}
		private:
		static const int B = 10000, S = 27, W = 4;
		int s[S], size;
		int& operator [] (int x) {return s[x];}
		const int& operator [] (int x) const {return s[x];}
	} t[107][107];
	void Work()
	{
		for (int i = 1; i <= 100; i++)
		{
			t[i][1] = i;
			for (int j = 2; j <= i; j++)
				t[i][j] = t[i][j - 1] * t[i - 1][j - 1] / (t[i][j - 1] - t[i - 1][j - 1]);
		}
		
		largeint cache = t[n][1];
		ll Res;
		for (int i = 2; i <= k; i++) cache = lcm(cache, t[n][i]);
		cout << (Res = cache % MOD) << endl;
		int c[N], d[N];
		for (int i = 1; i < q; i++) cin >> c[i];
		for (int i = 1; i < q; i++) cin >> d[i];
		for (int i = 1; i < q; i++)
		{
			n = (a * Res + c[i]) % mod + 1; k = (b * Res + d[i]) % n + 1;
			cache = t[n][1];
			for (int i = 2; i <= k; i++) cache = lcm(cache, t[n][i]) % MOD;
			cout << (Res = cache % MOD) << endl;
		}
	}
}

int main()
{
	cin >> q >> n >> k >> a >> b >> mod;
	
	if (mod <= 10) One::Work();
	else Two::Work();
	
	return 0;
}

