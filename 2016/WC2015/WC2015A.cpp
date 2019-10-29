#include <iostream>
#include <algorithm>
using namespace std;

const int N = 17, M = 27, K = 1048577;
struct Edge {int s, t, d, Next;} e[M];
int Head[N], o[K], Top, n, m, s, t;
bool a[M], b[N];

bool DFS(int x)
{
	if (x == t) return false;
	b[x] = true;
	int i = Head[x];
	while (i)
	{
		if (a[i] && !b[e[i].t] && !DFS(e[i].t)) return false;
		i = e[i].Next;
	}
	return true;
}
void Try(int BITS)
{
	int Res = 0, i;
	fill(a + 1, a + m + 1, true);
	for (i = 1; i <= m; i++)
		if ((1 << (i - 1)) & BITS) {Res += e[i].d; a[i] = false; continue;}
	fill(b + 1, b + n + 1, false);
	if (DFS(s)) o[Top++] = Res;
}

int main()
{
	ios::sync_with_stdio(false);
	
	int k;
	cin >> n >> m >> s >> t >> k;
	for (int i = 1; i <= m; i++)
	{
		cin >> e[i].s >> e[i].t >> e[i].d;
		e[i].Next = Head[e[i].s]; Head[e[i].s] = i;
	}
	
	const int ALL_BITS = (1 << m) - 1;
	for (int i = 1; i <= ALL_BITS; i++) Try(i);
	
	sort(o, o + Top);
	if (Top < k)
	{
		for (int i = 0; i < Top; i++) cout << o[i] << endl;
		cout << -1 << endl;
	}
	else for (int i = 0; i < k; i++) cout << o[i] << endl;
	
	return 0;
}

