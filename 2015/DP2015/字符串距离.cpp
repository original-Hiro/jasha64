#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

template <typename T>
inline T abs(T x)
{
	if (x < 0) return -x;
	return x;
}
template <typename T>
inline T min(T a, T b, T c) {return min(a, min(b, c));}

const int N = 2007;
int f[N][N];

int main()
{
	int i, j, k, l1, l2;
	char s1[N], s2[N];
	
	scanf(" %s %s%d", s1 + 1, s2 + 1, &k);
	
	memset(f, 0x3fffffff, sizeof(f));
	l1 = strlen(s1 + 1); l2 = strlen(s2 + 1);
	for (i = 1; i <= l1; ++i) f[i][0] = i * k;
	for (i = 1; i <= l2; ++i) f[0][i] = i * k;
	for (i = 1; i <= l1; ++i)
		for (j = 1; j <= l2; ++j)
			f[i][j] = min(f[i - 1][j - 1] + abs(s1[i] - s2[j]),
			f[i - 1][j] + k, f[i][j - 1] + k);
	
	printf("%d\n", f[l1][l2]);
	
	return 0;
}

