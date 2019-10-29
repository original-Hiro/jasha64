#include <cstdio>
using namespace std;

const int N = 30000000;
int f[N + 7];

int main()
{
	int T, n, i, j, k, Case = 0;
	
	for (i = 2; i <= N; ++i)
		if ((i ^ (i - 1)) == 1)
		{
			++f[i];
			for (j = i << 1, k = 2; j <= N; j += i, ++k)
				if ((j ^ (j - k)) == k) ++f[j];
		}
	for (i = 2; i <= N; ++i) f[i] += f[i - 1];
	
	scanf("%d", &T);
	while (T--) {scanf("%d", &n); printf("Case %d: %d\n", ++Case, f[n]);}
	
	return 0;
}

