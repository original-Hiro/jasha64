#include <iostream>
#include <vector>
using namespace std;

const int MAXN = 200001, MOD = 998244353;
int n, m, Fac[MAXN], Inv[MAXN];
void Pre_Process()
{
    Fac[0] = Fac[1] = Inv[0] = Inv[1] = 1;
    for (int i = 2; i < MAXN; i++)
    {
        Fac[i] = (long long)Fac[i - 1] * i % MOD;
        Inv[i] = MOD - (long long)Inv[MOD % i] * (MOD / i) % MOD;
    }
    for (int i = 2; i < MAXN; i++) Inv[i] = (long long)Inv[i - 1] * Inv[i] % MOD;
}
inline int C(int u, int v)
{
	if (u < 0 || v < 0 || u < v) return 0;
	return (long long)Fac[u] * Inv[v] % MOD * Inv[u - v] % MOD;
}
inline int Calc(int a, int b, int d) {return (C(b+1+d, d+1) - C(a+d, d+1) + MOD) % MOD;}
 
struct Modi
{
    int pos, dep, val;
    Modi(int pos, int dep, int val): pos(pos), dep(dep), val(val) {}
};
vector<Modi> v;
 
int main()
{
    ios::sync_with_stdio(false);
    Pre_Process();
    
    int T;
    cin >> T;
    while (T--)
    {
        v.clear();
        cin >> n >> m;
        for (int i = 1, cur = 0, op; i <= m; i++)
        {
            cin >> op;
            if (op == 1)
            {
                int a, b, val;
                cin >> a >> b >> val;
                v.push_back(Modi(a, cur, val));
                v.push_back(Modi(b + 1, cur, MOD - val));
            }
            else if (op == 2) cur++;
            else {
                int l, r, Res = 0;
                cin >> l >> r;
                for (const Modi& f : v)
                {
                    if (f.pos > r) continue;
                    int d = cur - f.dep;
                    int a = max(0, l - f.pos), b = r - f.pos;
                    Res = (Res + (long long)Calc(a, b, d) * f.val) % MOD;
                }
                cout << Res << endl;
            }
        }
    }
    
    return 0;
}

