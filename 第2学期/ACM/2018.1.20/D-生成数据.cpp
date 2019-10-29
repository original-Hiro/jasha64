#include <fstream>
using namespace std;

ofstream cout("D.in");
const char a[3] = {'*', 'B', 'G'};
char G[3][3];

inline void Print()
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++) cout << G[i][j];
		cout << endl;
	}
	cout << endl;
}
//Make Data
void MD(int x, int y)
{
	if (x == 2 && y == 2)
	{
		for (int k = 0; k < 3; k++)
		{
			G[x][y] = a[k];
			Print();
		}
		return;
	}
	
	int ny = (y + 1) % 3;
	int nx = (ny == 0 ? x+1 : x);
	for (int k = 0; k < 3; k++)
	{
		G[x][y] = a[k];
		MD(nx, ny);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	
	G[0][0] = '*';
	MD(0, 1);
	
	return 0;
}

