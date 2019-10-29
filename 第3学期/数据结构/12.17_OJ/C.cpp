//DP
//容易发现，对于给定a, b, c的纸片，它一定能被唯一一个c+1的纸片覆盖，直接DP即可 
/*
受上周课程内容影响，很容易认为是DS题，然后就做不出来 
这也是没办法的事 
*/
#include <iostream>
#include <unordered_map>
using namespace std;

#define umap unordered_map
umap<int, umap<int, umap<int, int> > > f; //unordered_map三维数组 
#undef umap
inline int Query(int a, int b, int c) //查询f[a][b][c]，若不存在即创建f[a][b][c]并返回0 
{
	if (f[a][b].count(c) == 0) f[a][b][c] = 0;
	return f[a][b][c];
}
inline void Add(int a, int b, int c) {Query(a, b, c); f[a][b][c]++;} //给f[a][b][c]加一，若不存在即创建f[a][b][c]并赋值为1 

int main()
{
	ios::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	for (int i = 0, a, b, c; i < m; i++)
	{
		cin >> a >> b >> c;
		cout << Query(a, b, c) << endl;
		Add(a, b, c);
		while (c < n) Add(a /= 2, b /= 2, ++c);
	}
	
	return 0;
}

