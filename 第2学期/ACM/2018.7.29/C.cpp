#include <cstdio>
#include <cstring>
using namespace std;

const int N = 15007;
char s[N];

int main()
{
  scanf("%s", s);
  int l = strlen(s) / 2;

  int r1 = 0;
  for (int i = 0; i < l; i++) r1 = (r1 + s[i] - 'A') % 26;
  for (int i = 0; i < l; i++) {
    s[i] += r1;
    if (s[i] > 'Z') s[i] -= 26;
  }
  int r2 = 0;
  for (int i = l; i < l+l; i++) r2 = (r2 + s[i] - 'A') % 26;
  for (int i = l; i < l+l; i++) {
    s[i] += r2;
    if (s[i] > 'Z') s[i] -= 26;
  }

  for (int i = 0; i < l; i++) {
    s[i] = s[i] + (s[i+l]-'A');
    if (s[i] > 'Z') s[i] -= 26;
  }

  s[l] = 0;
  printf("%s\n", s);

  return 0;
}

