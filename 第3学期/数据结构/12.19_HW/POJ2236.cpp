//POJ 2236 Wireless Network
//并查集 
#include <iostream>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <cctype>
using namespace std;

const int N = 1002;
const double eps = 1e-6;
int x[N], y[N];
bool G[N][N], w[N]; //w: whether it works
inline double dist(int p1, int p2) {return hypot(x[p1]-x[p2], y[p1]-y[p2]);}
inline int dcmp(double x) //浮点误差处理函数 
{
	if (fabs(x) <= eps) return 0;
	return x < 0 ? -1 : 1;
}
//一开始浮点误差没处理好，被坑惨了 
//一开始以为比较的时候会自动把dist转换成int，但实际上则是把不等号两边变量转换成高类型(double) 
//然后直接把dist函数返回值改成int，返回hypot(dx, dy)+eps，但是这样如果求出的结果是[d, d+1)的double，就会认为距离没有超过d 
//所以对待浮点误差要小心 
int f[N];
int Find(int x)
{
	if (f[x] == x) return x;
	return f[x] = Find(f[x]);
}

int main()
{
	ios::sync_with_stdio(false);
	int n, d;
	cin >> n >> d;
	for (int i = 1; i <= n; i++)
	{
		cin >> x[i] >> y[i];
		for (int j = 1; j < i; j++)
			if (dcmp(dist(i, j) - d) <= 0) G[i][j] = G[j][i] = 1;
	}
	
	for (int i = 1; i <= n; i++) f[i] = i;	
	char op; int v, u;
	while (cin >> op)
	{
		if (op == 'O')
		{
			cin >> v; w[v] = 1;
			for (int u = 1; u <= n; u++)
				if (G[v][u] && w[u]) f[Find(u)] = Find(v);
		}
		else {
			cin >> v >> u;
			cout << (Find(v) == Find(u) ? "SUCCESS" : "FAIL") << endl;
		}
	}
	
	return 0;
}

