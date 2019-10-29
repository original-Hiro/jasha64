#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
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
void Init(const int& Root, const int& Left, const int& Right)
{
	if (Left >= Right) {f[Root] = a[Left]; return;}
	Init(LSon);
	Init(RSon);
	f[Root] = max(f[LRoot], f[RRoot]);
}
int Query(const int& Root, const int& Left, const int& Right)
{
	if (Left > y || Right < x) return -1;
	if (x <= Left && Right <= y) return f[Root];
	int a = Query(LSon), b = Query(RSon);
	return max(a, b);
}

int main()
{
	int n, m;
	int i;
	
	cin >> n;
	for (i = 1; i <= n; i++) scanf("%d", &a[i]);
	Init(1, 1, n);
	cin >> m;
	for (i = 0; i < m; i++)
	{
		scanf("%d%d", &x, &y);
		if (x > y) {Swap(x, y);}
		printf("%d\n", Query(1, 1, n));
	}
	
	return 0;
}

