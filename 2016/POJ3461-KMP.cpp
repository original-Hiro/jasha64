#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int N = 1000007, M = 10007;
int f[N];
char a[M], b[N];

void GetNext()
{
  int i, j, n = strlen(b + 1);
  f[1] = f[2] = 1;
  for (i = 2; i <= n; ++i)
    {
      j = f[i];
      while (j != 1 && b[j] != b[i]) j = f[j];
      f[i + 1] = b[i] == b[j] ? j + 1 : 1;
    }
}
int Find()
{
  int i, j = 1, m = strlen(a + 1), n = strlen(b + 1), Ans = 0;
  for (i = 1; i <= n; ++i)
    {
      while (j != 1 && a[j] != b[i]) j = f[j];
      if (a[j] == b[i]) ++j;
      if (j == m + 1) {++Ans; j = f[j];}
    }
  cout << Ans << endl;
}

int main()
{
  int n;

  cin >> n;
  while (n--)
    {
      memset(f, 0, sizeof(f));
      memset(a, 0, sizeof(a));
      memset(b, 0, sizeof(b));

      scanf(" %s", a + 1);
      scanf(" %s", b + 1);

      GetNext();
      Find();
    }

  return 0;
}
