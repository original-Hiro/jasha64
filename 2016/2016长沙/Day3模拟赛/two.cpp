#include <cstdio>
#include <cstring>
using namespace std;

const int N = 100007;
int l1, l2, f[N], Ans[N];
char s1[N], s2[N];

void KMP()
{
	f[0] = f[1] = 0;
	for (int i = 1; i < l2; i++)
	{
		int j = f[i];
		while (j && s2[i] != s2[j] && s2[i] != '?' && s2[j] != '?') j = f[j];
		f[i + 1] = s2[i] == s2[j] || s2[i] == '?' || s2[j] == '?' ? j + 1 : 0;
	}
}
void Find()
{
	int Top = 0;
	for (int i = 0, j = 0; i < l1; i++)
	{
		while (j && s1[i] != s2[j] && s2[j] != '?') j = f[j];
		if (s1[i] == s2[j] || s2[j] == '?') ++j;
		if (j == l2) {Ans[Top++] = i - l2 + 1; j = f[j];}
	}
	printf("%d\n", Top);
	for (int i = 0; i < Top; i++) printf("%d\n", Ans[i]);
}
void Work1()
{
	int Top = 0;
	for (int i = 0, j = 0; i < l1; i++, j = 0)
	{
		while (j < l2 && (s1[i + j] == s2[j] || s2[j] == '?')) ++j;
		if (j == l2) {Ans[Top++] = i; j = 0;}
	}
	printf("%d\n", Top);
	for (int i = 0; i < Top; i++) printf("%d\n", Ans[i]);
}
void Work2() {KMP(); Find();}

int main()
{
	freopen("two.in", "r", stdin);
	freopen("two.out", "w", stdout);
	
	scanf("%s%s", s1, s2);
	l1 = strlen(s1); l2 = strlen(s2);
	if (s2[l2 - 1] == '?') --l1, --l2;
	
	if (l1 <= 100 && l2 <= 100) Work1();
	else Work2();
	
	return 0;
}

