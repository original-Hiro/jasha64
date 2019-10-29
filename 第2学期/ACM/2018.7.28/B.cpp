#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
  int a, b, c, n, m;
  cin >> a >> b >> c >> n >> m;

  long long Res = (long long)a+b+c; //a, b, c <= 1e9, a+b+c <= 3e9, ¼ÇµÃ¼Ó×¢(long long)
  if (a+c > n) Res = min(Res, (long long)n);
  if (b+c > m) Res = min(Res, (long long)m);
  cout << Res << endl;

  return 0;
}

