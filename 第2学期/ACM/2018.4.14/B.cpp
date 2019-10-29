#include <cstdio>
#include <cstring>
using namespace std;

const int N = 26, L = 100007;
char a[L], b[L];
int cnt[N];
inline int todigit(char c) {return c - 'a';} //lowercase letters only

int main()
{
    int kase;
    scanf("%d", &kase);
    while (kase--)
    {
		memset(cnt, 0, sizeof(cnt));
		scanf("%s%s", a, b);
		int lb = strlen(b);
		for (int i = 0; i < lb; i++) ++cnt[todigit(b[i])];
		int la = strlen(a), i;
		for (i = 0; i < la; i++)
		{
		    int& CurCnt = cnt[todigit(a[i])];
		    if (CurCnt == 0) break;
		    --CurCnt;
		}
	        printf("%d\n", i);
    }
    
    return 0;
}

