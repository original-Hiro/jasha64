//SPOJ - assembly line
//最小值最大，用二分 
//此题思路和NOIP2011聪明的质检员挺像，可能太久没做这种二分，忘记了 
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cctype>
using namespace std;

inline int Read()
{
	int r = 0;
	char c = getchar();
	while (!isdigit(c)) c = getchar();
	while (isdigit(c)) {r = r * 10 + c - '0'; c = getchar();}
	return r;
}
const int N = 100001;
int n, sp[N], cost[N];
long long tot;
bool Check(const long long val)
{
	long long rem = tot;
	for (int i = 0; i < n; i++)
		if (val > sp[i] && (rem -= cost[i] * (val - sp[i])) < 0) return false; //细心！一开始忘写val > sp[i]跪了一次 
	return true;
}

int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		cin >> n >> tot;
		for (int i = 0; i < n; i++) {sp[i] = Read(); cost[i] = Read();}
		
		//所有类型的二分都面临一个头疼的问题：最后答案应该等于Low还是等于High？("off by 1 problem") 
		//在最小值最大类的问题中，因为只需要Mid这一点的信息，所以有一种比较保险的写法 
		//我们把[Low, High]的定义从"最优解所在区间"修改为"更优解所在区间"，同时维护一个Res记录当前已经算出的最优解 
		//显然最后的答案就是Res 
		long long Low = *min_element(sp, sp+n), High = 2e12, Res = Low;
		while (Low <= High)
		{
			long long Mid = (Low + High) / 2;
			if (Check(Mid)) {Res = Mid; Low = Mid + 1;}
			//已经验证Mid可行，修改Res = Mid，修改Low = Mid+1（更优解只可能出现在[Mid+1, High]) 
			else High = Mid - 1;
		}
		cout << Res << endl;
	}
	
	return 0;
}
//参考资料：https://ideone.com/wOLsFC 

