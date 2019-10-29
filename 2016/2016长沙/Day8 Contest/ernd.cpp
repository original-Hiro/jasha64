#include <fstream>
using namespace std;

ifstream cin("ernd.in");
ofstream cout("ernd.out");
int n, k;
long long Res, MOD;

namespace One
{
	int a[17], f[17], ALL_BITS;
	
	int Find(int x) {return f[x] == x ? x : f[x] = Find(f[x]);}
	void Search(int cur)
	{
		if (cur == ALL_BITS) return;
		for (int i = a[cur - 1] + 1; i < ALL_BITS; i++)
		{
			for (int j = 1; j <= cur; j++) f[j] = j;
			a[cur] = i;
			for (int j = 1; j <= cur; j++)
				for (int k = 1; k <= cur; k++)
					if (j != k && (a[j] & a[k])) f[Find(j)] = Find(k);
			int block = 0;
			for (int j = 1; j <= cur; j++)
				if (Find(j) == j) ++block;
			if (block == k)	Res = (Res + 1) % MOD;
			Search(cur + 1);
		}
	}
	void Work()
	{
		ALL_BITS = 1 << n;
		Search(1);
	}
}

int main()
{
	cin >> n >> k >> MOD;
	if (MOD == 1) {cout << 0 << endl; return 0;}
	if (n == k) {cout << 1 << endl; return 0;}
	
	One::Work();
	
	cout << Res << endl;
	
	return 0;
}

