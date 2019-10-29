#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

const int N1 = 27, N2 = 2007, N3 = 100007;
int n, len, b[N1];
char s[N3], c[N1], Ans[N1];

inline bool Strcmp()
{
	int len = max(strlen(c), strlen(Ans));
	for (int i = 0; i < len; i++)
		if (c[i] > Ans[i]) return true;
		else if (c[i] < Ans[i]) return false;
	return false;
}
inline bool Strcmp(int S, int T)
{
	for (int i = S; i < T; i++)
		if (s[i] > c[i - S]) return true;
		else if (s[i] < c[i - S]) return false;
	return false;
}
inline void Update(int S, int T)
{
	memset(c, 0, sizeof(c));
	for (int i = S; i < T; i++) c[i - S] = s[i];
}
void DFS(int x)
{
	if (x == n)
	{
		memset(c, 0, sizeof(c));
		for (int i = 1; i <= n; i++)
			for (int j = b[i - 1]; j < b[i]; j++)
				if (Strcmp(j, b[i])) Update(j, b[i]);
		if (!Strcmp()) strcpy(Ans, c);
		return;
	}
	for (int i = b[x - 1] + 1; i < len; i++) {b[x] = i; DFS(x + 1);}
}
void Work1()
{
	b[n] = len; fill(Ans, Ans + N1, 'z');
	DFS(1);
	printf("%s\n", Ans);
}
struct Pair
{
	int a[2];
	
	Pair(int x = 0, int y = 0) {a[0] = x; a[1] = y;}
	friend bool operator < (const Pair& a, const Pair& b)
	{
		int len = max(a[1] - a[0], b[1] - b[0]);
		for (int i = 0; i < len; i++)
			if (s[a[0] + i] > s[b[0] + i]) return false;
			else if (s[a[0] + i] < s[b[0] + i]) return true;
		return a[1] - a[0] < b[1] - b[0];
	}
	friend bool operator == (const Pair& a, const Pair& b)
	{
		int len = a[1] - a[0];
		if (b[1] - b[0] != len) return false;
		for (int i = 0; i < len; i++)
			if (s[a[0] + i] != s[b[0] + i]) return false;
		return true;
	}
	int& operator [] (int x) {return a[x];}
	const int& operator [] (int x) const {return a[x];}
} G[N2 * N2];
bool Can(Pair a)
{
	int L = a[1] - a[0];
	char C[N2] = {};
	for (int i = a[0]; i < a[1]; i++) C[i - a[0]] = s[i];
	int Cnt = 1;
	for (int i = 0, j = 0; i < len; i++)
		if (j == L || s[i] > C[j]) {++Cnt; j = 0;}
		else if (s[i] == C[j]) ++j;
		else j = 0;
	return Cnt <= n;
}
void Work2()
{
	char c = 0, Top = 0;
	for (int i = 0; i < len; i++) c = max(c, s[i]);
	for (int i = 0; i < len; i++)
		if (s[i] == c)
			for (int j = i + 1; j <= len; j++) G[++Top] = Pair(i, j);
	sort(G + 1, G + Top + 1);
	int Res = Top, Low = 1, Mid, High = Top;
	while (Low <= High)
	{
		Mid = (Low + High) >> 1;
		if (Can(G[Mid])) {High = Mid - 1; Res = Mid;}
		else Low = Mid + 1;
	}
	for (int i = G[Res][0]; i < G[Res][1]; i++) printf("%c", s[i]);
	printf("\n");
}
void Work3()
{
	int Cnt, Ans_1 = 0;
	char c = 0;
	for (int i = 0; i < len; i++)
		if (s[i] > c) {Cnt = 1; c = s[i]; Ans_1 = i;}
		else if (s[i] == c) ++Cnt;
	if (n > Cnt) {cout << c << endl; return;}
	if (n == 1)
	{
		for (int i = Ans_1; i < len; i++) printf("%c", s[i]);
		printf("\n");
		return;
	}
	
}

int main()
{
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	
	cin >> n;
	scanf("%s", s); len = strlen(s);
	
	if (len <= 20) Work1();
	else if (len <= 2000) Work2();
	else Work3();
	
	return 0;
}

