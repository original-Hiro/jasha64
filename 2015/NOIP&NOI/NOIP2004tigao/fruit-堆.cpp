#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int Res, n, f[1 << 15 | 1];

void Adjust(int i, int m)
{
	int j = i << 1;
	while (j <= m)
	{
		if (j < m && f[j] > f[j + 1]) j++;
		if (f[j] < f[i]) {swap(f[i], f[j]); i = j; j = i << 1;}
		else return;
	}
}
void Heap_Sort()
{
	int i;
	for (i = n >> 1; i > 0; i--) Adjust(i, n);
	for (i = n; i > 1; i--)
	{
		swap(f[1], f[i]);
		Adjust(1, i - 1);
		Res += (f[1] += f[i]);
		Adjust(1, i - 1);
	}
}

int main()
{
	int i;
	
	cin >> n;
	for (i = 1; i <= n; i++) scanf("%d", &f[i]);
	
	Heap_Sort();
	
	cout << Res << endl;
	
	return 0;
}

