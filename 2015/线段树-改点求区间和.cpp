#include <iostream>
#include <algorithm>
#include <cstdio>
#include <string>
using namespace std;
#define Mid (Left + Right) >> 1
#define LRoot Root << 1
#define RRoot Root << 1 | 1
#define LSon Root << 1, Left, (Left + Right) >> 1
#define RSon Root << 1 | 1, ((Left + Right) >> 1) + 1, Right

int a[500007], x, y;
int f[1 << 20 | 1];

template <typename T>
inline void Swap(T& x, T& y)
{
	x ^= y; y ^= x; x ^= y;
}
void Change(const int& Root, const int& Left, const int& Right)
{
	if (Left == Right) {f[Root] = y; return;}
	if (Mid < x) Change(RSon);
	else Change(LSon);
	f[Root] = f[LRoot] + f[RRoot];
}
void Init(const int& Root, const int& Left, const int& Right)
{
	if (Left >= Right) {f[Root] = a[Left]; return;}
	Init(LSon);
	Init(RSon);
	f[Root] = f[LRoot] + f[RRoot];
}
int Sum(const int& Root, const int& Left, const int& Right)
{
	if (Left > y || Right < x) return 0;
	if (x <= Left && Right <= y) return f[Root];
	int a = Sum(LSon), b = Sum(RSon);
	return a + b;
}

int main()
{
	int n, argc;
	char argv;
	int i;
	
	cin >> n;
	for (i = 1; i <= n; i++) scanf("%d", &a[i]);
	Init(1, 1, n);
	cin >> argc;
	for (i = 0; i < argc; i++)
	{
		scanf(" %c%d%d", &argv, &x, &y);
		if (argv == 'U') Change(1, 1, n);
		else {
			if (x > y) {Swap(x, y);}
			printf("%d\n", Sum(1, 1, n));
		}
	}
	
	return 0;
}

