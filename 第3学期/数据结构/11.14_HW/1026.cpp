//10.131.235.233 - 1026
//贪心 
//利用贪心算法的标准证明方法，易证如下算法的正确性: 
//按照DFS序遍历树，用mn[v]记录以v为根子树中代价系数(ti)的最小值，sum[v]记录子树中 
//权值(wi)的和，lim[v]表示节点v的限制值(ci)，则在访问完每个点的子节点后，如果 
//sum[v] < lim[v]，则我们在以v为根子树中代价系数最小的点上加权值lim[v] - sum[v] 
//（这对答案的贡献是(lim[v] - sum[v]) * mn[v]），这样就使得sum[v] = lim[v]，符合了 
//题目的要求 
#include <iostream>
#include <algorithm>
using namespace std;

const int N = 100001;
int mn[N], Left[N], Right[N], lim[N], cost[N];
long long sum[N];
//一开始写的是int, 被数据范围坑了一整页提交记录的WA 
//数据范围的估算还要加强意识 
inline void AddChild(int v, int u) {Right[u] = Left[v]; Left[v] = u;} //左儿子右兄弟 
long long res = 0;
void DFS(int v)
{
	if (Left[v] == 0) {mn[v] = cost[v]; sum[v] = lim[v]; res += lim[v] * cost[v]; return;}
	mn[v] = cost[v]; sum[v] = 0;
	for (int u = Left[v]; u != 0; u = Right[u]) {DFS(u); mn[v] = min(mn[v], mn[u]); sum[v] += sum[u];}
	if (lim[v] > sum[v]) {res += (lim[v] - sum[v]) * mn[v]; sum[v] = lim[v];}
}

int main()
{
	ios::sync_with_stdio(false);
	int n, rt;
	cin >> n;
	for (int i = 1, fa; i <= n; i++)
	{
		cin >> fa >> lim[i] >> cost[i];
		if (fa == -1) rt = i;
		else AddChild(fa, i);
	}
	DFS(rt);
	cout << res << endl;
	return 0;
}

