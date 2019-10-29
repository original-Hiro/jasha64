#include <iostream>
#include <cstdio>
#include <cctype>
#include <algorithm>
using namespace std;

//read
int Read()
{
  int r = 0;
  char c = getchar();
  while (!isdigit(c)) c = getchar();
  while (isdigit(c)) {r = r*10 + c-'0'; c = getchar();}
  return r;
}

//graph
const int N = 500007;
int Head[N], Next[N+N], t[N+N], top = 2;
inline void AddEdge(int S, int T)
{
  t[top] = T;
  Next[top] = Head[S]; Head[S] = top; top++;
}

//tree
int fa[N], dep[N];
void DFS(int u)
{
  for (int i = Head[u]; i; i = Next[i]) {
    int v = t[i];
    if (v == fa[u]) continue;
    fa[v] = u; dep[v] = dep[u]+1; DFS(v);
  }
}
void Make_Tree(int r) {fa[r] = 0; dep[r] = 0; DFS(r);}

int main()
{
  int n;
  cin >> n;
  for (int i = 0, a, b; i < n-1; i++) {
    a = Read(); b = Read();
    AddEdge(a, b); AddEdge(b, a);
  }

  Make_Tree(n);
  int r = 1;
  for (int i = 2; i <= n; i++)
    if (dep[i] > dep[r]) r = i;
  Make_Tree(r);
  int maxlen = dep[1];
  for (int i = 2; i <= n; i++) maxlen = max(maxlen, dep[i]);
  maxlen--;
  int Res = 0;
  while (maxlen > 0) {maxlen /= 2; Res++;}
  cout << Res << endl;

  return 0;
}

