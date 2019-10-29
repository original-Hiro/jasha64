#include <fstream>
#include <algorithm>
using namespace std;

ifstream cin("tree.in");
ofstream cout("tree.out");
bool f[10007];

int main()
{
	int L, n, l, r;
	int i, Res = 0;
	
	cin >> L >> n;
	fill(f, f + L + 1, true);
	for (i = 0; i < n; i++)
	{
		cin >> l >> r;
		fill(f + l, f + r + 1, false);
	}
	
	for (i = 0; i <= L; i++)
		if (f[i]) Res++;
	
	cout << Res << endl;
	
	return 0;
}

