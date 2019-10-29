#include <cstdio>
#include <algorithm>
#include <complex>
#include <cmath>
using namespace std;

typedef complex<double> CD;
const double PI = acos(-1), eps = 1e-8;
const int N = 262147;
CD a[N], b[N];
double c[N];

inline void FFT(CD* a, int n, bool inv)
{
  for (int i = 0, j = 0; i < n; i++) {
    if (j > i) swap(a[i], a[j]);
    int k = n;
    while (j & (k >>= 1)) j &= ~k;
    j |= k;
  }

  for (int i = 1; i < n; i <<= 1) {
      const double alpha = (inv ? -PI : PI) / i;
      for (int k = 0; k < i; k++) {
	const CD omegak = exp(CD(0, alpha * k));
	for (int k1 = k; k1 < n; k1 += i << 1) {
	  int k2 = k1 + i;
	  const CD t = omegak * a[k2];
	  a[k2] = a[k1] - t;
	  a[k1] += t;
	}
      }
  }
	 
  if (inv)
    for (int i = 0; i < n; i++) a[i] /= n;
}

int main()
{
  int n, m;

  scanf("%d%d", &n, &m); ++n; ++m;
  for (int i = 0; i < n; i++) {scanf("%lf", &c[i]); a[i] = CD(c[i], 0);}
  for (int i = 0; i < m; i++) {scanf("%lf", &c[i]); b[i] = CD(c[i], 0);}

  int k = 2;
  while (k < n + m) k <<= 1;
  FFT(a, k, false);
  FFT(b, k, false);
  for (int i = 0; i < k; i++) a[i] *= b[i];
  FFT(a, k, true);

  for (int i = 0; i < n + m - 1; i++) printf("%.0lf\n", fabs(c[i] = a[i].real()) < eps ? 0 : c[i]);

  return 0;
}
