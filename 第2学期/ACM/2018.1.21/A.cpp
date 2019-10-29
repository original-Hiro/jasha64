#include <iostream>
using namespace std;

const int p[4][4] = {{}, {0, 0, 3, 2}, {0, 3, 0, 1}, {0, 2, 1, 0}};

int main()
{
  int n, w = 3, c;

  cin >> n;
  while (n--) {
    cin >> c;
    if (c == w) {cout << "NO" << endl; return 0;}
    w = p[w][c];
  }
  cout << "YES" << endl;

  return 0;
}

