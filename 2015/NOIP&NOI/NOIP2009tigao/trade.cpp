#include <iostream>
#include <algorithm>
#include <cstdio>
#include <queue>
using namespace std;

const int N = 100007, M = 1000007;
int a[N], b[N], s[N], l[M], r[M], Head[N], Next[M], C_Head[N], C_Next[M];
bool inq[N];
queue<int> q;

int main()
{
	int n, m, i, c, Res = 0;
	
	cin >> n >> m;
	for (i = 1; i <= n; i++) scanf("%d", &a[i]);
	for (i = 1; i <= m; i++)
	{
		scanf("%d%d%d", &l[i], &r[i], &c);
		if (c == 1) {Next[i] = Head[l[i]]; Head[l[i]] = i; C_Next[i] = C_Head[r[i]]; C_Head[r[i]] = i;}
		else {
			Next[i] = Head[l[i]];
			Head[l[i]] = i;
			C_Next[i] = C_Head[r[i]];
			C_Head[r[i]] = i;
			m++; i++; l[i] = r[i - 1]; r[i] = l[i - 1];
			Next[i] = Head[l[i]];
			Head[l[i]] = i;
			C_Next[i] = C_Head[r[i]];
			C_Head[r[i]] = i;
		}
	}
	
	fill(b + 1, b + n + 1, 107);
	q.push(1); inq[1] = true;
	while (!q.empty())
	{
		c = q.front(); q.pop(); inq[c] = false;
		b[c] = min(b[c], a[c]);
		i = Head[c];
		while (i)
		{
			if (b[r[i]] > b[l[i]])
			{
				b[r[i]] = b[l[i]];
				if (!inq[r[i]]) {q.push(r[i]); inq[r[i]] = true;}
			}
			i = Next[i];
		}
	}
	q.push(n); inq[n] = true;
	while (!q.empty())
	{
		c = q.front(); q.pop(); inq[c] = false;
		s[c] = max(s[c], a[c]);
		i = C_Head[c];
		while (i)
		{
			if (s[l[i]] < s[r[i]])
			{
				s[l[i]] = s[r[i]];
				if (!inq[l[i]]) {q.push(l[i]); inq[l[i]] = true;}
			}
			i = C_Next[i];
		}
	}
	
	for (i = 1; i <= n; i++) Res = max(Res, s[i] - b[i]);
	cout << Res << endl;
	
	return 0;
}

