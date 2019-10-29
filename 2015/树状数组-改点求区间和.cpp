#include <iostream>
#include <cstdio>
using namespace std;

int n, c1, c2;
int f[1 << 20 | 1];

inline int Lowbit(const int& x) {return x & -x;}
void Add(int x, const int& v) {for (; x <= n; x += Lowbit(x)) f[x] += v;}
int Sum(int x)
{
	int s = 0;
	for (; x > 0; x -= Lowbit(x)) s += f[x];
	return s;
}

int main()
{
	int argc;
	char argv;
	int i;
	
	cin >> n;
	for (i = 1; i <= n; i++)
	{
		scanf("%d", &c1);
		Add(i, c1);
	}
	cin >> argc;
	for (i = 0; i < argc; i++)
	{
		scanf(" %c%d%d", &c1, &c2);
		
		if (argv == 'A') Add(c1, c2);
		else printf("%d\n", Sum(c2) - Sum(c1 - 1));
	}
	
	return 0;
}

