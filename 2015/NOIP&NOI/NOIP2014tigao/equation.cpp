#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

typedef unsigned long long ull;
const ull N = 107, MOD[] = {100000007, 2147483647};
int Solutions[107], Top;

int main()
{
	freopen("equation.in", "r", stdin);
	freopen("equation.out", "w", stdout);
	
	int NumberN, Range;
	ull Numbers[107][2];
	int i, j;
	bool isNeg;
	char C;
	
	cin >> NumberN >> Range;
	memset(Numbers, 0, sizeof(Numbers));
	for (i = 0; i <= NumberN; i++)
	{
		isNeg = 0;
		do C = getchar(); while (!(C == '-' || ('0' <= C && C <= '9')));
		if (C == '-')
		{
			isNeg = true;
			C = getchar();
		}
		do {
			Numbers[i][0] = (Numbers[i][0] * 10 + (C - '0')) % MOD[0];
			Numbers[i][1] = (Numbers[i][1] * 10 + (C - '0')) % MOD[1];
			C = getchar();
		} while ('0' <= C && C <= '9');
		if (isNeg)
		{
			if (Numbers[i][0]) Numbers[i][0] = MOD[0] - Numbers[i][0];
			if (Numbers[i][1]) Numbers[i][1] = MOD[1] - Numbers[i][1];
		}
	}
	
	register ull Value;
	for (i = 1; i <= Range; i++)
	{
		Value = 0;
		for (j = NumberN; j >= 0; j--)
		{
			Value = Value * i + Numbers[j][1];
			Value = (Value & MOD[1]) + (Value >> 31);
		}
		Value %= MOD[1];
		if (Value) continue;
		Value = 0;
		for (j = NumberN; j >= 0; j--) Value = (Value * i + Numbers[j][0]) % MOD[0];
		if (Value) continue;
		Solutions[Top++] = i;
	}
	
	cout << Top << endl;
	for (i = 0; i < Top; i++) printf("%d\n", Solutions[i]);
	
	return 0;
}

