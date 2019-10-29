#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

const int N = 100007, MAXC = 'z' + 1;
int sa[N], t[N], t2[N], c[N], r[N], h[N];
char s[N];

void Build_SA(int n, int m)
{
	int i, *x = t, *y = t2;
	memset(c, 0, sizeof(c));
	for (i = 0; i < n; i++) ++c[x[i] = s[i]];
	for (i = 1; i < m; i++) c[i] += c[i - 1];
	for (i = n - 1; i >= 0; i--) sa[--c[x[i]]] = i;
	for (int k = 1; k < n; k <<= 1)
	{
		int p = 0;
		for (i = n - k; i < n; i++) y[p++] = i;
		for (i = 0; i < n; i++)
			if (sa[i] >= k) y[p++] = sa[i] - k;
		memset(c, 0, sizeof(c));
		for (i = 0; i < n; i++) ++c[x[y[i]]];
		for (i = 1; i < m; i++) c[i] += c[i - 1];
		for (i = n - 1; i >= 0; i--) sa[--c[x[y[i]]]] = y[i];
		swap(x, y);
		p = 1; x[sa[0]] = 0;
		for (i = 1; i < n; i++)
			x[sa[i]] = (y[sa[i - 1]] == y[sa[i]] && y[sa[i - 1] + k] == y[sa[i] + k] ? p - 1 : p++);
		if (p == n) break;
		m = p;
	}
}
void GetHeight(int n)
{
	int i, j, k = 0;
	for (i = 1; i <= n; i++) r[sa[i]] = i;
	for (i = 0; i < n; i++)
	{
		if (k) --k;
		j = sa[r[i] - 1];
		while (s[i + k] == s[j + k]) ++k;
		h[r[i]] = k;
	}
}

int main()
{
	int n;
	scanf("%s", s); n = strlen(s);
	if (n == 1) {cout << 1 << endl; return 0;}
	
	Build_SA(n + 1, MAXC);
	GetHeight(n);
	
	cout << sa[1] + 1;
	for (int i = 2; i <= n; i++) cout << ' ' << sa[i] + 1;
	cout << endl << h[2];
	for (int i = 3; i <= n; i++) cout << ' ' << h[i];
	cout << endl;
	
	return 0;
}

