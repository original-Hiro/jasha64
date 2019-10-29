#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

typedef const int& int_;
const int N = 107, M = 10007;
int To[M], Head[N], Next[M], DFN[N], Low[N], f[N], InDegree[N], OutDegree[N], idx, cnt;
bool ins[N];
stack<int> s;

void Tarjan(int_ x)
{
	int i;
	
	DFN[x] = Low[x] = ++idx;
	s.push(x); ins[x] = true;
	i = Head[x];
	while (i)
	{
		if (!DFN[To[i]]) {Tarjan(To[i]); Low[x] = min(Low[x], Low[To[i]]);}
		else if (ins[To[i]]) Low[x] = min(Low[x], DFN[To[i]]);
		i = Next[i];
	}
	if (DFN[x] == Low[x])
	{
		++cnt;
		do {
			i = s.top(); s.pop(); ins[i] = false;
			f[i] = x;
		} while (i != x);
	}
}

int main()
{
	int n, i, j, k = 0;
	
	cin >> n;
	for (i = 1; i <= n; ++i)
		while (cin >> j && j) {To[++k] = j; Next[k] = Head[i]; Head[i] = k;}
	
	for (i = 1; i <= n; ++i)
		if (!DFN[i]) Tarjan(i);
	for (j = 1; j <= n; ++j)
	{
		i = Head[j];
		while (i)
		{
			if (f[j] != f[To[i]]) {++InDegree[f[To[i]]]; ++OutDegree[f[j]];}
			i = Next[i];
		}
	}
	if (cnt == 1) {cout << 1 << endl << 0 << endl; return 0;}
	j = k = 0;
	for (i = 1; i <= n; ++i)
	{
		if (f[i] != i) continue;
		if (!InDegree[f[i]]) ++j;
		if (!OutDegree[f[i]]) ++k;
	}
	k = max(k, j);
			
	cout << j << endl << k << endl;
	
	return 0;
}

