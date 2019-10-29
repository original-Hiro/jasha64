#include <iostream>
using namespace std;

const int N = 100007;
int a[N], mx[N];

int main()
{
  ios::sync_with_stdio(false);

  int tot = 0, n, d;
  cin >> n >> d;
  for (int i = 1; i <= n; i++) {
    cin >> a[i]; tot += a[i];
    if (tot > d) {cout << -1 << endl; return 0;}
  }
  
  mx[n+1] = 1 + 1e9;
  for (int i = n; i > 0; i--) {
    mx[i] = min(mx[i+1], d-tot);
    tot -= a[i];
  }
  int day = 0, dep = 0;
  for (int i = 1; i <= n; i++) {
    tot += a[i];
    if (a[i] == 0 && tot + dep < 0) {
      dep = mx[i]; day++;
      if (tot + dep < 0) {cout << -1 << endl; return 0;}
    }
  }
  cout << day << endl;

  return 0;
}

