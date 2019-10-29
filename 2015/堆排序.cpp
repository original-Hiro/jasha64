#include <iostream>
#include <algorithm>
using namespace std;

int n, f[1 << 13 | 1];

void Adjust(int i, int m)
{
	int j = i << 1;
	while (j <= m)
	{
		if (j < m && f[j + 1] < f[j]) j++;
		if (f[j] < f[i]) {swap(f[i], f[j]); i = j; j = i << 1;}
		else return;
	}
}
void Sort()
{
	int i;
	for (i = n >> 1; i > 0; i--) Adjust(i, n);
	for (i = n; i > 1; i--) {swap(f[1], f[i]); Adjust(1, i - 1);}
}

int main()
{
	int i;
	
	cin >> n;
	for (i = 1; i <= n; i++) cin >> f[i];
	
	Sort();
	
	cout << f[1];
	for (i = 2; i <= n; i++) cout << ' ' << f[i];
	cout << endl;
	
	return 0;
}

