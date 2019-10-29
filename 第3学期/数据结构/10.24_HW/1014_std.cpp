#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long LL;
const int N = 45 + 5;

int n;
LL ans;

bool AllSame(const vector <int>& vec)
{
	for (int i = 2; i < vec.size(); i ++)
		if (vec[i] != vec[1])
			return false;
	return true;
}

LL Calc(int cnt, vector <int> PosA, vector <int> PosB)
{
	if (cnt == 0) return 0;
	if (PosA[cnt] == PosB[cnt])
	{
		PosA.pop_back();
		PosB.pop_back();
		return Calc(cnt - 1, PosA, PosB);
	}
	if (AllSame(PosA) && AllSame(PosB)) {
		printf("AllSame! %lld\n", (1LL << cnt) - 1);
		return (1LL << cnt) - 1;
	}
	int mid = 6 - PosA[cnt] - PosB[cnt];
	vector <int> transfer(cnt);
	for (int i = 1; i < cnt; i ++)
		transfer[i] = mid;
	int c1 = PosA.back(); PosA.pop_back();
	int c2 = PosB.back(); PosB.pop_back();
	LL a = Calc(cnt - 1, PosA, transfer);
	printf("%d -> %d\n", c1, c2);
	return a + 1 + Calc(cnt - 1, transfer, PosB);
}

int main()
{
	//freopen("1014.in", "r", stdin);
	//freopen("1014_std.out", "w", stdout); //debug
	scanf("%d", &n);
	vector <int> PosA(n + 1), PosB(n + 1);
	for (int i = 1, c; i <= 3; i ++)
	{
		scanf("%d", &c);
		for (int j = 1, x; j <= c; j ++)
		{
			scanf("%d", &x);
			PosA[x] = i;
		}
	}
	for (int i = 1, c; i <= 3; i ++)
	{
		scanf("%d", &c);
		for (int j = 1, x; j <= c; j ++)
		{
			scanf("%d", &x);
			PosB[x] = i;
		}
	}
	//for (int x = 1; x <= n; x++) scanf("%d", &PosA[x]);
	//for (int x = 1; x <= n; x++) scanf("%d", &PosB[x]); //debug
	ans = Calc(n, PosA, PosB);
	printf("%lld\n", ans);
	return 0;
}
