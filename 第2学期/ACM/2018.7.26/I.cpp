#include <iostream>
#include <cstdio>
#include <cctype>
#include <algorithm>
#include <cstdlib>
using namespace std;

const int N = 1000007;
int a[N], b[N];

int Read() //may be negative
{
  int r = 0;
  bool isNeg = 0;
  char c = getchar();
  while (!isdigit(c) && c != '-') c = getchar();
  if (c == '-') {isNeg = 1; c = getchar();}
  while (isdigit(c)) {r = r*10 + c-'0'; c = getchar();}
  return isNeg ? -r : r;
}

int main()
{
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) a[i] = Read();

  for (int i = 0; i < n-1; i++)
    b[i] = (long long)a[i] * a[i+1] < 0 ? min(abs(a[i]), abs(a[i+1])) : 0;
  int p1 = -1, p2 = -1;
  for (int i = 0; i < n-1; i++) {
    if (p1 == -1 || b[i] > b[p1]) {p2 = p1; p1 = i;}
    else if (p2 == -1 || b[i] > b[p2]) p2 = i;
  }

  long long Res = 0;
  for (int i = 0; i < n-1; i++) {
    Res += abs(a[i+1] - a[i]);
    if (i == p1 || i == p2) Res -= 2*b[i];
  }
  cout << Res << endl;

  return 0;
}

