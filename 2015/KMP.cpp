#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

const int N = 1000007, MOD = 1000000007;
char a[N];
int Next[N], Len;

void GetNext()
{
	int i, j;
	Len = strlen(a);
	Next[0] = Next[1] = 0;
	for (i = 1; i < Len; i++)
	{
		j = Next[i];
		while (j && a[i] != a[j]) j = Next[j];
		if (a[i] == a[j]) Next[i + 1] = j + 1;
		else Next[i + 1] = 0;
	}
}

int main()
{
	int StringN;
	int i, Res;
	
	cin >> StringN;
	while (StringN--)
	{
		Res = 1;
		fill(a, a + N, '\0');
		
		scanf("%s", a);
		
		GetNext();
		for (i = 0; i < Len; i++) Res = Res * (Next[i] + 1) % MOD;
		
		for (i=0;i<Len;i++) cout<<Next[i]<<' '; cout<<endl;
		
		cout << Res << endl;
	}
	
	return 0;
}

