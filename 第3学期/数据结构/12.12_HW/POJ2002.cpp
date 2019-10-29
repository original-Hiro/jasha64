//POJ 2002 Squares
//hash 
//强烈谴责POJ还是C++98，用不了unordered_set，不得不手写一份Hash 
#include <iostream>
#include <cstring>
using namespace std;

const int N = 1001, MH = 999979; //哈希表越大，越不容易出现冲突，此处选用靠近1e6的质数作为模数 
struct Node
{
	int x, y, Next;
} pt[N]; //静态链表，易于调试 
int top = 1, x[N], y[N];
int Hash[MH];
inline int H(int x, int y) {return (x * x + y * y) % MH;} //这个哈希函数有两个参数，此处采取平方和+取余作为哈希函数 
//值得一提的是，题目已经说明|x|, |y| < 20000，这时我们可以把(x, y)看作20000进制数 
//这样得到的哈希是完美哈希，理论上说是不用处理冲突的 
//然而经过实际测试，这样写会WA，加上冲突处理则TLE，说明出题人卡了这种哈希。深表遗憾 
inline void Insert(int x, int y)
{
	int h = H(x, y);
	pt[top].x = x; pt[top].y = y;
	pt[top].Next = Hash[h]; Hash[h] = top++;
}
bool Find(int x, int y)
{
	int h = H(x, y), cur = Hash[h];
	while (cur != 0)
	{
		if (pt[cur].x == x && pt[cur].y == y) return true;
		cur = pt[cur].Next;
	}
	return false;
}

int main()
{
	ios::sync_with_stdio(false);
	int n;
	while (cin >> n && n != 0)
	{
		memset(Hash, 0, sizeof(Hash)); top = 1; //多笔测资初始化 
		for (int i = 0; i < n; i++) {cin >> x[i] >> y[i]; Insert(x[i], y[i]);}
		
		/*
		解题思路：因为定了两个点以后，以它们为顶点的正方形的另两个点的坐标易求得， 
		所以我们采取这种做法：把所有点插入哈希表，O(n*n)枚举点对，对每个枚举到的 
		点对，查询另两个点是否在哈希表中。这样就把几何问题转化成了索引问题。总时 
		间复杂度O(n*n) 
		*/
		int res = 0;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < i; j++)
			{
				int x1 = x[i], y1 = y[i], x2 = x[j], y2 = y[j];
				int x3, y3, x4, y4;
				int dx = -(y2 - y1), dy = x2 - x1;
				x3 = x1 + dx; y3 = y1 + dy;
				x4 = x2 + dx; y4 = y2 + dy;
				if (Find(x3, y3) && Find(x4, y4)) res++;
				x3 = x1 - dx; y3 = y1 - dy;
				x4 = x2 - dx; y4 = y2 - dy;
				if (Find(x3, y3) && Find(x4, y4)) res++;
			}
		
		res /= 4;
		cout << res << endl;
	}
	
	return 0;
}
//一开始想不出来做法，看了一眼标签，然后钻进通过哈希值直接判断正方形的死胡同里出不来了，丢人 
//参考资料：https://blog.csdn.net/alongela/article/details/8247605 

