#include <cstdio>
using namespace std;

typedef long long ll;
const ll MOD = (1ll << 32) - 1;
void Ext_Gcd(ll a, ll b, ll& x, ll& y)
{
	if (b == 0) {x = 1; y = 0; return;}
	Ext_Gcd(b, a%b, y, x); y -= x*(a/b);
}
inline void Rev_Mod(ll& t, const ll a)
{
	ll x, y;
	Ext_Gcd(a, MOD, x, y);
	x = (x % MOD + x) % MOD;
	x = (x * t) % MOD;
}
bool Test2(ll t)
{
	const ll c3 = (1 << 10) + 1;
	Rev_Mod(t, c3);
	printf("%lld\n", t);
	return true;
}
bool Test(ll t)
{
	const ll c2 = (1 << 3) + 1;
	Rev_Mod(t, c2);
	for (int i = 0; i < (1 << 27); i++)
	{
		ll c = t ^ i;
		if ((c >> 6) == i)
			if (Test2(c)) return true;
	}
}

int main()
{
	int q;
	scanf("%d", &q);
	while (q--)
	{
		ll t;
		scanf("%lld", &t);
		const int c1 = (1 << 16) + 1;
		Rev_Mod(t, c1);
		for (int i = 0; i < (1 << 22); i++)
		{
			ll c = t ^ i;
			if ((c >> 11) == i)
				if (Test(c)) break;
		}
	}
	
	return 0;
}

