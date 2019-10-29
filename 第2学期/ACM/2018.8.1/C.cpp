#include <cstdio>
#include <cctype>
#include <cstring>
#include <stack>
using namespace std;

inline int Read()
{
  int r = 0;
  char c = getchar();
  while (!isdigit(c)) c = getchar();
  while (isdigit(c)) {r = r*10 + c-'0'; c = getchar();}
  return r;
}

const int N = 100007; //max of edges
int s[N], t[N], Next[N], Head[N], Top;
inline void AddEdge(int S, int T)
{
  s[Top] = S; t[Top] = T;
  Next[Top] = Head[S]; Head[S] = Top;
  Top++;
}
bool sgn[N]; //signed edge

int tim, DFN[N], Low[N], lb[N], fb[N]; //Low的定义：节点及其后代所能连接回祖先的DFN的最小值 
bool ins[N];
stack<int> st;
int sccno[N];
void Tarjan(int u)
{
  DFN[u] = Low[u] = ++tim;
  st.push(u); ins[u] = 1;
  for (int i = Head[u]; i; i = Next[i]) {
    int v = t[i];
    if (!DFN[v]) {
      fb[v] = i; Tarjan(v);
      if (Low[v] < Low[u]) {Low[u] = Low[v]; lb[u] = i;}
    }
    else if (ins[v] && DFN[v] < Low[u]) {Low[u] = DFN[v]; lb[u] = i;}
  }
  if (Low[u] == DFN[u]) {
    int v;
    do {
      v = st.top(); st.pop();
      ins[v] = 0; sccno[v] = u;
      sgn[fb[v]] = sgn[lb[v]] = 1;
    } while (v != u);
  }
}

int main()
{
  int T;
  scanf("%d", &T);
  while (T--) {
    int n, m;
    scanf("%d%d", &n, &m);
    memset(Head, 0, sizeof(Head)); Top = 1;
    for (int i = 1, a, b; i <= m; i++) {
      a = Read(); b = Read();
      AddEdge(a, b);
    }

    memset(sgn, 0, sizeof(sgn));
    memset(lb, 0, sizeof(lb));
    tim = 0;
    memset(DFN, 0, sizeof(DFN));
    Tarjan(1);

    for (int i = 1; i <= m; i++)
      if (!sgn[i]) st.push(i);
    while (st.size() > m-n-n) st.pop();
    while (!st.empty()) {
      int u = s[st.top()], v = t[st.top()]; st.pop();
      printf("%d %d\n", u, v);
    }
  }

  return 0;
}

