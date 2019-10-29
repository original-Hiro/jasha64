//SPOJ - running median again
//堆 
//我们可以通过把数列如下划分成两半把在线求中位数的问题转化成在线求最值的问题： 
//用一个大根堆装数组的前一半，即a[0..(n+1)/2] 
//用一个小根堆装数组的后一半，即a[(n+1)/2+1..n-1] 
//这样，欲求中位数，则只需要取出大根堆的根即可 
//注意插入和删除元素时维护好两个堆，使得大根堆的最值始终是数组最中间的数 
#include <cstdio>
#include <cctype>
#include <queue>
#include <vector>
#include <cstdlib>
using namespace std;

//值得一提的是，此题输入数据量是未知的，可能会很大，所以需要加读入优化 
//（事实上，通过关闭流同步的流输入是会TLE的） 
inline int Read()
{
	int r = 0;
	bool isNeg = 0;
	char c = getchar();
	while (!isdigit(c) && c != '-') c = getchar();
	if (c == '-') {isNeg = 1; c = getchar();}
	while (isdigit(c)) {r = r * 10 + c - '0'; c = getchar();}
	return isNeg ? -r : r;
}

int main()
{
	int T = Read();
	while (T--)
	{
		priority_queue<int> Front;
		priority_queue<int, vector<int>, greater<int> > Rear;
		int x;
		while ((x = Read()) != 0)
		{
			if (x == -1)
			{
				printf("%d\n", Front.top()); Front.pop();
				if (Front.size() < Rear.size()) {Front.push(Rear.top()); Rear.pop();}
				continue;
			}
			if (Front.empty()) {Front.push(x); continue;}
			int cmid = Front.top();
			if (x <= cmid)
			{
				Front.push(x);
				if (Front.size() > Rear.size() + 1) {Rear.push(Front.top()); Front.pop();}
			}
			else {
				Rear.push(x);
				if (Rear.size() > Front.size()) {Front.push(Rear.top()); Rear.pop();}
			}
		}
		printf("\n");
	}
	
	return 0;
}
//参考资料: https://www.luogu.org/problemnew/solution/SP15376

