#include <fstream>
using namespace std;

ifstream cin("dinner.in");
ofstream cout("dinner.out");

const int MAX_BIT = 31;
int MOD;

int With0(const int& x)
{
	int Res = 0, Cache = 1;
	for (int i = 1; i <= x; i++) {Cache = Cache * (x - i + 1) / i; Res += Cache;}
	return Res;
}
bool Prime(int a, int b)
{
	int c;
	while (b) {c = a % b; a = b; b = c;}
	return a == 1;
}

int main()
{
	int n;
	int Res, i1, i2, c1, c2;
	bool OK;
	
	cin >> n >> MOD;
	
	if (n > 30) return 0;
	if (MOD == 1) cout << 0 << endl;
	Res = (With0(n - 1) << 1) + 1; 
	for (c1 = 1 << 2; c1 < 1 << (n + 1); c1 += 1 << 2)
		for (c2 = 1 << 2; c2 < 1 << (n + 1); c2 += 1 << 2)
		{
			OK = true;
			for (i1 = 2; i1 <= n; i1++)
				if (c1 & (1 << i1))
				{
					for (i2 = 2; i2 <= n; i2++)
						if (c2 & (1 << i2))
							if (!Prime(i1, i2)) {OK = false; break;} 
					if (!OK) break;
				}
			if (OK) Res = (Res + 1) % MOD;
		}
	
	cout << Res << endl;
	
	return 0;
}

