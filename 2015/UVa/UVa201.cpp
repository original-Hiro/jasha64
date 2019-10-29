#include <iostream>
#include <algorithm>
using namespace std;

const int M = 10;
bool EdgeH[M][M], EdgeV[M][M];
int square[M];

inline bool exist(const int& x, const int& y, const int& len)
{
	if (x + len > M - 1 || y + len > M - 1) return false;
	for (int i = 0; i < len; i++)
		if (!EdgeH[x][y + i] || !EdgeV[x + i][y] ||
			!EdgeH[x + len][y + i] || !EdgeV[x + i][y + len]) return false;
	return true;
}

int main()
{
	int n, m;
	int i, i1, i2, kase = 0;
	bool has_square;
	char c;
	
	while (cin >> n >> m)
	{
		has_square = 0;
		fill(square, square + M, 0);
		for (i = 0; i < M; i++)
		{
			fill(EdgeH[i], EdgeH[i] + M, 0);
			fill(EdgeV[i], EdgeV[i] + M, 0);
		}
		
		for (i = 1; i <= m; i++)
		{
			cin >> c >> i1 >> i2;
			if (c == 'H') EdgeH[i1][i2] = 1;
			else EdgeV[i2][i1] = 1;
		}
		
//		for (i=1;i<=n;i++) {for (i1=1;i1<=n;i1++) cout<<EdgeH[i][i1]<<EdgeV[i][i1]<<' '; cout<<endl;} 
		
		for (i = 1; i <= n; i++)
			for (i1 = 1; i1 <= n; i1++)
				for (i2 = 1; i2 <= n; i2++)
					if (exist(i, i1, i2)) square[i2]++;
		
		if (kase) cout << endl << "**********************************" << endl << endl;
		cout << "Problem #" << ++kase << endl << endl;
		for (i = 1; i <= n; i++)
			if (square[i])
			{
				has_square = 1;
				cout << square[i] << " square (s) of size " << i << endl;
			}
		if (!has_square) cout << "No complete squares can be found." << endl;
	}
	
	return 0;
}

