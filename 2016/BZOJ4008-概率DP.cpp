#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;

const int N = 227, R = 137;
int d[N];
double p[N], f[N][R], c[N][R];

int main()
{
  ios::sync_with_stdio(false);
  int T, n, r;

  cin >> T;
  while (T--) {
    cin >> n >> r;
    for (int i = 1; i <= n; i++) cin >> p[i] >> d[i];
    
    for (int i = 1; i <= n; i++) {
      c[i][0] = 1;
      for (int j = 1; j <= r; j++) c[i][j] = c[i][j - 1] * (1 - p[i]);
    }

    double Res = 0;
    fill(f[0], f[0] + N * R, 0);
    f[0][r] = 1;
    for (int i = 0; i < n; i++)
      for (int j = 0; j <= r; j++) {
	f[i + 1][j] += f[i][j] * c[i + 1][j];
	if (j) {
	  f[i + 1][j - 1] += f[i][j] * (1 - c[i + 1][j]);
	  Res += f[i][j] * (1 - c[i + 1][j]) * d[i + 1];
	}
    }
    cout << setiosflags(ios::fixed) << setprecision(10) << Res << endl;
  }

  return 0;
}
