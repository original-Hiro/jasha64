#include <iostream>
#include <cstring>
using namespace std;

const int N = 1001, MOD = 7901;
int Cnt[N], Fac[N];

int main()
{
  Fac[0] = 1;
  for (int i = 1; i < N; i++) Fac[i] = Fac[i-1] * i % MOD;

  int T;
  cin >> T;
  while (T--) {
    memset(Cnt, 0, sizeof(Cnt));

    int n;
    cin >> n;
    for (int i = 0, c; i < n; i++) {cin >> c; Cnt[c]++;}

    int Res = 1;
    for (int i = 0; i < N; i++) Res = Res * Fac[Cnt[i]] % MOD;
    cout << Res << endl;
  }

  return 0;
}

