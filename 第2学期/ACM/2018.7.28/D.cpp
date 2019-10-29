#include <iostream>
#include <cstdlib>
using namespace std;

const int N = 200007;
int a[N], b[N], l[N], r[N];
inline int Dist(int a, int b) {return abs(a-b);}

int main()
{
  ios::sync_with_stdio(false);

  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    if (i > 1 && a[i] == a[i-1]) {n--; i--;} //去重
  }
  for (int i = 1; i <= m; i++) cin >> b[i];

  for (int i = 1, j = 1; i <= m; i++) {
    while (j < n && Dist(b[i], a[j]) > Dist(b[i], a[j+1])) j++;
    int c = Dist(b[i], a[j]);
    if (b[i] < a[j]) l[j] = max(c, l[j]);
    else r[j] = max(c, r[j]);
  }
  //c表示b[i]到最近传送门的距离 
  //l[j]表示传送门j左边的在所有传送门中离它最近的财宝的距离的最大值 
  //r[j]表示......右边......最大值 

  long long Res = 2ll * l[1];
  for (int i = 2; i <= n; i++)
    Res += min(2ll * (r[i-1] + l[i]), (long long)a[i] - a[i-1]);
  Res += 2ll * r[n];
  cout << Res << endl;

  return 0;
}

