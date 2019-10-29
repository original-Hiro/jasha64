#include <iostream>
#include <cstdio>
using namespace std;

const int N = 1000007;
int DayN, OrderN;
int ClassroomN[N], Left[N], Right[N], Value[N];
int Low, High, Mid;
int f[N], Cache[N];

void BSearch()
{
	int i;
	
	Low = 1;
	High = OrderN;
	while (Low <= High)
	{
		Mid = (Low + High) >> 1;
		fill(f + 1, f + DayN + 1, 0);
		for (i = 1; i <= Mid; i++)
		{
			f[Left[i]] += Value[i];
			f[Right[i] + 1] -= Value[i];
		}
		for (i = 1; i <= DayN; i++)
		{
			Cache[i] = Cache[i - 1] + f[i];
			if (Cache[i] > ClassroomN[i]) {High = Mid - 1; break;}
		}
		if (i == DayN + 1) Low = Mid + 1;
	}
}

int main()
{
	freopen("classroom.in", "r", stdin);
	freopen("classroom.out", "w", stdout);
	
	int i;
	
	cin >> DayN >> OrderN;
	for (i = 1; i <= DayN; i++) scanf("%d", &ClassroomN[i]);
	for (i = 1; i <= OrderN; i++) scanf("%d%d%d", &Value[i], &Left[i], &Right[i]);
	BSearch();
	
	if (Low == OrderN + 1) cout << 0 << endl;
	else cout << -1 << endl << Low << endl;
	
	return 0;
}

