#include <iostream>
#include <string>
using namespace std;

const int N = 200007;
int love[N], cnt[N];
string s[N];

int main()
{
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> s[i];

  int m;
  cin >> m;
  for (int i = 0, a, b; i < m; i++) {
    cin >> a >> b;
    if (!love[b]) {love[a] = b; cnt[a] = 1;}
    else {love[a] = love[b]; cnt[a] = cnt[b] + 1;}
  }

  if (!love[1]) cout << s[1] << endl;
  else {
    for (int i = 0; i < cnt[1]; i++) cout << "I_love_";
    cout << s[love[1]] << endl;
  }

  return 0;
}

