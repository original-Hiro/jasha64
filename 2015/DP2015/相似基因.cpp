#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

template <typename T>
inline T max(const T& a, const T& b, const T& c) {return max(a, max(b, c));}

const int G[5][5] = 
{
	{0, -3, -4, -2, -1},
	{-3, 5, -1, -2, -1},
	{-4, -1, 5, -3, -2},
	{-2, -2, -3, 5, -2},
	{-1, -1, -2, -2, 5}
}, N = 107;
int f[N][N];

int main()
{
	int l1, l2, i, j, m[N];
	char s1[N], s2[N];
	
	scanf("%d %s%d %s", &l1, s1 + 1, &l2, s2 + 1);
	m['A'] = 1; m['C'] = 2; m['G'] = 3; m['T'] = 4;
	for (i = 1; i <= l1; ++i) s1[i] = m[s1[i]];
	for (i = 1; i <= l2; ++i) s2[i] = m[s2[i]];
	
	for (i = 1; i <= l1; ++i) f[i][0] = f[i - 1][0] + G[s1[i]][0];
	for (i = 1; i <= l2; ++i) f[0][i] = f[0][i - 1] + G[0][s2[i]];
	for (i = 1; i <= l1; ++i)
		for (j = 1; j <= l2; ++j)
			f[i][j] = max(f[i - 1][j] + G[s1[i]][0], f[i][j - 1] + G[0][s2[j]],
			f[i - 1][j - 1] + G[s1[i]][s2[j]]);
	
	printf("%d\n", f[l1][l2]);
	
	return 0;
}

