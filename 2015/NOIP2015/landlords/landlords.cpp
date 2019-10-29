#include <fstream>
#include <algorithm>
#include <cmath>
using namespace std;

ifstream cin("landlords.in");
ofstream cout("landlords.out");

int Res, b[15];
void DFS(int n, int Move)
{
	if (!n) {Res = min(Res, Move); return;}
	if (Move >= Res) return;
	
	int i, j, k;
	for (i = 3; i <= 11; ++i)
	{
		for (j = i; j <= 13; ++j)
			if (b[j] < 3) break;
		if (--j >= i + 1)
		{
			for (k = i; k <= j; ++k) b[k] -= 3;
			DFS(n - 3 * (j - i + 1), Move + 1);
			for (k = i; k <= j; ++k) b[k] += 3;
		}
	}
	for (i = 3; i <= 11; ++i)
	{
		for (j = i; j <= 13; ++j)
			if (b[j] < 2) break;
		if (--j >= i + 2)
		{
			for (k = i; k <= j; ++k) b[k] -= 2;
			DFS(n - ((j - i + 1) << 1), Move + 1);
			for (k = i; k <= j; ++k) b[k] += 2;
		}
	}
	for (i = 3; i <= 11; ++i)
	{
		for (j = i; j <= 13; ++j)
			if (!b[j]) break; 
		if (--j >= i + 4)
		{
			for (k = i; k <= j; ++k) --b[k];
			DFS(n - (j - i + 1), Move + 1);
			for (k = i; k <= j; ++k) ++b[k];
		}
	}
	for (i = 1; i <= 13; ++i)
		if (b[i] >= 4)
			for (j = 1; j <= 13; ++j)
				if (i != j && b[j] >= 2)
					for (k = 1; k <= 13; ++k)
						if (i != k && j != k && b[k] >= 2)
						{
							b[i] -= 4; b[j] -= 2; b[k] -= 2;
							DFS(n - 8, Move + 1);
							b[i] += 4; b[j] += 2; b[k] += 2;
						}
	for (i = 1; i <= 13; ++i)
		if (b[i] >= 4)
			for (j = 1; j <= 13; ++j)
				if (i != j && b[j])
					for (k = 1; k <= 13; ++k)
						if (i != k && j != k && b[k])
						{
							b[i] -= 4; --b[j]; --b[k];
							DFS(n - 6, Move + 1);
							b[i] += 4; ++b[j]; ++b[k];
						}
	for (i = 1; i <= 13; ++i)
		if (b[i] >= 3)
			for (j = 1; j <= 13; ++j)
				if (i != j && b[j] >= 2)
				{
					b[i] -= 3; b[j] -= 2;
					DFS(n - 5, Move + 1);
					b[i] += 3; b[j] += 2;
				}
	for (i = 1; i <= 13; ++i)
		if (b[i] >= 3)
			for (j = 1; j <= 13; ++j)
				if (i != j && b[j] >= 1)
				{
					b[i] -= 3; --b[j];
					DFS(n - 4, Move + 1);
					b[i] += 3; ++b[j];
				}
	for (i = 1; i <= 13; ++i)
		if (b[i] >= 4)
		{
			b[i] -= 4;
			DFS(n - 4, Move + 1);
			b[i] += 4;
		}
	for (i = 1; i <= 13; ++i)
		if (b[i] >= 3)
		{
			b[i] -= 3;
			DFS(n - 3, Move + 1);
			b[i] += 3;
		}
	for (i = 1; i <= 13; ++i)
		if (b[i] >= 2)
		{
			b[i] -= 2;
			DFS(n - 2, Move + 1);
			b[i] += 2;
		}
	for (i = 1; i <= 13; ++i)
		if (b[i])
		{
			--b[i];
			DFS(n - 1, Move + 1);
			++b[i];
		}
}

int main()
{
	int T, n, i, c1, c2;
	
	cin >> T >> n;
	while (T--)
	{
		Res = n;
		
		for (i = 0; i < n; ++i)
		{
			cin >> c1 >> c2;
			++b[c1];
		}
		
		DFS(n - b[0], 0);
		if (b[0]) ++Res;
		
		cout << Res << endl;
	}
	
	return 0;
}

