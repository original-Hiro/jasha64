#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int n, l, r;
int f[1 << 18 | 1];

inline int Lowbit(const int& x) {return x & -x;}
void Add(int x, const int& v) {for (; x > 0; x -= Lowbit(x)) f[x] += v;}
int Sum(int x)
{
	int s = 0;
	for (; x <= n; x += Lowbit(x)) s += f[x];
	return s;
}

int main()
{
	int i;
	
	while (cin >> n && n)
	{
		for (i = 0; i < n; i++)
		{
			scanf("%d%d", &l, &r);
			Add(r, 1); Add(l - 1, -1);
		}
		
		cout << Sum(1);
		for (i = 2; i <= n; i++) printf(" %d", Sum(i));
		cout << endl;
		
		fill(f + 1, f + n + 1, 0);
	}
	
	return 0;
}

