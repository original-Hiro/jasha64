#include <iostream>
#include <cstdio>
using namespace std;

const int N = 100007, MOD = 1000000007;
int a[N], b[N], c[N]; //b:前缀积 c:后缀积 

inline int Read()
{
  int r = 0;
  char c = getchar();
  while (!isdigit(c)) c = getchar();
  while (isdigit(c)) {r = r * 10 + c - '0'; c = getchar();}
  return r;
}

int main()
{
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) a[i] = Read();
    b[0] = 1;
    for (int i = 1; i <= n; i++) b[i] = (long long)b[i-1] * a[i] % MOD;
    c[n+1] = 1;
    for (int i = n; i >= 1; i--) c[i] = (long long)c[i+1] * a[i] % MOD;

    int Res = 0;
    for (int i = 1; i <= n; i++)
      Res = (Res + (long long)b[i-1] * (a[i]-1) % MOD * c[i+1] % MOD) % MOD;
    cout << Res << endl;
  }

  return 0;
}

