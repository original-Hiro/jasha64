#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int w, r;
char ALL_PERMUTATION[27], INITIAL_PERMUTATION[27], Current[27], Res[5][27], Top;
bool Begin;

void Calc_Permutation(int Cur, int Last)
{
	if (Cur == w)
	{
		if (Begin)
		{
			if (Top == 5) return;
			strcpy(Res[Top++], Current);
		}
		else if (!strcmp(Current, INITIAL_PERMUTATION)) Begin = true;
		return;
	}
	for (int i = Last + 1; i <= r; ++i)
	{
		Current[Cur] = ALL_PERMUTATION[i];
		Calc_Permutation(Cur + 1, i);
	}
}

int main()
{
	int s, t, i;
	
	cin >> s >> t >> w; r = t - s;
	for (i = s; i <= t; ++i) ALL_PERMUTATION[i - s] = i + 'a' - 1;
	scanf("%s", INITIAL_PERMUTATION);
	
	Calc_Permutation(0, -1);
	
	for (i = 0; i < Top; ++i) printf("%s\n", Res[i]);
	
	return 0;
}

