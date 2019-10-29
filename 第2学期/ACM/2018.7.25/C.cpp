#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int N = 100007;
char a[N], b[N];

int main()
{
  int T;
  cin >> T;
  while (T--) {
    scanf("%s", a);
    scanf("%s", b);
    int l = strlen(a);

    bool Sol = 1;
    for (int i = 0; i <= l/2; i++)
      if (!((a[i] == b[i] && a[l-i-1] == b[l-i-1]) || (a[i] == b[l-i-1] && a[l-i-1] == b[i]))) {Sol = 0; break;}
    if (!Sol) {cout << -1 << endl; continue;}

    int Res = 0;
    bool sw = 0;
    for (int i = 0; i < l/2; i++)
      if ((sw == 0 && a[i] != b[i]) || (sw == 1 && a[i] == b[i] && a[i] != b[l-i-1])) {++Res; sw = !sw;}
    cout << Res << endl;
  }

  return 0;
}

