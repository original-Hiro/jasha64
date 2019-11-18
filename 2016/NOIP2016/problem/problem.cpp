//"CTSC" 2016
#include <iostream>
#include <cstdio>
using namespace std;

const int N = 2007;
int C[N][N], f[N][N], fx[N][N], fy[N][N]; //忘记二维前缀和怎么求了只能乱搞QAQ 

//再次提醒 不要忘记注释调试输出 
void Print()
{
	for (int i = 0; i <= 10; i++)
	{
		for (int j = 0; j <= i; j++) cout << f[i][j] << ' ';
		cout << endl;
	}
	cout << endl;
}

int main()
{
	freopen("problem.in", "r", stdin);
	freopen("problem.out", "w", stdout);
	
	int T, k;
	cin >> T >> k;
	
	C[0][0] = 1;
	for (int i = 1; i < N; i++)
	{
		C[i][0] = 1;
		for (int j = 1; j <= i; j++) C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % k;
	}
	for (int i = 0; i < N; i++)
		for (int j = 0; j <= i; j++)
			if (C[i][j] == 0) f[i][j] = 1;
//	Print();
	for (int i = 0; i < N; i++)
	{
		fx[i][0] = f[i][0];
		for (int j = 1; j <= i; j++) fx[i][j] = fx[i][j - 1] + f[i][j];
	}
	fy[0][0] = f[0][0];
	for (int i = 1; i < N; i++)
		for (int j = 0; j <= i; j++) fy[i][j] = fy[i - 1][j] + f[i][j];
	for (int i = 1; i < N; i++)
	{
		f[i][0] = fy[i][0];
		for (int j = 1; j <= i; j++) f[i][j] = f[i - 1][j - 1] + fx[i][j - 1] + fy[i - 1][j] + f[i][j];
	}
//	Print();
	
	int a, b;
	while (T--)
	{
		scanf("%d%d", &a, &b);
		if (b > a) b = a;
		printf("%d\n", f[a][b]);
	}
	
	return 0; //中规中矩 
}

