#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstdlib>
using namespace std;

const double eps = 0.01, delta = 0.9, pi = acos(-1);
const int N = 1007, m = 31;

inline double Dist(double x1, double y1, double x2, double y2) {return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));}

int main()
{
  int T;
  scanf("%d", &T);
  while (T--) {
    int x, y, n, a[N], b[N];
    scanf("%d%d%d", &x, &y, &n);
    for (int i = 0; i < n; i++) scanf("%d%d", &a[i], &b[i]);

    const double INF = hypot(x, y);
    double px[m], py[m], dm[m];
    fill(dm, dm + m, INF);
    for (int i = 0; i < m; i++) {
      px[i] = rand() / (double)RAND_MAX * x; py[i] = rand() / (double)RAND_MAX * y;
      for (int j = 0; j < n; j++) dm[i] = min(dm[i], Dist(px[i], py[i], a[j], b[j]));
    }
    double temp = max(x, y) / sqrt(n);
    while (temp > eps) {
      for (int i = 0; i < m; i++) {
	double sx = px[i], sy = py[i];
	for (int j = 0; j < m; j++) {
	  double theta = rand() / (double)RAND_MAX * 2 * pi;
	  double tx = sx + cos(theta) * temp, ty = sy + sin(theta) * temp, nm = INF;
	  if (tx < 0 || tx > x || ty < 0 || ty > y) continue;
	  for (int j = 0; j < n; j++) nm = min(nm, Dist(tx, ty, a[j], b[j]));
	  double dE = nm - dm[i];
	  if (dE >= 0) {px[i] = tx; py[i] = ty; dm[i] = nm;}
	}
      }
      temp *= delta;
    }

    int Res = 0;
    for (int i = 1; i < m; i++)
      if (dm[i] < Res) Res = i;
    printf("The safest point is (%.1lf, %.1lf).\n", px[Res], py[Res]);
  }

  return 0;
}
