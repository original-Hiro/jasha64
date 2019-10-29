#include <iostream>
#include <cstdio>
#include <cctype>
#include <ctime>
#include <cstdlib>
#include <cstring>
using namespace std;

inline long long Read()
{
  long long r = 0;
  char c = getchar();
  while (!isdigit(c)) c = getchar();
  while (isdigit(c)) {r = r*10 + c-'0'; c = getchar();}
  return r;
}

const int N = 1001, MOD = 1000000007;
int n;
long long a[N][N], b[N][N], c[N][N], d[N]; //d是一个随机的行向量 

bool Test()
{
  for (int i = 1; i <= n; i++) d[i] = rand() % MOD;
  long long e[N] = {}, f[N] = {};
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++) e[i] = (e[i] + d[j] * a[j][i]) % MOD; //D*A
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++) f[i] = (f[i] + d[j] * c[j][i]) % MOD; //D*C
  for (int i = 1; i <= n; i++) {
    long long cache = 0;
    for (int j = 1; j <= n; j++) cache = (cache + e[j] * b[j][i]) % MOD; //D*A*B
    if (cache != f[i]) return false;
  }
  return true;
}

int main()
{
  cin >> n;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++) a[i][j] = Read();
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++) b[i][j] = Read();
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++) c[i][j] = Read();

  srand(time(NULL));
  if (Test() && Test()) cout << "YES" << endl;
  else cout << "NO" << endl;

  return 0;
}

