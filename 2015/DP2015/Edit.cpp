#include <iostream>
#include <algorithm>
#include <string>
#include <cstdarg>
using namespace std;

const int N = 5007;
int f[N][N];
string s1, s2;

template <typename T>
inline T Min(int Num, const T& a, ...)
{
	va_list Arg;
	T c, Res = a;
	
	va_start(Arg, a); Num--;
	while (Num--)
	{
		c = va_arg(Arg, T);
		Res = min(Res, c);
	}
	va_end(Arg);
	
	return Res;
}

int main()
{
	while (cin >> s1 >> s2)
	{
		int l1 = s1.size(), l2 = s2.size(), i, j;
		
		for (i = 1; i <= l1; i++) f[i][0] = i;
		for (i = 1; i <= l2; i++) f[0][i] = i;
		for (i = 1; i <= l1; i++)
			for (j = 1; j <= l2; j++)
			{
				f[i][j] = Min(3, f[i - 1][j - 1], f[i - 1][j], f[i][j - 1]) + 1;
				if (s1[i - 1] == s2[j - 1]) f[i][j] = min(f[i][j], f[i - 1][j - 1]);
			}
		
		cout << f[l1][l2] << endl;
	}
	
	return 0;
}

