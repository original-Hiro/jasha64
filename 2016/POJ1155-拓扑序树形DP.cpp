#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 3007, INF = 10000000;
int n, m, s[N], Head[N], f[N][N];
struct node {int t, c, Next;} e[N];

void DFS(int x)
{
  int i = Head[x];
  while (i)
    {
      int v = e[i].t;
      DFS(v);
      s[x] += s[v];
      for (int j = s[x]; j > 0; j--)
	for (int k = 1; k <= j && k <= s[v]; k++) f[x][j] = max(f[x][j], f[x][j - k] + f[v][k] - e[i].c);
	i = e[i].Next;
    }
}

int main()
{
  int t = 1;
  cin >> n >> m;
  for (int i = 1; i <= n - m; i++)
    {
      int k, a, b;
      cin >> k;
      while (k--)
	{
	  cin >> a >> b;
	  e[t].t = a; e[t].c = b;
	  e[t].Next = Head[i]; Head[i] = t++;
	}
    }
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) f[i][j] = -INF;
  for (int i = n - m + 1; i <= n; i++) {s[i] = 1; cin >> f[i][1];}

  DFS(1);

  for (int i = m; i >= 0; i--)
    if (f[1][i] >= 0) {cout << i << endl; break;}

  return 0;
}
