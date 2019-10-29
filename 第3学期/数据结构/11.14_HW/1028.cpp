//10.131.235.233 - 1028
//此题关键在于把求解问题的过程看成每次往现有的树里增加一个点的过程（重复n次） 
//对于每次新加进来的点，我们要通过已知条件求出它对答案的贡献，等于到它的父节点的距离， 
//形象地说就等于k到离它最近的一个分岔点的距离 
//不难发现，(d[i][k] + d[k][j] - d[i][j]) / 2是节点k到lower(LCA(i, k), LCA(j, k))的距离， 
//或者形象地说，就等于k到路径i-k和路径k-j的交叉点的距离 
//由此可得，每次加入一个点i，则它对答案的贡献等于min{(d[1][i] + d[j][i] - d[1][j]) / 2 | 1 < j < i} 
//所以我们从只有节点1和2的初始状态（此时答案为d[1][2]）依次按上述方法加点即可 
#include <iostream>
#include <climits>
using namespace std;

int d[31][31];

int main()
{
	int n;
	while (cin >> n && n != 0)
	{
		for (int i = 1; i <= n; i++)
			for (int j = i+1; j <= n; j++) cin >> d[i][j];
		
		int res = d[1][2];
		for (int i = 3; i <= n; i++)
		{
			int cur = INT_MAX;
			for (int j = 2; j < i; j++) cur = min(cur, (d[1][i] + d[j][i] - d[1][j]) / 2);
			res += cur;
		}
		
		cout << res << endl;
	}
	return 0;
}
//参考资料：https://blog.csdn.net/peter_819/article/details/51236389

