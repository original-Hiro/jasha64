#include <cstdio>
#include <cstring>

const int L = 100001;
char t[L], p[L];
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
bool KMP()
{
	GetNext();
	int i = 0, j = 0, lp = strlen(p), lt = strlen(t);
	bool has = 0, fir = 1;
	while (i < lt)
	{
		if (t[i] == p[j])
		{
			i++;
			if (++j == lp)
			{
				has = 1;
				if (fir) fir = 0;
				else printf(" ");
				printf("%d", i-lp);
				j = Next[j];
			}
		}
		else if (Next[j] != -1) j = Next[j];
		else {i++; j = 0;}
	}
	return has;
}

int main()
{
	scanf("%s%s", t, p);
	if (!KMP()) printf("DuiYouNe?\n");
	return 0;
}

