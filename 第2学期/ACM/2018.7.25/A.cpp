#include <iostream>
using namespace std;

int main()
{
  int T;
  cin >> T;
  while (T--) {
    long long a, b; 
    cin >> a >> b;
    if (a*a > 2*b*b) cout << 1 << endl; //a,b <= 1e8, a*a,b*b <= 1e16
    else cout << 2 << endl;
  }

  return 0;
}

