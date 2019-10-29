#include <iostream>
#include <algorithm>
using namespace std;

int map[15][15], number[15][15];

struct xiangqi
{
	int posx, posy, num;
	char type;
	
	xiangqi() {posx = posy = num = 0; type = ' ';}
	void init()
	{
		map[posx][posy] += num;
		int i;
		switch (type)
		{
			case 'G':
				for (i = posx + 1; i <= 10; i++)
				{
					if (number[i][posy]) break;
					map[i][posy] += num;
				}
				for (i = posx - 1; i > 0; i--)
				{
					if (number[i][posy]) break;
					map[i][posy] += num;
				}
				break;
			case 'R':
				for (i = posx + 1; i <= 10; i++)
				{
					if (number[i][posy]) break;
					map[i][posy] += num;
				}
				for (i = posx - 1; i > 0; i--)
				{
					if (number[i][posy]) break;
					map[i][posy] += num;
				}
				for (i = posy + 1; i <= 9; i++)
				{
					if (number[posx][i]) break;
					map[posx][i] += num;
				}
				for (i = posy - 1; i > 0; i--)
				{
					if (number[posx][i]) break;
					map[posx][i] += num;
				}
				break;
			case 'H':
				if (!number[posx + 1][posy])
				{
					map[posx + 2][posy - 1] += num;
					map[posx + 2][posy + 1] += num;
				}
				if (!number[posx - 1][posy])
				{
					map[posx - 2][posy - 1] += num;
					map[posx - 2][posy + 1] += num;
				}
				if (!number[posx][posy + 1])
				{
					map[posx + 1][posy + 2] += num;
					map[posx - 1][posy + 2] += num;
				}
				if (!number[posx][posy - 1])
				{
					map[posx + 1][posy - 2] += num;
					map[posx - 1][posy - 2] += num;
				}
				break;
			case 'C':
				for (i = posx + 1; i <= 10; i++)
					if (number[i][posy]) {i++; break;}
				for (; i <= 10; i++)
				{
					if (number[i][posy]) break;
					map[i][posy] += num;
				}
				for (i = posx - 1; i > 0; i--)
					if (number[i][posy]) {i--; break;}				
				for (; i > 0; i--)
				{
					if (number[i][posy]) break;
					map[i][posy] += num;
				}
				for (i = posy + 1; i <= 9; i++)
					if (number[posx][i]) {i++; break;}
				for (; i <= 9; i++)
				{
					if (number[posx][i]) break;
					map[posx][i] += num;
				}
				for (i = posy - 1; i > 0; i--)
					if (number[posx][i] == 2) {i--; break;}
				for (; i > 0; i--)
				{
					if (number[posx][i]) break;
					map[posx][i] += num;
				}
				break;
		}
	}
	
	friend istream& operator >> (istream& cin, xiangqi& a)
	{
		cin >> a.type >> a.posx >> a.posy;
		return cin;
	}
} f[15];

inline bool checkmate(const int& x, const int& y)
{
	switch (x)
	{
		case 1:
		switch (y)
		{
			case 4: return map[1][5] != number[1][5] && map[2][4] != number[2][4];
			case 5: return map[1][4] != number[1][4] && map[1][6] != number[1][6] &&
							map[2][5] != number[2][5];
			case 6: return map[1][5] != number[1][5] && map[2][6] != number[2][6];
		}
		case 2:
		switch (y)
		{
			case 4: return map[1][4] != number[1][4] && map[3][4] != number[3][4] &&
							map[2][5] != number[2][5];
			case 5: return map[1][5] != number[1][5] && map[3][5] != number[3][5] &&
							map[2][4] != number[2][4] && map[2][6] != number[2][6];
			case 6: return map[1][6] != number[1][6] && map[3][6] != number[3][6] &&
							map[2][5] != number[2][5];
		}
		case 3:
		switch (y)
		{
			case 4: return map[2][4] != number[2][4] && map[3][5] != number[3][5];
			case 5: return map[2][5] != number[2][5] && map[3][4] != number[3][4] &&
							map[3][6] != number[3][6];
			case 6: return map[2][6] != number[2][6] && map[3][5] != number[3][5];
		}
	}
}

int main()
{
	int n, x, y;
	int i;
	
	while ((cin >> n >> x >> y) && n && x && y)
	{
		for (i = 0; i < 15; i++)
		{
			fill(map[i], map[i] + 15, 0);
			fill(number[i], number[i] + 15, 0);
		}
		
		for (i = 1; i <= n; i++)
		{
			cin >> f[i];
			number[f[i].posx][f[i].posy] = f[i].num = i;
		}
		for (i = 0; i < n; i++) f[i].init();
		
		if (checkmate(x, y)) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	
	return 0;
}

