#include <iostream>
#include <algorithm>
using namespace std;

const int N = 300007, SIZE = 4096;
int n, a[N], f[N / SIZE + 1][SIZE], p, v;
long long u, k, l, r;

void Read()
{
	int b = 0, j = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		f[b][j] = a[i];
		if (++j == SIZE) {sort(f[b], f[b] + SIZE); ++b; j = 0;}
	}
	if (j) sort(f[b], f[b] + j);
}
void Get()
{
	int lb = l / SIZE, rb = r / SIZE, i;
	k = 0;
	if (lb == rb)
	{
		for (i = l; i <= r; i++) 
			if (a[i] < v) ++k;
		return;
	}
	for (i = (lb + 1) * SIZE - 1; i >= l; i--)
		if (a[i] < v) ++k;
	for (i = lb + 1; i < rb; i++) k += lower_bound(f[i], f[i] + SIZE, v) - f[i];
	for (i = rb * SIZE; i <= r; i++)
		if (a[i] < v) ++k;
}
void Change()
{
	int b = p / SIZE, old = a[p], x = u * k / (r - l + 1);
	if (a[p] == x) return;
	a[p] = x;
	int c = 0;
	while (f[b][c] < old) ++c;
	f[b][c] = x;
	if (x > old)
		while (c < SIZE - 1 && f[b][c + 1] && f[b][c] > f[b][c + 1]) {swap(f[b][c], f[b][c + 1]); ++c;}
	else while (c > 0 && f[b][c] <f[b][c - 1]) {swap(f[b][c], f[b][c - 1]); --c;}
}

int main()
{
	ios::sync_with_stdio(false);
	
	int q;
	cin >> n >> q >> u;
	Read();
	
	while (q--) {cin >> l >> r >> v >> p; --l; --r; --p; Get(); Change();}
	
	for (int i = 0; i < n; i++) cout << a[i] << endl;
	
	return 0;
}

