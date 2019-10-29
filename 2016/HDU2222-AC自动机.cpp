#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

const int N = 500007, SIGMA_SIZE = 26;
int Res;
char c[57], s[1000007];
inline int idx(char c) {return c - 'a';}
struct WA_Automata
{
	int sz, ch[N][SIGMA_SIZE], f[N], v[N], last[N], t[N];
	
	int Newnode()
	{
		memset(ch[sz], 0, sizeof(ch[sz]));
		t[sz] = v[sz] = 0;
		return sz++;
	}
	void Clear() {sz = 0; Newnode();}
	void Insert()
	{
		int len = strlen(c), o = 0;
		for (int i = 0; i < len; i++)
		{
			int x = idx(c[i]);
			if (!ch[o][x]) ch[o][x] = Newnode();
			o = ch[o][x];
		}
		++t[o];
	}
	void Build()
	{
		queue<int> q;
		f[0] = 0;
		for (int c = 0; c < SIGMA_SIZE; c++)
		{
			int u = ch[0][c];
			if (u) {f[u] = last[u] = 0; q.push(u);}
		}
		while (!q.empty())
		{
			int o = q.front(); q.pop();
			for (int c = 0; c < SIGMA_SIZE; c++)
			{
				int u = ch[o][c];
//				if (!u) continue;
				if (!u) {ch[o][c] = ch[f[o]][c]; continue;}
				q.push(u);
				int v = f[o];
				while (v && !ch[v][c]) v = f[v];
				f[u] = ch[v][c];
				last[u] = t[f[u]] ? f[u] : last[f[u]];
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
		if (!p || v[p]) return;
		Res += t[p]; v[p] = true; Count(last[p]);
	}
} WA;

int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		Res = 0;
		WA.Clear();
		
		int n;
		cin >> n;
		for (int i = 1; i <= n; i++) {scanf("%s", c); WA.Insert();}
		WA.Build();
		
		scanf("%s", s);
		WA.Search();
		
		cout << Res << endl;
	}
	
	return 0;
}

