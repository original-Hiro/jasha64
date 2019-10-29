#include <iostream>
using namespace std;

const int N = 100007;
int a[N+N], f[N];

int main()
{
  ios::sync_with_stdio(false);
  int n, r;
  cin >> n >> r;
  double r1 = 0;
  int u = n+n;
  for (int i = 0, x, y; i < r-1; i++) {
    cin >> x >> y;
    if (!a[x]) u--;
    if (!a[y]) u--;
    cin >> a[x] >> a[y]; f[a[x]]++; f[a[y]]++;
    if (a[x] == a[y]) r1 = max(r1, (double)a[x]);
  }

  double Res = 0;
  double r2 = 0;
  const double C = 2.0 / (u * (u-1)); //1 / C(n, 2)
  int Cnt = 0;
  for (int i = n; i > 0; i--)
    if (f[i] == 0) {
      r2 = i;
      Res += max(r1, r2) * C; Cnt++;
    }
  Res += r1 * (1 - Cnt*C);

  r2 = 0;
  const double U = 1.0 / u;
  for (int i = n; i > 0; i--)
    if (f[i] == 1) {r2 = i; break;}
  Res = max(Res, max(r1, r2) * U + r1 * (1-U));

  r2 = 0;
  for (int i = n; i > 0; i--)
    if (f[i] == 2) {r2 = i; break;}
  Res = max(Res, max(r1, r2));

  cout << Res << endl;
  return 0;
}

