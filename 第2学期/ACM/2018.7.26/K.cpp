#include <iostream>
using namespace std;

int main()
{
  ios::sync_with_stdio(false);
  int n, m, k;
  cin >> n >> m >> k;

  int Res = 4;
  if (n == 1 && m == 1) Res = 1;
  else if (n == 1 && m > 1) Res = 2;
  else if (n > 1 && m == 1) Res = 2;
  for (int i = 0, x, y; i < k; i++) {
    cin >> x >> y;
    if (x == 1 && y == 1) --Res;
    else if (x == n && y == m) --Res;
    else if (x == n && y == 1) --Res;
    else if (x == 1 && y == m) --Res;
  }
  cout << Res << endl;

  return 0;
}

