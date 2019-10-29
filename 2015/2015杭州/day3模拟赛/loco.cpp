#include <iostream>
#include <cstdio>
using namespace std;

const int N = 50007;
int a[N], s[N], f[4], n, m, Res;

void Search(const int& Cur)
{
	if (Cur == 4)
	{
		Res = max(Res, s[f[1]] + s[f[2]] + s[f[3]]);
		return;
	}
	for (int i = f[Cur - 1] + m; i <= n - (3 ^ Cur) * m; i++)
	{
		f[Cur] = i;
		Search(Cur + 1);
	}
}

int main()
{
	int i;
	
	cin >> n;
	for (i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
		s[i] = s[i - 1] + a[i];
	}
	cin >> m;
	for (i = n; i > m; i--) s[i] -= s[i - m];
	cout << endl;
	
	Search(1);
	
	cout << Res << endl;
	
	return 0;
}

