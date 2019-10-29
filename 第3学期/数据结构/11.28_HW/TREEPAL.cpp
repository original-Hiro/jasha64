//SPOJ - tree and palindrome
//数学推导：易见点对总数为C(n, 2)，符合条件的点对数目为sum{C(m, 2) | m为处于同一深度的节点数目} 
#include <iostream>
#include <algorithm>
#include <cctype>
#include <cstring>
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
int to[N+N], Head[N], Next[N+N];
inline void AddEdge(int v, int u, int j) {to[j] = u; Next[j] = Head[v]; Head[v] = j;}
int dcnt[N];
void DFS(int v, int fa, int dep)
{
	dcnt[dep]++;
	for (int i = Head[v]; i != 0; i = Next[i])
	{
		int u = to[i];
		if (u == fa) continue;
		DFS(u, v, dep+1);
	}
}
void Make_Tree(int v) {DFS(1, 0, 0);}
inline long long C2(long long n) {return n < 2 ? 0 : n * (n-1) / 2;} //组合数C(n, 2)
long long gcd(long long a, long long b) {return b == 0 ? a : gcd(b, a % b);}

int main()
{
	int n;
	while (cin >> n)
	{
		memset(Head, 0, sizeof(Head)); memset(dcnt, 0, sizeof(dcnt));
		for (int i = 1, j = 2, v, u; i < n; i++) {v = Read(); u = Read(); AddEdge(v, u, j++); AddEdge(u, v, j++);}
		Make_Tree(1);
		
		long long fz = 0, fm = 0;
		for (int i = 0; i < N; i++) fz += C2(dcnt[i]);
		fm = C2(n);
		//输出既约分数：除以最大公约数即可 
		long long g = gcd(fz, fm);
		cout << fz / g << '/' << fm / g << endl;
	}
	
	return 0;
}

