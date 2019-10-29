#include <iostream>
#include <cstdio>
#include <cstring>
#include <map>
#include <vector>
using namespace std;

char c[27];
int a[27], t;
map<char, int> m;

int len;
bool G[11][11], in[11], vis[11];
inline void AddEdge(int s, int t) {G[s][t] = 1;}
int DFS(int u, int dep) //1: dep < t 0: success -1: has loop
{
  vis[u] = 1;
  bool suc = (dep == t);
  for (int v = 1; v <= 10; v++)
    if (G[u][v]) {
      if (vis[v]) return -1;
      int r = DFS(v, dep+1);
      if (r == -1) return -1;
      else if (r == 0) suc = 1;
    }
  vis[u] = 0;
  return !suc;
}
bool Check()
{
  memset(G, 0, sizeof(G)); memset(in, 0, sizeof(in));
  for (int i = 0; i < len-1; i++)
    if (a[i] == 0) {AddEdge(m[c[i]], m[c[i+1]]); in[m[c[i+1]]] = 1;}
    else if (a[i] == 1) {AddEdge(m[c[i+1]], m[c[i]]); in[m[c[i]]] = 1;}

  memset(vis, 0, sizeof(vis));
  for (int i = 1; i <= t; i++)
    if (in[i] == 0) return DFS(i, 1) == 0;
  return false;
}
bool Search(int Cur)
{
  if (Cur == len-1) return Check();
  if (c[Cur] == c[Cur+1]) {a[Cur] = 2; return Search(Cur+1);}

  a[Cur] = 0;
  if (Search(Cur+1)) return true;
  a[Cur] = 1;
  return Search(Cur+1);
}

int main()
{
  scanf("%s", c);
  len = strlen(c);
  t = 0;
  for (int i = 0; i < len; i++)
    if (m.find(c[i]) == m.end()) m[c[i]] = ++t;

  if (!Search(0)) cout << "Impossible" << endl;
  else {
    for (int i = 0; i < len-1; i++) {
      cout << c[i] << ' ';
      if (a[i] == 0) cout << '<';
      else if (a[i] == 1) cout << '>';
      else cout << '=';
      cout << ' ';
    }
    cout << c[len-1] << endl;
  }

  return 0;
}

