#include <iostream>
#include <cstdio>
#include <cctype>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

inline int Read()
{
  int r = 0;
  char c = getchar();
  while (!isdigit(c)) c = getchar();
  while (isdigit(c)) {r = r*10 + c-'0'; c = getchar();}
  return r;
}

const int N = 1001;
int t[N+N], Next[N+N], Head[N], Top;
inline void AddEdge(int u, int v)
{
  t[Top] = v;
  Next[Top] = Head[u]; Head[u] = Top;
  Top++;
}

int n;
int fa[N], siz[N], mn;
vector<int> p; //possible roots
void DFS(int u)
{
  siz[u] = 1;
  for (int i = Head[u]; i; i = Next[i]) {
    int v = t[i];
    if (v == fa[u]) continue;
    fa[v] = u; DFS(v);
    siz[u] += siz[v];
  }
}
inline void Make_Tree(int r) {fa[r] = 0; DFS(r);}
void DFS2(int u)
{
  int mx = n - siz[u];
  for (int i = Head[u]; i; i = Next[i]) {
    int v = t[i];
    if (v == fa[u]) continue;
    mx = max(mx, siz[v]);
  }
  if (mx < mn) {mn = mx; p.clear(); p.push_back(u);}
  else if (mx == mn) p.push_back(u);
  for (int i = Head[u]; i; i = Next[i]) {
    int v = t[i];
    if (v == fa[u]) continue;
    DFS2(v);
  }
}
void Get_Root() {Make_Tree(1); mn = N; DFS2(1);}
bool Check(int u)
{
  int mx = 0;
  for (int i = Head[u]; i; i = Next[i]) {
    int v = t[i];
    if (v == fa[u]) continue;
    if (siz[v] > mx) mx = siz[v];
  }
  if (mx * 2 > siz[u]) return false;
  for (int i = Head[u]; i; i = Next[i]) {
    int v = t[i];
    if (v == fa[u]) continue;
    if (!Check(v)) return false;
  }
  return true;
}

int main()
{
  int T;
  cin >> T >> n;
  while (T--) {
    memset(Head, 0, sizeof(Head)); Top = 2;
    for (int i = 0, a, b; i < n-1; i++) {
      a = Read(); b = Read();
      AddEdge(a, b); AddEdge(b, a);
    }
		
    Get_Root();
    bool Sol = 0;
    for (int i = 0; i < p.size(); i++) {
      int u = p[i];
      Make_Tree(u);
      if (Check(u)) {cout << "Centroid" << endl; Sol = 1; break;}
    }
    if (!Sol) cout << "Random" << endl;
  }
	
  return 0;
}

