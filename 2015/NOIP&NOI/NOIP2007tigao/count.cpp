#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

const int N = 200007;
int Number[N];
int Value[N], Count[N], Top = 0;

int main()
{
	freopen("count.in", "r", stdin);
	freopen("count.out", "w", stdout);
	
	int NumberN;
	int i;
	
	cin >> NumberN;
	for (i = 0; i < NumberN; i++) scanf("%d", &Number[i]);
	
	sort(Number, Number + NumberN);
	fill(Value, Value + N, -1);
	for (i = 0; i < NumberN; i++)
	{
		if (Value[Top] != Number[i])
		{
			++Top;
			Value[Top] = Number[i];
			Count[Top] = 1;
		}
		else Count[Top]++;
	}
	
	for (i = 1; i <= Top; i++) cout << Value[i] << ' ' << Count[i] << endl;
	
	return 0;
}

