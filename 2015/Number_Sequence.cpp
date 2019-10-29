#include <iostream>
#include <algorithm>
using namespace std;

const int N = 2407;
int f[N] = {0, 1, 1}, Pos1[N], Pos2[N];

int main()
{
	int a, b, n;
	int i, Cycle;
	
	while ((cin >> a >> b >> n) && a && b && n)
	{
		fill(f + 3, f + N, 0);
		fill(Pos1, Pos1 + N, 0);
		fill(Pos2, Pos2 + N, 0);
		Pos1[1] = 1; Pos2[1] = 2;
		for (i = 3;; i++)
			f[i] = ;
	}
	
	return 0;
}

