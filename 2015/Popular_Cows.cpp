#include <iostream>
#include <algorithm>
#include <cstdio>
#include <stack>
#include <cstring>
using namespace std;

typedef const int& int_;
const int N = 10007, M = 50007;
int m, l[M], r[M], idx, Next[M], Head[N], b[N], DFN[N], Low[N], Size[N], OutDegree[N];
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
		if (!DFN[r[i]]) {Tarjan(r[i]); Low[x] = min(Low[x], Low[r[i]]);}
		else if (ins[r[i]]) Low[x] = min(Low[x], DFN[r[i]]);
		i = Next[i];
	}
	if (Low[x] == DFN[x])
		do {
			i = s.top(); s.pop(); ins[i] = false;
			b[i] = x; ++Size[x];
		} while (i != x);
}

int main()
{
	int i, n, a;
	bool o;
	
	while (cin >> n >> m)
	{
		o = idx = 0;
		memset(DFN, 0, sizeof(DFN));
		memset(Size, 0, sizeof(Size));
		memset(OutDegree, 0, sizeof(OutDegree));
		
		for (i = 1; i <= m; ++i)
		{
			scanf("%d%d", &l[i], &r[i]);
			Next[i] = Head[l[i]]; Head[l[i]] = i;
		}
		
		for (i = 1; i <= n; ++i)
			if (!DFN[i]) Tarjan(i);
		for (i = 1; i <= m; ++i) r[i] = b[r[i]];
		for (i = 1; i <= m; ++i)
			if (b[l[i]] != b[r[i]]) ++OutDegree[b[l[i]]];
		for (i = 1; i <= n; ++i)
			if (b[i] == i && !OutDegree[i])
			{
				o = !o; a = i;
				if (!o) break;
			}
		if (!o) {cout << 0 << endl; continue;}
		
		cout << Size[a] << endl;
	}
	
	return 0;
}

