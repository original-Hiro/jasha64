#include <iostream>
#include <cstring>
using namespace std;

const int N = 2;
const long long MOD = 1000000007;

struct Matrix
{
	int l, c;
	long long a[N][N];
	Matrix() {memset(a, 0, sizeof(a)); l = c = 0;}
	friend Matrix operator * (const Matrix& a, const Matrix& b)
	{
		Matrix Res;
		int m = a.l, n = b.c, p = a.c;
		Res.l = m; Res.c = n;
		for (int i = 0; i < m; i++)
			for (int j = 0; j < n; j++)
				for (int k = 0; k < p; k++) Res[i][j] = (Res[i][j] + a[i][k] % MOD * b[k][j] % MOD) % MOD;
		return Res;
	}
	long long* operator [] (int x) {return a[x];}
	const long long* operator [] (int x) const {return a[x];}
};

long long f(long long n)
{
	Matrix A, B, Res;
	A[0][0] = A[1][0] = A[1][1] = 0; A[0][1] = 1; A.l = A.c = 2;
	B[0][0] = 0; B[0][1] = B[1][0] = B[1][1] = 1; B.l = B.c = 2;
	Res[0][0] = Res[1][1] = 1; Res[1][0] = Res[0][1] = 0; Res.l = Res.c = 2;
	
	--n;
	while (n)
	{
		if (n & 1) Res = Res * B;
		B = B * B; n >>= 1;
	}
	
	Res = A * Res;
	return Res[0][1];
}

int main()
{
	ios::sync_with_stdio(false);
	
	long long n;
	while (cin >> n) cout << f(n) << endl;
	
	return 0;
}

