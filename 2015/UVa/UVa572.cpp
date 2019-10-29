#include <iostream>
#include <cstring>
using namespace std;

const int N = 107;
int m, n, idx[N][N];
char pic[N][N];

inline void DFS(const int& r, const int& c, const int& id)
{
	if (r < 0 || r >= m || c < 0 || c >= n) return;
	if (idx[r][c] || pic[r][c] != '@') return;
	idx[r][c] = id;
	int dr, dc;
	for (dr = -1; dr <= 1; dr++)
		for (dc = -1; dc <= 1; dc++)
			if (dr || dc) DFS(r + dr, c + dc, id);
}

int main()
{
	int i, j, count;
	
	while ((cin >> m >> n) && m && n)
	{
		for (i = 0; i < m; i++)
			for (j = 0; j < n; j++) cin >> pic[i][j];
		
		memset(idx, 0, sizeof(idx));
		count = 0;
		for (i = 0; i < m; i++)
			for (j = 0; j < n; j++)
				if (!idx[i][j] && pic[i][j] == '@') DFS(i, j, ++count);
		
		cout << count << endl;
	}
	
	return 0;
}

