//首先发现这样一个规律：说服前面的人强行投票，不会差于说服后面的人强行投票。
//然后发现，随着说服强行投票的人变多，最后得到的票数单调增加。遂可以使用二分法。 
//二分答案，从前往后枚举每一个人，如果当前这个人的ai大于当前投票的人数，就让他强行投票。 
#include <iostream>
using namespace std;

const int N = 200007;
int a[N], n, m;

bool Can(int x)
{
	int Cur = 0;
	for (int i = 1; i <= n; i++)
	{
		if (a[i] <= Cur) ++Cur;
		else if (x > 0) {--x; ++Cur;}
		if (Cur >= m) return 1;
	}
	return 0;
}

int main()
{
	ios::sync_with_stdio(false);
	
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i];
	
	int Low = 0, High = m, Res; //[Low, High]的含义修改为可能出现更优答案的区间 
	while (Low <= High)
	{
		int Mid = (Low + High) / 2;
		if (Can(Mid)) {Res = Mid; High = Mid - 1;}
		else Low = Mid + 1;
	}
	
	cout << Res << endl;
	
	return 0;
}

