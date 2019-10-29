#include <iostream>
#include <queue>
using namespace std;

const int N = 1007;
int a[N], uni;
queue<int> q;

int main()
{
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int p;
    cin >> p;
    if (p > 0) a[p]++;
    else if (p == 0) uni++;
    else {
      if (a[-p] > 0) --a[-p];
      else if (uni > 0) {--uni; q.push(-p);}
      else {cout << "No" << endl; return 0;}
    }
  }
  while (uni > 0) {q.push(1); uni--;}

  cout << "Yes" << endl;
  if (!q.empty()) {
    cout << q.front(); q.pop();
    while (!q.empty()) {cout << ' ' << q.front(); q.pop();}
    cout << endl;
  }
  return 0;
}

