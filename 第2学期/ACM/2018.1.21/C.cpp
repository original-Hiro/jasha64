#include <iostream>
#include <algorithm>
using namespace std;

const int N = 100007;
int a[N], f[N];
bool s[N] = {};
int Find(int x)
{
  if (f[x] == x) return x;
  int v = Find(f[x]);
  a[v] = min(a[v], a[x]);
  f[x] = v;
  return f[x];
}

int main()
{
  ios::sync_with_stdio(false);

  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= n; i++) cin >> a[i];
  for (int i = 1; i <= n; i++) f[i] = i;
  for (int i = 0, c, b; i < m; i++) {
    cin >> c >> b;
    int v1 = Find(c), v2 = Find(b);
    f[v1] = v2; a[v2] = min(a[v2], a[v1]);
  }

  long long res = 0;
  for (int i = 1; i <= n; i++) {
    int v = Find(i);
    if (!s[v]) {
      s[v] = 1;
      res += a[v];
    }
  }
  cout << res << endl;

  return 0;
}

