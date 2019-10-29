//10.131.235.233 - 1027
//数学推导 
//首先列举dist数列的前几项（从1开始编号）：
//0 0 1 1 0 0 2 2 0 0 1 1 0 0 3 3 0 0 1 1 0 0 2 2 0 0 1 1 0 0 4 4 ... 
//发现规律是dist(i) = max(f(i), f(i+1)) - 1, 其中f(i)的含义是i的二进制表示中末尾0的个数 
//又因为i和i+1中必有一个偶数而且这个偶数的f值一定比另一个(奇数)的大，所以 
//[1, x]的答案可以拆成[1, x]中的所有偶数f值减一之和+[1, x+1]的所有偶数f值减一之和 
//接下来我们分析[1, x]中所有偶数的f值减一之和怎么求：
//dist(2) = 0  dist(4) = 1 dist(6) = 0 dist(8) = 2 dist(10) = 0 dist(12) = 1 dist(14) = 0 dist(16) = 3 ... 
//发现其中大于0的个数是x/4个，大于1的个数是x/8个，大于2的个数是x/16个... 
//所以这个值等于summation(i = 1 ... +∞) x / (1<<i) 
#include <iostream>
using namespace std;

int f(int x)
{
	int ret = 0;
	for (unsigned int i = 4; i <= x+1; i <<= 1) ret += x / i + (x+1) / i; //注意x+1可能超出int范围 
	return ret;
}

int main()
{
	int l, r;
	cin >> l >> r;
	cout << f(r-1) - f(l-1) << endl;
	return 0;
}

