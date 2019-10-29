#include <iostream>
using namespace std;

const int N = 3, M = 6; 
int g[N][M];
bool f[1000];

inline void calc_one_digit(int a)
{
	for (int i = 0; i < M; i++) f[g[a][i]] = 1;
}
inline void calc_two_digits(int a, int b)
{
	for (int i = 0; i < M; i++)
	{
		if (g[a][i] == 0) continue;
		for (int j = 0; j < M; j++)
		{
			int v = g[a][i] * 10 + g[b][j];
			f[v] = 1;
		}
	}
}
inline void calc_three_digits(int a, int b, int c)
{
	for (int i = 0; i < M; i++)
	{
		if (g[a][i] == 0) continue;
		for (int j = 0; j < M; j++)
			for (int k = 0; k < M; k++)
			{
				int v = g[a][i] * 100 + g[b][j] * 10 + g[c][k];
				f[v] = 1;
			}
	}
}

int main()
{
	int n;
	
	cin >> n;
	if (n >= 1)
	{
		for (int i = 0; i < M; i++) cin >> g[0][i];
		calc_one_digit(0);
	}
	if (n >= 2)
	{
		for (int i = 0; i < M; i++) cin >> g[1][i];
		calc_one_digit(1);
		calc_two_digits(0, 1); calc_two_digits(1, 0); 
	}
	if (n >= 3)
	{
		for (int i = 0; i < M; i++) cin >> g[2][i];
		calc_one_digit(2);
		calc_two_digits(0, 2); calc_two_digits(2, 0);
		calc_two_digits(1, 2); calc_two_digits(2, 1);
		calc_three_digits(0, 1, 2); calc_three_digits(0, 2, 1);
		calc_three_digits(1, 0, 2); calc_three_digits(1, 2, 0);
		calc_three_digits(2, 0, 1); calc_three_digits(2, 1, 0);
	}
	
	int i;
	for (i = 1; i <= 999; i++)
		if (f[i] == 0) break;
	cout << i-1 << endl;
	
	return 0;
}

