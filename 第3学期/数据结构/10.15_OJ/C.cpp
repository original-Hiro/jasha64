#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int L = 100001;
char t[L], p[L];
int f[L];
int Next[L];
void GetNext()
{
	int i = 0, k = -1, lp = strlen(p);
	Next[0] = -1;
	while (i < lp)
	{
		if (k == -1 || p[i] == p[k])
		{
			Next[++i] = ++k;
			if (p[i] == p[k]) Next[i] = Next[k];
		}
		else k = Next[k];
	}
}
inline void Relax(int& a, int b) {if (a > b) a = b;}
bool KMP()
{
	GetNext();
	int i = 0, j = 0, lp = strlen(p), lt = strlen(t);
	while (i < lt)
	{
		if (t[i] == p[j])
		{
			i++; Relax(f[i], f[i-1] + 1);
			if (++j == lp)
			{
				Relax(f[i-1], lp-1);
				Relax(f[i], f[i-1] + 1);
				j = Next[j];
			}
		}
		else if (Next[j] != -1) j = Next[j];
		else {i++; Relax(f[i], f[i-1] + 1); j = 0;}
	}
}

int main()
{
	int n;
	scanf("%s", t);
	scanf("%d", &n);
	
	int len = strlen(t);
	for (int i = 0; i < len; i++) f[i] = i+1;
	while (n--)
	{
		scanf("%s", p);
		if (strlen(p) == 1)
		{
			for (int i = 0; i < len; i++)
				if (p[0] == t[i]) f[i] = 0;
				else if (i > 0) Relax(f[i], f[i-1] + 1);
		}
		else KMP();
		//for (int i = 0; i < len; i++) printf("%d ", f[i]); puts("");
	}
	
	int res = 0;
	for (int i = 0; i < len; i++) res = max(res, f[i]);
	if (res == 0) printf("DuiYouNe!?\n");
	else printf("%d\n", res);
	
	return 0;
}

