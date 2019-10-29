#include <iostream>
#include <algorithm>
using namespace std;

int a[100007], b[107], fa[100007];
bool f[100007];

int main()
{
  int n, w, Max = 0;
  cin >> w >> n;
  for (int i = 1; i <= n; i++) {cin >> b[i]; Max += b[i];}

  int Top = 0, t;
  f[a[++Top] = Max] = true;
  for (int i = 1; i <= n; i++)
    {
      t = Top;
      for (int j = 1; j <= t; j++)
	if (!f[a[j] - b[i]]) {f[a[++Top] = a[j] - b[i]] = true; fa[a[Top]] = i;}
	else if (a[j] - b[i] == w && f[a[j] - b[i]]) {cout << -1 << endl; return 0;}
    }

  if (!f[w]) cout << 0 << endl;
  else {
    int Tracker = w, o[107] = {0}; Top = 0;
    while (Tracker < Max)
      {
	o[Top++] = fa[Tracker];
	Tracker += b[fa[Tracker]];
      }
    sort(o, o + Top);
    cout << o[0];
    for (int i = 1; i < Top; i++) cout << ' ' << o[i];
    cout << endl;
  }

  return 0;
}
