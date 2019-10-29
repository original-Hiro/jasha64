#include <iostream>
using namespace std;

const int N = 2007;
const char* P[] = {
"  +---+",
" /   /|",
"+---+ |",
"|   | +",
"|   |/ ",
"+---+  "};
int a[507][507];
char c[N][N];

inline void Draw(int x, int y)
{
	int i, j;
	for (j = 0; j < 5; ++j) c[x - 1][y + j] = P[5][j];
	for (j = 0; j < 6; ++j) c[x - 2][y + j] = P[4][j];
	for (i = 2; i < 4; ++i)
		for (j = 0; j < 7; ++j) c[x - i - 1][y + j] = P[5 - i][j];
	for (j = 1; j < 7; ++j) c[x - 5][y + j] = P[1][j];
	for (j = 2; j < 7; ++j) c[x - 6][y + j] = P[0][j];
}

int main()
{
	int n, m, h, w, i, j, k, l;
	
	while (cin >> n >> m)
	{
		fill(c[0], c[0] + N * N, '.');
		k = l = 0;
		for (i = 0; i < n; ++i)
		{
			for (j = 0; j < m; ++j)
			{
				cin >> a[i][j];
				k = max(k, 3 * a[i][j] + 3);
			}
			k += 2;
		}
		k -= 2;
		l = (m << 2) + (n << 1) + 1;
		for (i = 0; i < n; ++i)
			for (j = 0; j < m; ++j)
			{
				h = k - ((n - i - 1) << 1);
				w = ((n - i - 1) << 1) + (j << 2);
				while (a[i][j]--)
				{
					Draw(h, w);
					h -= 3;
				}
			}
		
		for (i = 0; i < k; ++i)
		{
			for (j = 0; j < l; ++j) cout << c[i][j];
			cout << endl;
		}
		cout << endl;
	}
	
	return 0;
}

