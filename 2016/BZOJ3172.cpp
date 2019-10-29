#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

const int N = 1000207, SIGMA_SIZE = 26;
int Res[207], r[207];
char c[N], s[N];

inline int idx(char c) {return c - 'a';}
struct RE_Automaton
{
	int sz, ch[N][SIGMA_SIZE], t[N], f[N], last[N];
	
	int Newnode()
	{
		memset(ch[sz], 0, sizeof(ch[sz]));
		t[sz] = 0;
		return sz++;
	}
	void Clear() {sz = 0; Newnode();}
	void Insert(int x)
	{
		int len = strlen(c), o = 0;
		for (int i = 1; i < len; i++)
		{
			int v = idx(c[i]);
			if (!ch[o][v]) ch[o][v] = Newnode();
			o = ch[o][v];
		}
		if (t[o]) r[x] = t[o];
		else t[o] = x;
	}
	void Build()
	{
		queue<int> q;
		for (int i = 0; i < SIGMA_SIZE; i++)
		{
			int u = ch[0][i];
			if (!u) continue;
			f[u] = last[u] = 0;
			q.push(u);
		}
		while (!q.empty())
		{
			int v = q.front(); q.pop();
			for (int i = 0; i < SIGMA_SIZE; i++)
			{
				int u = ch[v][i];
//				if (!u) continue;
				if (!u) {ch[v][i] = ch[f[v]][i]; continue;}
				int o = f[v];
				while (o && !ch[o][i]) o = f[o];
				f[u] = ch[o][i];
				last[u] = t[f[u]] ? f[u] : last[f[u]];
				q.push(u);
			}
		}
	}
	void Search()
	{
		int len = strlen(s), j = 0;
		for (int i = 0; i < len; i++)
		{
			int x = idx(s[i]);
//			while (j && !ch[j][x]) j = f[j];
			j = ch[j][x];
			if (t[j]) Count(j);
			else if (last[j]) Count(last[j]);
		}
	}
	void Count(int p)
	{
		if (!p) return;
		++Res[t[p]]; Count(last[p]);
	}
} RE;

int main()
{
	int n;
	RE.Clear();
	
	cin >> n;
	for (int i = 1; i <= n; i++) {scanf("%s", c + 1); c[0] = 1; strcat(s, c); RE.Insert(i);}
	RE.Build();
	
	RE.Search();
	
	for (int i = 1; i <= n; i++)
		if (r[i]) Res[i] = Res[r[i]];
	for (int i = 1; i <= n; i++) cout << Res[i] << endl;
	
	return 0;
}

