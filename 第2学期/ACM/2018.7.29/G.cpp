#include <iostream>
#include <algorithm>
using namespace std;

const int N = 107;
int a[N], s[N], f[N][N]; //speed
inline void Tension(int& a, int b) {if (a < b) a = b;}

int main()
{
  int n;
  cin >> n >> s[0];
  for (int i = 1; i <= n; i++) s[i] = s[i-1] * 2 / 3;
  for (int i = 1; i <= n; i++) cin >> a[i];

  f[1][1] = min(s[0], a[1]);
  for (int i = 1; i < n; i++)
    for (int k = 0; k <= i; k++)
    {
      Tension(f[i+1][k>0 ? k-1 : 0], f[i][k]);
	  Tension(f[i+1][k+1], f[i][k] + min(s[k], a[i+1]));
      if (i < n-1) Tension(f[i+2][0], f[i][k]);
  	}

  cout << *max_element(f[n], f[n]+n+1) << endl;
  return 0;
}

