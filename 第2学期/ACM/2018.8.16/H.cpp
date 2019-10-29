#include <iostream>
using namespace std;
#define ls p<<1
#define rs ls|1
#define lson ls, l, mid
#define rson rs, mid+1, r

const int MAXN = 100001, MAXK = 42, MOD = 1000000007;
int n, m, k, D;
int Pow(int a, int b)
{
	if (b == 1) return a;
	int c = Pow(a, b / 2) % MOD;
	if (b % 2) return (long long)c * c % MOD * a % MOD;
	else return (long long)c * c % MOD;
}
struct Segment_Tree
{
    static const int MAXN = 1 << 18 | 1;
    int s[MAXN][MAXK], c[MAXK];
    
    int Query(int p, int l, int r, int x)
	{
        int Ret = 0;
		for (int i = 0; i <= k; i++) Ret = (Ret + (long long)s[p][i] * c[i]) % MOD;
        if (l == r) return Ret;
		int mid = (l + r) / 2;
        if (x <= mid) Ret = (Ret + Query(lson, x)) % MOD;
        else Ret = (Ret + Query(rson, x)) % MOD;
        return Ret;
    }
    int Query(int x)
	{
        c[0] = 1;
		for (int i = 1; i <= k; i++) c[i] = (long long)c[i-1] * x % MOD;
        return (long long)Query(1, 1, n, x) * D % MOD;
    }
    void Add(int p, int l, int r, int fir, int las)
	{
        if (l == fir && r == las)
		{
            for (int i = 0; i <= k; i++)
				if ((s[p][i] += c[i]) >= p) s[p][i] -= MOD;
            return;
        }
        int mid = (l + r) / 2;
        if (las <= mid) Add(lson, fir, las);
        else if (fir > mid) Add(rson, fir, las);
        else {Add(lson, fir, mid); Add(rson, mid+1, las);}
    }
    void Add(int x, int y)
	{
        c[0] = 1;
		for (int i = 1; i <= k; i++) c[i] = 0;
        for (int i = 1, t = k-x; i <= k; i++, t--)
		{
            for (int j = k; j >= 1; j--) c[j] = ((long long)t * c[j] + c[j-1]) % MOD;
            c[0] = (long long)c[0] * t % MOD;
        }
        for (int i = 0; i <= k; i++) c[i] = (long long)c[i] * y % MOD;
        for (int i = 0; i <= k; i++)
			if (c[i] < 0) c[i] += MOD;
        Add(1, 1, n, x, n);
    }
} T;

int main(){
	ios::sync_with_stdio(false);
	cin >> n >> m >> k;
    k--;
	D = 1;
	for (int i = 1; i <= k; i++) D = (long long)D * i % MOD;
	D = Pow(D, MOD-2);
	
    while (m--)
	{
        int op, x, y;
        cin >> op >> x;
        if (op == 0) {cin >> y; T.Add(x, y);}
		else cout << (T.Query(x) + MOD) % MOD << endl;
    }
    
    return 0;
}

