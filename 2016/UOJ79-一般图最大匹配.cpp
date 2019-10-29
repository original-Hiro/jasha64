#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

const int N = 507;
struct Edge{int t, Next;} e[250007];
int n, Head[N], Next[N], b[N], Match[N], ResCnt, fa[N], Sign[N], vis[N], t;

int Find(int x) {return b[x] == x ? x : b[x] = Find(b[x]);}
inline void Unit(int a, int c) {if (Find(a) != Find(c)) b[Find(a)] = Find(c);}
int LCA(int a, int b)
{
  ++t;
  while (true) {
    if (a) {
      a = Find(a);
      if (vis[a] == t) return a;
      vis[a] = t;
      a = Next[Match[a]];
    }
    swap(a, b);
  }
}
inline void Contract(int v, int r, queue<int>& q)
{
  while (v != r) {
    int mv = Match[v], c = Next[mv];
    if (Find(c) != r) Next[c] = mv;
    Sign[mv] = 1; q.push(mv);
    Unit(v, c); Unit(mv, c);
    v = c;
  }
}
void Augment(int s)
{
  fill(Next + 1, Next + n + 1, 0);
  fill(Sign + 1, Sign + n + 1, 0);
  fill(vis + 1, vis + n + 1, 0);
  for (int i = 1; i <= n; i++) b[i] = i;

  queue<int> q;
  q.push(s); Sign[s] = 1;
  while (!q.empty()) {
    int v = q.front(); q.pop();
    for (int i = Head[v]; i; i = e[i].Next) {
      int x = e[i].t;
      if (Match[x] == v || Find(x) == Find(v) || Sign[x] == 2) continue;
      if (Sign[x] == 1) {
	int r = LCA(v, x);
	if (Find(v) != r) Next[v] = x;
	if (Find(x) != r) Next[x] = v;
	Contract(v, r, q); Contract(x, r, q);
      }
      else if (!Match[x]) {
	Next[x] = v;
	int a = x, b, mb;
	while (a) {
	  b = Next[a]; mb = Match[b];
	  Match[b] = a; Match[a] = b;
	  a = mb;
	}
	++ResCnt; return;
      }
      else {Next[x] = v; Sign[x] = 2; Sign[Match[x]] = 1; q.push(Match[x]);}
    }
  }
}

int main()
{
  ios::sync_with_stdio(false);

  int m;
  cin >> n >> m;
  for (int i = 0, j = 1, a, b; i < m; i++) {
    cin >> a >> b;
    e[j].t = b; e[j].Next = Head[a]; Head[a] = j++;
    e[j].t = a; e[j].Next = Head[b]; Head[b] = j++;
  }

  for (int i = 1; i <= n; i++)
    if (!Match[i]) Augment(i);

  cout << ResCnt << endl << Match[1];
  for (int i = 2; i <= n; i++) cout << ' ' << Match[i];
  cout << endl;

  return 0;
}
