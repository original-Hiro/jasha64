#include <iostream>
#include <algorithm>
using namespace std;

int main()
{

  int T;
  cin >> T;
  while (T--) {
    int n, m;
    cin >> n >> m;
    if (n < m) swap(n, m);

    int c1 = (n+1)/2, c2 = n/2+1;
    long long Res = m/2 * (long long)(c1+c2) + m%2 * c1;
    cout << Res << endl;
  }

  return 0;
}

