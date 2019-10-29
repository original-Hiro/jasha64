#include <iostream>
#include <algorithm>
#include <cstdio>
#include <stack>
using namespace std;

const int N = 200007;
int a[N], f[N], DFN[N], Low[N], idx, Res = N;
bool ins[N];
stack<int> s;

void Tarjan(int x)
{
	DFN[x] = Low[x] = ++idx;
	s.push(x); ins[x] = true;
	if (!DFN[a[x]]) {Tarjan(a[x]); Low[x] = min(Low[x], Low[a[x]]);}
	else if (ins[a[x]]) Low[x] = min(Low[x], DFN[a[x]]);
	if (Low[x] == DFN[x])
	{
		int i;
		do {
			i = s.top(); s.pop(); ins[i] = false;
			++f[x];
		} while (i != x);
		if (f[x] > 1) Res = min(Res, f[x]);
	}
}

int main()
{
	freopen("message.in", "r", stdin);
	freopen("message.out", "w", stdout);
	
	int n, i;
	
	cin >> n;
	for (i = 1; i <= n; ++i) scanf("%d", &a[i]);
	
	for (i = 1; i <= n; ++i)
		if (!DFN[i]) Tarjan(i);
	
	cout << Res << endl;
	
	return 0;
}

