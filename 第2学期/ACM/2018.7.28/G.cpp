#include <iostream>
#include <cstdio>
#include <cctype>
using namespace std;

inline int Read()
{
  int r = 0;
  char c = getchar();
  while (!isdigit(c)) c = getchar();
  while (isdigit(c)) {r = r*10 + c-'0'; c = getchar();}
  return r;
}

const int N = 1001;
int a[N][N];
int x[4], y[4];
inline void Assign(int a, int b) {x[a] = x[b]; y[a] = y[b];}
inline void Assign(int a, int X, int Y) {x[a] = X; y[a] = Y;}
inline void Print(int x, int y) {cout << x << ' ' << y << endl;}

int main()
{
  int n, m;
  cin >> n >> m;
  int& x1 = x[1]; int& x2 = x[2]; int& x3 = x[3];
  int& y1 = y[1]; int& y2 = y[2]; int& y3 = y[3]; //top 3 in the field
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) {
      a[i][j] = Read();
      if (x1 == 0 || a[i][j] > a[x1][y1]) {
	Assign(3, 2); Assign(2, 1); Assign(1, i, j);
      }
      else if (x2 == 0 || a[i][j] > a[x2][y2]) {Assign(3, 2); Assign(2, i, j);}
      else if (x3 == 0 || a[i][j] > a[x3][y3]) Assign(3, i, j);
    }

  if (x1 != x2 && y1 != y2) {
    if (x3 == x1 || y3 == y2) Print(x1, y2);
    else Print(x2, y1);
  }
  else if (x1 == x2) {
    if (x3 == x1) {
      x3 = y3 = 0;
      for (int i = 1; i <= n; i++)
	for (int j = 1; j <= m; j++) {
	  if (i == x1) continue;
	  if (x3 == 0 || a[i][j] > a[x3][y3]) Assign(3, i, j);
	}
    }
    Print(x1, y3);
  }
  else {
    if (y3 == y1) {
      x3 = y3 = 0;
      for (int i = 1; i <= n; i++)
	for (int j = 1; j <= m; j++) {
	  if (j == y1) continue;
	  if (x3 == 0 || a[i][j] > a[x3][y3]) Assign(3, i, j);
	}
    }
    Print(x3, y1);
  }

  return 0;
}

