#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

const int N = 200007;
struct Player
{
  int no, kill;
  friend bool operator < (const Player& a, const Player& b) {return a.kill > b.kill;}
} a[N];
typedef pair<int, int> pii;
stack<pii> Printer;

int main()
{
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {cin >> a[i].kill; a[i].no = i;}
  sort(a+1, a+n+1);

  for (int i = 1, j = 2; i <= n; i++) {
    int c = 0; //kill count
    while (c < a[i].kill) {
      if (j > n) {cout << "NO" << endl; return 0;}
      Printer.push(pii(a[i].no, a[j].no));
      j++; c++;
    }
  }

  cout << "YES" << endl;
  while (!Printer.empty()) {
    pii c = Printer.top(); Printer.pop();
    cout << c.first << ' ' << c.second << endl;
  }
  return 0;
}

