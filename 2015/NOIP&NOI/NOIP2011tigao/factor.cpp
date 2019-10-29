#include <fstream>
using namespace std;

ifstream cin("factor.in");
ofstream cout("factor.out");
const long long MOD = 10007, N = 1005;
long long C[N][N];

inline long long Pow(const int& a, const int& n)
{
	if (n == 0) return 1;
	if (n == 1) return a;
	long long c = Pow(a, n / 2) % MOD;
	if (n % 2) return c * c * a % MOD;
	else return c * c % MOD;
}
inline void Calc(const int& k)
{
	int i, j;
	C[0][0] = C[1][0] = C[1][1] = 1;
	for (i = 2; i <= k; i++)
		for (j = 0; j <= i; j++) C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % MOD;
}

int main()
{
	int a, b, k, n, m;
	
	cin >> a >> b >> k >> n >> m;
	
	Calc(k);
	
	cout << Pow(a, n) % MOD * Pow(b, m) % MOD * C[k][n] % MOD << endl;
	
	return 0;
}

