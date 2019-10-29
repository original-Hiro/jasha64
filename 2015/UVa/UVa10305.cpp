#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

const int N = 107;
int TaskN, RelationN;
int Topo[N], Top;
bool Vis[N], Before[N][N];

void DFS(const int& Number)
{
	Vis[Number] = 1;
	for (int i = 1; i <= TaskN; i++)
		if (!Vis[i] && Before[Number][i]) DFS(i);
	Topo[--Top] = Number;
}
void Topo_Sort()
{
	Top = TaskN;
	for (int i = 1; i <= TaskN; i++)
		if (!Vis[i]) DFS(i);
}

int main()
{
	int i, c1, c2;
	
	while ((cin >> TaskN >> RelationN) && (TaskN || RelationN))
	{
		memset(Before, 0, sizeof(Before));
		
		while (RelationN--)
		{
			cin >> c1 >> c2;
			Before[c1][c2] = 1;
		}
		
		Topo_Sort();
		
		cout << Topo[0];
		for (i = 1; i < TaskN; i++) cout << ' ' << Topo[i];
		cout << endl;
		
		fill(Topo, Topo + TaskN, 0);
		fill(Vis + 1, Vis + TaskN + 1, 0);
	}
	
	return 0;
}

