#include <iostream>
#include <cstring>
using namespace std;

const int N = 57, dx[] = {-1, 0, 0, 1}, dy[] = {0, -1, 1, 0};
int m, n;
char G[N][N];
bool f[N][N][4], v[N][N];

void DFS(int x, int y)
{
	if (x < 1 || x > m || y < 1 || y > n || v[x][y]) return;
	v[x][y] = true;
	for (int i = 0; i < 4; i++)
		if (f[x][y][i] && f[x + dx[i]][y + dy[i]][i ^ 3])
			DFS(x + dx[i], y + dy[i]);
}

int main()
{
	int i, j, Count;
	
	while (cin >> m >> n && m > 0 && n > 0)
	{
		Count = 0;
		memset(v, 0, sizeof(v));
		memset(f, 0, sizeof(f));
		
		for (i = 1; i <= m; i++)
			for (j = 1; j <= n; j++)
			{
				cin >> G[i][j];
				switch (G[i][j])
				{
					case 'A': f[i][j][0] = f[i][j][1] = true; break;
					case 'B': f[i][j][0] = f[i][j][2] = true; break;
					case 'C': f[i][j][3] = f[i][j][1] = true; break;
					case 'D': f[i][j][2] = f[i][j][3] = true; break;
					case 'E': f[i][j][3] = f[i][j][0] = true; break;
					case 'F': f[i][j][2] = f[i][j][1] = true; break;
					case 'G': f[i][j][0] = f[i][j][2] = f[i][j][1] = true; break;
					case 'H': f[i][j][0] = f[i][j][3] = f[i][j][1] = true; break;
					case 'I': f[i][j][1] = f[i][j][2] = f[i][j][3] = true; break;
					case 'J': f[i][j][0] = f[i][j][3] = f[i][j][2] = true; break;
					case 'K': f[i][j][0] = f[i][j][1] = f[i][j][2] = f[i][j][3] = true; break;
				}
			}
			
		for (i = 1; i <= m; i++)
			for (j = 1; j <= n; j++)
				if (!v[i][j]) {++Count; DFS(i, j);}
		
		cout << Count << endl;
	} 
	
	return 0;
} 

