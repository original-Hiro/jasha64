#include <iostream>
using namespace std;

int l[3], r[3], p[3], d[3];
void Walk(int i)
{
  if ((p[i] == l[i] && d[i] == -1) || (p[i] == r[i] && d[i] == 1)) d[i] = -d[i];
  p[i] += d[i];
}

int main()
{
  int T;
  cin >> T;
  while (T--) {
    int k;
    cin >> l[1] >> r[1] >> p[1] >> d[1]; if (d[1] == 0) d[1] = -1;
    cin >> l[2] >> r[2] >> p[2] >> d[2]; if (d[2] == 0) d[2] = -1;
    cin >> k;

    int Res = 0; //given p1 != p2 initially
    while (k--) {
      Walk(1); Walk(2);
      if (p[1] == p[2]) Res++;
    }
    cout << Res << endl;
  }

  return 0;
}

