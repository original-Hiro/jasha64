#include <fstream>
using namespace std;

ofstream cout("±í.txt");
const int N = 100007, SIZE = 25;
const long long MOD = 1000000007;
long long Pow[N], f[N];
int fa[N];

int Find(int x) {return fa[x] == x ? x : fa[x] = Find(fa[x]);}
long long Ans(int x)
{
	if (x & 1) return Ans(x - 1) * 26 % MOD;
	for (int i = 1; i <= x; i++) fa[i] = i;
	for (int i = 1; i <= x; i++)
		if (i & 1) fa[Find((x >> 1) + (i + 1 >> 1))] = Find(i);
		else fa[Find(i >> 1)] = Find(i);
	int c = 0;
	for (int i = 1; i <= x; i++)
		if (Find(i) == i) ++c;
	return Pow[c];
}

int main()
{
	Pow[0] = 1;
	for (int i = 1; i <= N; i++) Pow[i] = Pow[i - 1] * 26 % MOD;
	f[1] = 26;
	for (int i = 2; i <= N; i++) f[i] = Ans(i);
	
	long long Res = 0;
	for (int i = 0; i <= N; i++)
	{
		Res = (Res + f[i]) % MOD;
		if (i % SIZE == 0) {cout << Res << ','; Res = 0;}
	}
	cout << Res << endl;
	
	return 0;
}

