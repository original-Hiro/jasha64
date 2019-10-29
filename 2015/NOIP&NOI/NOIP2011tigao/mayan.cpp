#include <iostream>
#include <algorithm>
#include <cstring>
#include <stack>
using namespace std;

const int T[5][7] = {0};
int n;
struct Move
{
	int x, y, g;
	
	Move() {}
	Move(int a, int b, int c) {x = a; y = b; g = c;}
	
	friend ostream& operator << (ostream& cout, Move a)
	{
		cout << a.x << ' ' << a.y << ' ' << a.g;
		return cout;
	}
} C;
stack<Move> s;

void Switch(int a[5][7], int c[17])
{
	int i, j, k, x, y, sx, tx, sy, ty;
	bool OK, vx[5][7], vy[5][7], Cl[5][7];
	
	for (i = 0; i < 5; i++)
		for (j = 0; j < 7; j++)
			if (!a[i][j])
			{
				for (k = j + 1; k < 7; k++)
					if (a[i][k]) {swap(a[i][j], a[i][k]); break;}
				if (k == 7) break;
			}
	do {
		OK = true;
		memset(vx, 0, sizeof(vx));
		memset(vy, 0, sizeof(vy));
		memset(Cl, 0, sizeof(Cl));
		
		for (x = 0; x < 5; x++)
			for (y = 0; y < 7; y++)
			{
				if (!vx[x][y])
				{
					sx = 0; tx = 4;
					if (x > 0)
						for (sx = x - 1; true; sx--)
						{
							if (a[sx][y] != a[sx + 1][y]) {sx++; break;}
							if (sx == 0) break;
						}
					if (x < 4)
						for (tx = x + 1; true; tx++)
						{
							if (a[tx][y] != a[tx - 1][y]) {tx--; break;}
							if (tx == 4) break;
						}
					for (i = sx; i <= tx; i++) vx[i][y] = true;
					if (tx - sx >= 2)
						for (i = sx; i <= tx; i++) Cl[i][y] = true;
				}
				if (!vy[x][y])
				{
					sy = 0; ty = 6;
					if (y > 0)
						for (sy = y - 1; true; sy--)
						{
							if (a[x][sy] != a[x][sy + 1]) {sy++; break;}
							if (sy == 0) break;
						}
					if (y < 6)
						for (ty = y + 1; true; ty++)
						{
							if (a[x][ty] != a[x][ty - 1]) {ty--; break;}
							if (ty == 6) break;
						}
					for (i = sy; i <= ty; i++) vy[x][i] = true;
					if (ty - sy >= 2)
						for (i = sy; i <= ty; i++) Cl[x][i] = true;
				}
			}
		for (i = 0; i < 5; i++)
			for (j = 0; j < 7; j++)
				if (Cl[i][j]) {c[a[i][j]]--; a[i][j] = 0;}
		
		for (i = 0; i < 5; i++)
			for (j = 0, k = 1; k < 7; j++, k++)
				if (!a[i][j])
				{
					while (!a[i][k] && k < 7) k++;
					if (k == 7) break; 
					swap(a[i][j], a[i][k]);
					OK = false;
				}
	} while (!OK);
}
bool DFS(int Cur, const int a[5][7], const int Color[17])
{
	if (Cur == n) return !memcmp(a, T, sizeof(T)); 
	
	int x, y, g, f[5][7] = {0}, c[17]; 
	
	for (x = 1; x <= 10; x++)
		if (Color[x] == 1 || Color[x] == 2) return false; 
	
	memcpy(f, a, sizeof(f)); copy(Color, Color + 17, c);
	for (x = 0; x < 4; x++)
		for (y = 0; y < 7; y++)
			if (f[x][y])
			{
				if (f[x][y] == f[x + 1][y]) continue;
				g = 1; swap(f[x][y], f[x + 1][y]); Switch(f, c);
				if (DFS(Cur + 1, f, c)) {s.push(Move(x, y, g)); return true;}
				memcpy(f, a, sizeof(f)); copy(Color, Color + 17, c);
				if (x > 0 && !f[x - 1][y])
				{
					g = -1; swap(f[x][y], f[x - 1][y]); Switch(f, c);
					if (DFS(Cur + 1, f, c)) {s.push(Move(x, y, g)); return true;}
					memcpy(f, a, sizeof(f)); copy(Color, Color + 17, c);
				}
			}
			else break;
	for (y = 0; y < 7; y++)
		if (f[x][y] && !f[x - 1][y])
		{
			g = -1; swap(f[x][y], f[x - 1][y]); Switch(f, c);
			if (DFS(Cur + 1, f, c)) {s.push(Move(x, y, g)); return true;}
			memcpy(f, a, sizeof(f)); copy(Color, Color + 17, c);
		}
		else break;
	
	return false;
}

int main()
{
	int i, j, t, a[5][7] = {0}, c[17] = {0};
	
	cin >> n;
	for (i = 0; i < 5; i++)
	{
		j = 0;
		while ((cin >> t) && t)
		{
			a[i][j] = t;
			c[a[i][j++]]++;
		}
	}
	
	if (DFS(0, a, c))
		while (!s.empty())
		{
			C = s.top(); s.pop();
			cout << C << endl;
		}
	else cout << -1 << endl;
	
	return 0;
}
 
