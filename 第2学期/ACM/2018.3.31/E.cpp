#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int N = 200007;
char s1[N], s2[N];

int main()
{
    scanf("%s", s1);
    scanf("%s", s2);

    int l = 0;
    while (s1[l] == s2[l]) l++;
    int h = strlen(s1)-1;
    while (s1[h] == s2[h]) h--;
    reverse(s1+l, s1+h+1);
    if (strcmp(s1, s2) == 0)  printf("YES\n");
    else printf("NO\n");
    
    return 0;
}
