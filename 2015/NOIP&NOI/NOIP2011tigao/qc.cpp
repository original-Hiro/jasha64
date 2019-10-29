#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long ll;

const int N = 200007;
int StoneN, RangeN, Weight[N], Value[N], LeftB[N], RightB[N];
ll Std_Value;
int Low, High;
ll f1[N], f2[N];

template <typename T>
inline T Abs(const T& x)
{
	if (x < 0) return -x;
	return x;
}
ll Res_Value(const int& Check)
{
	fill(f1 + 1, f1 + StoneN + 1, 0);
	fill(f2 + 1, f2 + StoneN + 1, 0);
	
	int i;
	ll Res = 0;
	
	for (i = 1; i <= StoneN; i++)
		if (Weight[i] >= Check)
		{
			f1[i] = f1[i - 1] + Value[i];
			f2[i] = f2[i - 1] + 1;
		}
		else {
			f1[i] = f1[i - 1];
			f2[i] = f2[i - 1];
		}
	for (i = 1; i <= RangeN; i++)
		Res += (f1[RightB[i]] - f1[LeftB[i] - 1]) * (f2[RightB[i]] - f2[LeftB[i] - 1]);
	return Res;
}
void BSearch()
{
	int Mid;
	ll Cur;
	
	Low = *min_element(Weight + 1, Weight + StoneN + 1);
	High = *max_element(Weight + 1, Weight + StoneN + 1) + 1;
	while (Low <= High)
	{
		Mid = (Low + High) >> 1;
		Cur = Res_Value(Mid) - Std_Value;
		if (Cur == 0) {Low = High = Mid; return;}
		if (Cur < 0) High = Mid - 1;
		else Low = Mid + 1;
	}
}

int main()
{
	freopen("qc.in", "r", stdin);
	freopen("qc.out", "w", stdout);
	
	int i;
	
	cin >> StoneN >> RangeN >> Std_Value;
	for (i = 1; i <= StoneN; i++) scanf("%d%d", &Weight[i], &Value[i]);
	for (i = 1; i <= RangeN; i++) scanf("%d%d", &LeftB[i], &RightB[i]);
	
	BSearch();
	
	cout << min(Abs(Res_Value(Low) - Std_Value), Abs(Res_Value(High) - Std_Value)) << endl;
	
	return 0;
}

