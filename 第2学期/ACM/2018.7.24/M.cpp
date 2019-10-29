#include <iostream>
#include <cstring>
#include <cstdio>
#include <cctype>
using namespace std;

//读入优化，不能和关闭流同步同时使用 
inline int Read()
{
	int r = 0;
	char c = getchar();
	while (!isdigit(c)) c = getchar();
	while (isdigit(c)) {r = r*10 + c-'0'; c = getchar();}
	return r;
}

const int N = 100007, K = 17;
int n;

//make tree
int t[N+N], w[N+N], Head[N], Next[N+N], top;
inline void AddEdge(int S, int T, int W)
{
  t[top] = T; w[top] = W;
  Next[top] = Head[S]; Head[S] = top; top++;
}
int fa[N], dep[N], s1[N], s2[N]; //s1: 从根下行权值和 s2: 上行至根权值和 
void DFS(int u)
{
  for (int i = Head[u]; i; i = Next[i]) {
    int v = t[i];
    if (v == fa[u]) continue;
    s1[v] = s1[u] + w[i]; s2[v] = s2[u] + w[i^1];
    fa[v] = u; dep[v] = dep[u]+1; DFS(v);
  }
}
inline void Make_Tree() {dep[n] = 1; fa[n] = 0; s1[n] = s2[n] = 0; DFS(n);}

//queries
int f[N][K];
void Calc_Table()
{
  memset(f, 0, sizeof(f));
  for (int i = 1; i <= n; i++) f[i][0] = fa[i];
  for (int k = 1; (1<<k) < n; k++)
    for (int i = 1; i <= n; i++) f[i][k] = f[f[i][k-1]][k-1];
}
int LCA(int a, int b)
{
  if (dep[a] < dep[b]) swap(a, b);
  for (int k = K-1; k >= 0; k--)
    if (f[a][k] != 0 && dep[f[a][k]] >= dep[b]) a = f[a][k];
  if (a == b) return a;

  for (int k = K-1; k >= 0; k--)
    if (f[a][k] != f[b][k]) {a = f[a][k]; b = f[b][k];}
  return fa[a];
}

int main()
{
  int T;
  cin >> T;
  while (T--) {
    cin >> n;
    int SUM = 0;
    memset(Head, 0, sizeof(Head)); top = 2; //多笔测资中，调用AddEdge前务必检查这两项的初始化 
    for (int i = 0, u, v, c1, c2; i < n-1; i++)
	{
		u = Read(); v = Read(); c1 = Read(); c2 = Read();
		SUM += c1 + c2;
		AddEdge(u, v, c1); AddEdge(v, u, c2);
	}
    Make_Tree();

    Calc_Table();
    int q;
    cin >> q;
    while (q--) {
      int a, b;
      a = Read(); b = Read(); //T * q * 2 = 2e7
      int c = LCA(a, b);
      cout << SUM - s1[a] + s1[c] - s2[b] + s2[c] << endl;
    }
  }

  return 0;
}

