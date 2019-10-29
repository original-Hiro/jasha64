#include <cstdio>
#include <cstring>
using namespace std;

const int F = 100000;
int cnt[F];

int main()
{
    int kase;
    scanf("%d", &kase);
    while (kase--)
    {
		memset(cnt, 0, sizeof(cnt));
		int n;
		scanf("%d", &n);
		for (int i = 0, a; i < n; i++)
		{
		    scanf("%*s");
		    scanf("%d", &a); cnt[a]++;
		}
		
		int Res = 11111, CurCnt = cnt[11111];
		for (int i = 11112; i < F; i++)
		    if (cnt[i] > CurCnt) {CurCnt = cnt[i]; Res = i;}
		printf("%d\n", Res);
    }
    
    return 0;
}

