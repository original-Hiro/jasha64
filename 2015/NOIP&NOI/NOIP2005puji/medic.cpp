#include <fstream>
#include <algorithm>
using namespace std;

ifstream cin("medic.in");
ofstream cout("medic.out");
int f[1007];

int main()
{
	int T, n, t, v;
	int i, j;
	
	cin >> T >> n;
	for (i = 0; i < n; i++)
	{
		cin >> t >> v;
		for (j = T; j >= t; j--) f[j] = max(f[j], f[j - t] + v);
	}
	
	cout << f[T] << endl;
	
	return 0;
}

