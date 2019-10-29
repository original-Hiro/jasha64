#include <iostream>
#include <stack>
#include <string>
#include <sstream>
using namespace std;

int n;
stack<int> his;
inline void Fix(int& p)
{
  p %= n;
  if (p < 0) p += n;
}

int main()
{
  int k;
  cin >> n >> k;

  his.push(0);
  istringstream ss;
  while (k--) {
    string s;
    cin >> s;
    if (s == "undo") {
      int m;
      cin >> m;
      while (m--) his.pop();
    }
    else {
      int p;
      ss.str(s);
      ss >> p;
      ss.clear();

      Fix(p);
      his.push((his.top() + p) % n);
    }
  }

  cout << his.top() << endl;

  return 0;
}

