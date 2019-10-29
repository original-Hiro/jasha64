#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
 
const int MAXL = 1000010, SIGMA_SIZE = 26;
char str[MAXL], str2[MAXL];
vector<int> pos[SIGMA_SIZE];
inline int Todigit(char c) {return c - 'a';}
 
int main()
{
    int T;
    cin >> T;
    while (T--) {
    for (int i = 0; i < SIGMA_SIZE; i++) pos[i].clear();
    int n;
    cin >> n;
    memset(str, 0, sizeof(str));
    while (n--)
    {
        scanf("%s", str2);
        int len = strlen(str), len2 = strlen(str2), cur = 0;
        int i, ch;
        for (i = 0; i < len2; i++) {
        ch = Todigit(str2[i]);
        vector<int>::iterator I = lower_bound(pos[ch].begin(), pos[ch].end(), cur);
        if (I == pos[ch].end()) break;
        cur = (*I) + 1;
        }
        strcat(str + len, str2 + i);
        for (int j = i; j < len2; j++) {
        ch = Todigit(str2[j]);
        pos[ch].push_back(len + j - i);
        }
    }
    printf("%s\n", str);
    }
 
    return 0;
}

