//POJ 2524 Ubiquitous Religions
//²¢²é¼¯ 
#include <iostream>
#include <cstdio>
#include <cctype>
#include <cstring>
using namespace std;

inline int Read()
{
	int r = 0;
	char c = getchar();
	while (!isdigit(c)) c = getchar();
	while (isdigit(c)) {r = r * 10 + c - '0'; c = getchar();}
	return r;
}
const int N = 50001;
int f[N];
int Find(int x)
{
	if (f[x] == x) return x;
	return f[x] = Find(f[x]);
}
bool vis[N];

int main()
{
	int n, m, kase = 0;
	while (cin >> n >> m && n != 0)
	{
		for (int i = 1; i <= n; i++) f[i] = i;
		memset(vis, 0, sizeof(vis));
		
		for (int i = 0, a, b; i < m; i++)
		{
			a = Read(); b = Read();
			f[Find(a)] = Find(b);
		}
		
		int Res = 0;
		for (int i = 1; i <= n; i++)
			if (!vis[Find(i)]) {vis[Find(i)] = 1; Res++;}
		cout << "Case " << ++kase << ": " << Res << endl;
	}
	
	return 0;
}

