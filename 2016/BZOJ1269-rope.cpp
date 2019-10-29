#include <iostream>
#include <cstdio>
#include <ext/rope>
using namespace std;

__gnu_cxx::rope<char> r, rr;
char s[2097157];

inline char Getchar()
{
  char Ret = getchar();
  while (!(32 <= Ret && Ret <= 126)) Ret = getchar();
  return Ret;
}
inline void Getstr(int len)
{
  for (int i = 0; i < len; i++) s[i] = Getchar();
  s[len] = 0;
}

int main()
{
  int q, a, p = 0, sz = 1;
  char cmd[7], c;
  cin >> q;
  while (q--) {
    scanf("%s", cmd);
    if (cmd[0] == 'M') scanf("%d", &p);
    else if (cmd[0] == 'I') {
      scanf("%d", &a);
      Getstr(a);
      r.insert(p, s);
      reverse(s, s + a);
      rr.insert(sz - p - 1, s);
      sz += a;
    }
    else if (cmd[0] == 'D') {
      scanf("%d", &a);
      r.erase(p, a);
      rr.erase(sz - p - a - 1, a);
      sz -= a;
    }
    else if (cmd[0] == 'R') {
      scanf("%d", &a);
      rr.insert(sz - p - 1, r.substr(p, a));
      r.erase(p, a);
      r.insert(p, rr.substr(sz - p - a - 1, a));
      rr.erase(sz - p - a - 1, a);
    }
    else if (cmd[0] == 'G') printf("%c\n", r[p]);
    else if (cmd[0] == 'P') --p;
    else ++p;
  }
  
  return 0;
}
