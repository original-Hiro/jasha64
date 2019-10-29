#include <iostream>
#include <algorithm>
using namespace std;

const int N = 1007;
int a[N];

int main()
{
  ios::sync_with_stdio(false);

  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    reverse(a, a+n);
    for (int i = 0, c; i < n; i++) {cin >> c; a[i] += c;}
    cout << *max_element(a, a+n) << endl;
  }

  return 0;
}

