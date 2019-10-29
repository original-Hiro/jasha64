#include <iostream>
#include <algorithm>
using namespace std;

const int N = 100007;
int a[N];

int main()
{
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> a[i];

  sort(a+1, a+n+1);
  long long Res = 0; //Res <= 100000 + 99999 + ... + 1 = 25000 * 49999 ~ 1e10
  for (int i = 1; i <= n; i++) {
    int c = min(n-i, a[i]-i);
    Res += max(c, 0);
  }
  cout << Res*2 << endl;

  return 0;
}

