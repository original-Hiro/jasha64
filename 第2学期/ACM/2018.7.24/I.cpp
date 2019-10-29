#include <iostream>
using namespace std;

int main()
{
  int T;
  cin >> T;
  while (T--) {
    int x, n;
    cin >> x >> n;
    if (x < n) {cout << -1 << endl; continue;} //×¢Òâ¶ÁÌâ 

    int k1 = x / n, k2 = x % n;
    for (int i = k2; i < n; i++) cout << k1 << ' ';
    if (k2 > 0) cout << k1+1;
    for (int i = 1; i < k2; i++) cout << ' ' << k1+1;
    cout << endl;
  }

  return 0;
}

