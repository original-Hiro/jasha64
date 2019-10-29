#include <cstdio>
#include <algorithm>
using namespace std;

const int N = 50007;
struct OP {int s, l, r, q, v;} op[N], t[N];
int n, Q, Res[N];

inline int Lowbit(int x) {return x & -x;}
struct BIT
{
  int a[N], c[N];

  void Modify(int* a, int x, int v) {for (; x <= n; x += Lowbit(x)) a[x] += v;}
  void Add(int l, int r, int v) {Modify(a, l, v); Modify(a, r + 1, -v); Modify(c, l, v * l); Modify(c, r + 1, -v * (r + 1));}
  int Get_Sum(int* a, int x) {int Ret = 0; for (; x > 0; x -= Lowbit(x)) Ret += a[x]; return Ret;}
  int Sum(int l, int r) {return Get_Sum(a, r) * (r + 1) - Get_Sum(c, r) - Get_Sum(a, l - 1) * l + Get_Sum(c, l - 1);}
} B;

void Solve(int ql, int qr, int l, int r)
{
  if (ql > qr) return;
  if (l == r) {
    for (int i = ql; i <= qr; i++)
      if (op[i].s == 2) Res[op[i].q] = l;
    return;
  }

  int m = (l + r) >> 1, l1 = ql, l2 = qr;
  for (int i = ql; i <= qr; i++) {
    if (op[i].s == 1) 
      if (op[i].v <= m) t[l1++] = op[i];
      else {
		t[l2--] = op[i];
		B.Add(op[i].l, op[i].r, 1);
      }
    else {
      int Cnt = B.Sum(op[i].l, op[i].r);
      if (Cnt < op[i].v) {
		op[i].v -= Cnt;
		t[l1++] = op[i];
      }
      else t[l2--] = op[i];
    }
  }
  reverse(t + l2 + 1, t + qr + 1);

  for (int i = ql; i <= qr; i++) {
    op[i] = t[i];
    if (op[i].s == 1 && op[i].v > m) B.Add(op[i].l, op[i].r, -1);
  }

  Solve(ql, l1 - 1, l, m); Solve(l1, qr, m + 1, r);
}

int main()
{
  int m;

  scanf("%d%d", &n, &m);
  for (int i = 1; i <= m; i++) {
    scanf("%d%d%d%d", &op[i].s, &op[i].l, &op[i].r, &op[i].v);
    if (op[i].s == 2) op[i].q = ++Q;
  }

  Solve(1, m, 1, n);

  for (int i = 1; i <= Q; i++) printf("%d\n", Res[i]);

  return 0;
}

