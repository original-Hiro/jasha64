#include <cstdio>
#include <set>
#include <string>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;

typedef pair<int, int> pii;
char G[3][3];
int f[3][3], fa[9];
string str;
set<string> s;
const int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};
int pl;

int Find(int x) {return fa[x] == x ? x : fa[x] = Find(fa[x]);}
inline int trans(int x, int y) {return 3 * x + y;} //并查集用，二维坐标转换成一维坐标 
inline int Find(int x, int y) {return Find(trans(x, y));}
inline bool Out(int x, int y) {return x < 0 || x > 2 || y < 0 || y > 2;} //越界 
void Pre_Process()
{
	pl = 0; memset(f, 0, sizeof(f));
	for (int x = 0; x < 3; x++)
		for (int y = 0; y < 3; y++)
			if (G[x][y] != '*') pl++;
			else f[x][y] = 1;
	
	for (int i = 0; i < 9; i++) fa[i] = i;
	for (int x = 0; x < 3; x++)
		for (int y = 0; y < 3; y++)
			if (f[x][y])
				for (int i = 0; i < 2; i++)
				{
					int nx = x + dx[i];
					int ny = y + dy[i];
					if (Out(nx, ny) || !f[nx][ny]) continue;
					fa[Find(nx, ny)] = Find(x, y);
				}
				//k<2只访问右方和下方 k<4访问上下左右 
	
	s.clear();
}
void Search(int lx, int ly)
{
	if (pl == 0) s.insert(str);
	else {
		int fa_old[9];
		memcpy(fa_old, fa, sizeof(fa));
		fa[Find(lx, ly)] = Find(0, 0);
		for (int k = 0; k < 4; k++)
		{
			int nx = lx + dx[k];
			int ny = ly + dy[k];
			if (Out(nx, ny) || !f[nx][ny]) continue;
			fa[Find(nx, ny)] = Find(lx, ly);
		}
		
		for (int x = 0; x < 3; x++)
			for (int y = 0; y < 3; y++)
				if (Find(x, y) == Find(0, 0))
					for (int k = 0; k < 4; k++)
					{
						int nx = x + dx[k];
						int ny = y + dy[k];
						if (Out(nx, ny) || f[nx][ny]) continue;
						str += G[nx][ny]; f[nx][ny] = 1; pl--;
						Search(nx, ny);
						f[nx][ny] = 0; str = str.substr(0, str.size()-1); pl++;
					}
		
		memcpy(fa, fa_old, sizeof(fa_old));
	}
}

int main()
{
	freopen("D.in", "r", stdin);
	freopen("D.cpp", "w", stdout); 
	
	while (true)
	{
		for (int i = 0; i < 3; i++)
			if (scanf("%s", G[i]) == EOF) return 0;
		
		Pre_Process();
		Search(0, 0);
		
		printf("else if (strcmp(G[0], \"%s\") == 0) cout << %d << endl;\n", G[0], s.size());
	}
}

