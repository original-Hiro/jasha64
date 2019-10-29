#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

const int N = 1 << 18 | 1;
int a[N], n;

inline int Lowbit(int x) {return x & -x;}
void Add(int x, int v) {for (int i = x; i > 0; i -= Lowbit(i)) a[i] += v;}
int Query(int x)
{
	int Ret = 0;
	for (int i = x; i <= n; i += Lowbit(i)) Ret += a[i];
	return Ret;
}

int main()
{
	while (cin >> n && n)
	{
		fill(a, a + N, 0);
		
		for (int i = 0, l, r; i < n; i++) {scanf("%d%d", &l, &r); Add(r, 1); Add(l - 1, -1);}
		
		cout << Query(1);
		for (int i = 2; i <= n; i++) printf(" %d", Query(i));
		cout << endl;
	}
	
	return 0;	
}

