#include <iostream>
using namespace std;

const int N = 200001;
int a[N], f[N];

int main()
{
	ios::sync_with_stdio(false);
	
	int n, k, q;
	cin >> n >> k >> q;
	while (n--)
	{
		int b, c;
		cin >> b >> c;
		a[b]++; a[c+1]--;
	}
	for (int i = 1; i < N; i++) a[i] += a[i-1];
	for (int i = 1; i < N; i++)
		if (a[i] >= k) f[i] = 1;
	for (int i = 1; i < N; i++) f[i] += f[i-1];
	while (q--)
	{
		int b, c;
		cin >> b >> c;
		cout << f[c] - f[b-1] << endl;
	}
	
	return 0;
}

