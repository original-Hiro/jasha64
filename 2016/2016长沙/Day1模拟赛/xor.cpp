#include <fstream>
using namespace std;

ifstream cin("xor.in");
ofstream cout("xor.out");
int n, m, l, r, a[7], Res;

void Search(int x)
{
	if (x == n + 1)
	{
		for (int d = l; d <= r; d++)
		{
			int r = a[1] + d;
			for (int i = 2; i <= n; i++) r ^= a[i] + d;
			if (!r) {++Res; return;}
		}
		return;
	}
	for (int i = 0; i <= m; i++) {a[x] = i; Search(x + 1);}
}
void Work1()
{
	n = n << 1 | 1;
	Search(1);
	cout << Res << endl;
}
void Work2()
{
	
}

int main()
{
	cin >> n >> m >> l >> r;
	
	if (n <= 5 && m <= 5 && l <= 10 && r <= 10) Work1();
	else Work2();
	
	return 0;
}

