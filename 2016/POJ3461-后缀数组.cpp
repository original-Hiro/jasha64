#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

const int N = 1000007, MINC = 'A', MAXC = 'Z' + 1;
int l1, l2, sa[N], t[N], t2[N], c[N];
char s1[10007], s2[N];

inline int Suffix_Cmp(int x) {return strncmp(s1, s2 + sa[x], l1);}
int Find()
{
  if (Suffix_Cmp(0) < 0 || Suffix_Cmp(l2 - 1) > 0) return 0;
  int l, r, m, Ret;
  l = 0; r = l2 - 1;
  while (l < r)
    if (Suffix_Cmp(m = (l + r) >> 1) <= 0) r = m;
    else l = m + 1;
  Ret = l; l = 0; r = l2 - 1;
  while (l < r)
    if (Suffix_Cmp(m = (l + r) >> 1) >= 0) l = m + 1;
    else r = m;
  Ret = l - Ret;
  return Ret;
}
void Build_SA(int m)
{
  int i, *x = t, *y = t2;	
  memset(c, 0, sizeof(c));
  for (i = 0; i < l2; i++) ++c[x[i] = s2[i]];
  for (i = MINC + 1; i < m; i++) c[i] += c[i - 1];
  for (i = l2 - 1; i >= 0; i--) sa[--c[x[i]]] = i;
  for (int k = 1; k <= l2; k <<= 1)
    {
      int p = 0;
      for (i = l2 - k; i < l2; i++) y[p++] = i;
      for (i = 0; i < l2; i++)
	if (sa[i] >= k) y[p++] = sa[i] - k;
      memset(c, 0, sizeof(c));
      for (i = 0; i < l2; i++) ++c[x[y[i]]];
      for (i = 1; i < m; i++) c[i] += c[i - 1];
      for (i = l2 - 1; i >= 0; i--) sa[--c[x[y[i]]]] = y[i];
      swap(x, y);
      p = 1; x[sa[0]] = 0;
      for (i = 1; i < l2; i++) x[sa[i]] = (y[sa[i - 1]] == y[sa[i]] && y[sa[i - 1] + k] == y[sa[i] + k] ? p - 1 : p++);
      if (p >= l2) break;
      m = p;
    }
}


int main()
{
  int n;
	
  cin >> n;
  while (n--)
    {
      scanf("%s", s1); scanf("%s", s2);
      l1 = strlen(s1); l2 = strlen(s2);
		
      Build_SA(MAXC);
		
      cout << Find() << endl;
    }
	
  return 0;
}
