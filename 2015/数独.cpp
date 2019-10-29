#include <cstdio>
#include <cstring>
using namespace std;

const int N = 17;
int a[N][N], x[N * N], y[N * N], n, T = 0;
bool Row[N][N], Col[N][N], Sqr[N][N];

bool Read()
{
	int i, j;
	char c;
	
	n = 0;
	memset(Row, 0, sizeof(Row));
	memset(Col, 0, sizeof(Col));
	memset(Sqr, 0, sizeof(Sqr));
	for (i = 1; i <= 9; ++i)
		for (j = 1; j <= 9; ++j)
		{
			if ((scanf(" %c", &c)) == EOF) return false;
			if (c == '?')
			{
				a[i][j] = 0;
				x[n] = i; y[n++] = j;
			}
			else {
				a[i][j] = c - '0';
				Row[i][a[i][j]] = true;
				Col[j][a[i][j]] = true;
				Sqr[(i + 2) / 3 * 3 - 2 + (j - 1) / 3][a[i][j]] = true;
			}
		}
	return true;
}
bool Search(int Cur)
{
	if (Cur == n)
	{
		int i, j;
		
		if (T++) printf("\n");
		for (i = 1; i <= 9; i++)
		{
			printf("%d", a[i][1]);
			for (j = 2; j <= 9; j++) printf(" %d", a[i][j]);
			printf("\n");
		}
		return true;
	}
	
	for (int i = 1; i <= 9; i++)
		if (!Row[x[Cur]][i] && !Col[y[Cur]][i] && !Sqr[(x[Cur] + 2) / 3 * 3 - 2 + (y[Cur] - 1) / 3][i])
		{
			Row[x[Cur]][i] = Col[y[Cur]][i] = Sqr[(x[Cur] + 2) / 3 * 3 - 2 + (y[Cur] - 1) / 3][i] = true;
			a[x[Cur]][y[Cur]] = i;
			if (Search(Cur + 1)) return true;
			a[x[Cur]][y[Cur]] = 0;
			Row[x[Cur]][i] = Col[y[Cur]][i] = Sqr[(x[Cur] + 2) / 3 * 3 - 2 + (y[Cur] - 1) / 3][i] = false;
		}
	return false;
}

int main()
{
	while (Read()) Search(0);
	
	return 0;
}

