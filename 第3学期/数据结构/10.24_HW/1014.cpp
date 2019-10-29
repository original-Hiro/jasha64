//10.131.235.233 - 新汉诺塔 
//递归求解 
//朴素算法的时间复杂度是O(2^n)，因为每次移动一个盘子最多产生2^n步移动；加上优化以后去掉了时间表达式中所有的指数项，复杂度降到多项式级别 
#include <iostream>
using namespace std;
//ifstream cin("1014.in");
//ofstream cout("1014.out"); //debug

int cur[46], tar[46];
long long cnt = 0;
inline int rem(int a, int b) {return 6 - a - b;}
inline bool AllSame(int id)
{
	for (int i = id; i > 1; i--)
		if (cur[i] != cur[1]) return false;
	return true;
}
void Move(int id, int dest) //将id号盘移到dest号柱（需要将1号至id-1号盘全部先移到中间柱上） 
{
	if (cur[id] == dest) return;
	//优化：如果当前局面和目标局面的圆盘各都在同一个柱子上，则不必继续计算，直接将答案加以2^n-1 
	int d2 = rem(cur[id], dest);
	if (AllSame(id-1))
	{
		if (cur[1] != d2) //因为我们不保证不会出现目的地和出发地相同的情况，所以在此进行特判 
		{
			cnt += (1ll << id-1) - 1;
			for (int i = id-1; i > 0; i--) cur[i] = d2;
		}
		//cout << "AllSame! " << (1ll << id-1) - 1 << endl;
	}
	else for (int i = id-1; i > 0; i--) Move(i, d2);
	//cout << cur[id] << " -> " << dest << endl;
	cnt++; cur[id] = dest;
}

int main()
{
	int n;
	cin >> n;
	for (int i = 1; i <= 3; i++)
	{
		int k, c;
		cin >> k;
		while (k--) {cin >> c; cur[c] = i;}
	}
	for (int i = 1; i <= 3; i++)
	{
		int k, c;
		cin >> k;
		while (k--) {cin >> c; tar[c] = i;}
	}
	//for (int i = 1; i <= n; i++) cin >> cur[i];
	//for (int i = 1; i <= n; i++) cin >> tar[i]; //debug
	for (int i = n; i > 0; i--) Move(i, tar[i]);
	cout << cnt << endl;
	return 0;
}
//一开始自己设计的递归算法，Wrong Answer，遂查题解 
//参考资料：https://www.cnblogs.com/SoulSecret/p/8046901.html 

