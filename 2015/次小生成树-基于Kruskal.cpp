#include <iostream>
#include <algorithm>
using namespace std;

const int N = 5007;
int f[107];
bool v[N]; 

struct Edge
{
	int a, b, c;
	
	friend istream& operator >> (istream& cin, Edge& a)
	{
		cin >> a.a >> a.b >> a.c;
		return cin;
	} 
	friend bool operator < (const Edge& a, const Edge& b) {return a.c < b.c;}
} e[N];

int Find(int x)
{
	if (f[x] != x) return f[x] = Find(f[x]);
	return x;
}

int main()
{
	int n, m, i, j, Ans, Res = 10000007;
	
	cin >> n >> m;
	for (i = 0; i < m; i++) cin >> e[i]; 
	
	sort(e, e + m);
	for (i = 1; i <= n; i++) f[i] = i;
	Res = 0;
	for (j = 0; j < m; j++)
		if (Find(e[j].a) != Find(e[j].b)) {f[Find(e[j].a)] = Find(e[j].b); v[j] = true;}
	for (i = 0; i < m; i++)
	{
		if (!v[i]) continue;
		for (j = 1; j <= n; j++) f[j] = j;
		Ans = 0;
		for (j = 0; j < m; j++)
			if (j != i && Find(e[j].a) != Find(e[j].b))
			{
				f[Find(e[j].a)] = Find(e[j].b);
				Ans += e[j].c;
			}
		Res = min(Res, Ans); 
	}
	
	cout << Res << endl;
	
	return 0;
} 

