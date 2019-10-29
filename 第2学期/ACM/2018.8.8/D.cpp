#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cctype>
#include <algorithm>
using namespace std;

inline int Read()
{
  int r = 0;
  char c = getchar();
  while (!isdigit(c)) c = getchar();
  while (isdigit(c)) {r = r*10 + c-'0'; c = getchar();}
  return r;
}

const int N = 100001;

struct _
{
  double S, R;
  friend bool operator < (const _& a, const _& b)
  {
    return a.S < b.S || (a.S == b.S && a.R > b.R);
  }
} a[N];
int u[N];

int main()
{
  int d, n;
  cin >> d >> n;
  for (int i = 1, s, p, r; i <= n; i++) {
    s = Read(); p = Read(); r = Read();
    a[i].S = s*p; a[i].R = s*r;
  }
  
  sort(a+1, a+n+1);
  for (int i = 1, Prev = 0, t = 0; i <= n; i++)
    if (a[i].R > Prev) {
      Prev = a[i].R;
      u[++t] = i;
    }
  double Res = 0, now = 0;
  for (int i = t; i >= 1; i--) {
    now += (a[u[i]].R - a[u[i-1]].R) / a[u[i]].S;
    if (now >= d) {Res = a[u[i-1]].R + (now-d) * a[u[i]].S; break;}
  }

  cout << setiosflags(ios::fixed) << setprecision(7) << Res << endl;
  return 0;
}

