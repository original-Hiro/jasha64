#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;
const int N = 2000007, M = 640007, Q = 10007;
struct Comm
{
  int no, x, y, v, q, type;
  Comm(int a = 0, int b = 0, int c = 0, int d = 0, int e = 0, int f = 0) {no = a; x = b; y = c; v = d; q = e; type = f;}
  friend bool operator < (const Comm& a, const Comm& b) {return a.x < b.x;}
} op[M], t[M];
ll Ans[Q], BIT[N];
int no, n;

inline int Lowbit(int x) {return x & -x;}
inline ll BIT_Query(int x) {ll Ret = 0; for (; x; x -= Lowbit(x)) Ret += BIT[x]; return Ret;}
inline void BIT_Modify(int x, int v) {for (; x <= n; x += Lowbit(x)) BIT[x] += v;}
void Solve(int l, int r)
{
  if (l == r) return;

  int m = (l + r) >> 1;
  int s1 = l - 1, s2 = m;
  for (int i = l; i <= r; i++) t[op[i].no <= m ? ++s1 : ++s2] = op[i];
  copy(t + l, t + r + 1, op + l);

  int now = l;
  for (int i = m + 1; i <= r; i++)
    if (op[i].type == 2) {
      while (op[now].x <= op[i].x && now <= m) {
	if (op[now].type == 1) BIT_Modify(op[now].y, op[now].v);
	++now;
      }
      Ans[op[i].q] += op[i].v * BIT_Query(op[i].y);
    }

  while (now > l)
    if (op[--now].type == 1) BIT_Modify(op[now].y, -op[now].v);

  Solve(l, m); Solve(m + 1, r);
}

int main()
{
  ios::sync_with_stdio(false);

  int type, x, y, x2, y2, v, q = 0;

  cin >> n;
  while (true) {
    cin >> type;
    if (type == 3) break;
    else if (type == 1) {
      cin >> x >> y >> v;
      ++no; op[no] = Comm(no, x, y, v, q, 1);
    }
    else {
      cin >> x >> y >> x2 >> y2;
      ++q;
      ++no; op[no] = Comm(no, x - 1, y - 1, 1, q, 2);
      ++no; op[no] = Comm(no, x2, y2, 1, q, 2);
      ++no; op[no] = Comm(no, x - 1, y2, -1, q, 2);
      ++no; op[no] = Comm(no, x2, y - 1, -1, q, 2);
    }
  }

  sort(op + 1, op + no + 1);
  Solve(1, no);

  for (int i = 1; i <= q; i++) cout << Ans[i] << endl;

  return 0;
}
