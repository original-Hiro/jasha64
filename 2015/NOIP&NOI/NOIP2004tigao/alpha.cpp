#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

const int N = 97;
int n;
int v[N];
bool d[N], OK;
char t[N];
string a, b, s;

bool Check()
{
	int i, Cache, Jinwei = 0;
	for (i = n - 1; i >= 0; --i)
	{
		Cache = v[(int)a[i]] + v[(int)b[i]] + Jinwei;
		Jinwei = 0;
		if (Cache >= n) {Jinwei = Cache / n; Cache %= n;}
		if (Cache != v[(int)s[i]]) return false;
	}
	if (Jinwei) return false;
	return true;
}
bool Cont()
{
	int i, c1, c2, c3, c;
	for (i = n - 1; i >= 0; --i)
	{
		c1 = v[(int)a[i]]; c2 = v[(int)b[i]]; c3 = v[(int)s[i]];
		if (c1 != -1 && c2 != -1 && c3 != -1)
		{
			c = (c1 + c2) % n;
			if (c != c3 && (i == n - 1 || (c + 1) % n != c3)) return false;
		}
		if (c1 != -1 && c2 != -1 && c3 == -1)
		{
			c = (c1 + c2) % n;
			if (d[c] && (i == n - 1 || d[(c + 1) % n])) return false;
		}
		if (c1 != -1 && c2 == -1 && c3 != -1)
		{
			c = (c3 - c1 + n) % n;
			if (d[c] && (i == n - 1 || d[(c - 1 + n) % n])) return false;
		}
		if (c1 == -1 && c2 != -1 && c3 != -1)
		{
			c = (c3 - c2 + n) % n;
			if (d[c] && (i == n - 1 || d[(c - 1 + n) % n])) return false;
		}
	}
	return true;
}
void Solve(int Cur)
{
	if (Cur == n && Check()) OK = true;
	else for (int i = n - 1; i >= 0; --i)
		if (!d[i])
		{
			v[(int)t[Cur]] = i;
			if (!Cont()) {v[(int)t[Cur]] = -1; continue;}
			d[i] = true;
			Solve(Cur + 1);
			if (OK) return;
			d[i] = false;
			v[(int)t[Cur]] = -1;
		}
}

int main()
{
	int i, Top = 0;
	
	cin >> n >> a >> b >> s;
	for (i = n - 1; i >= 0; --i)
	{
		if (!v[(int)s[i]]) {t[Top++] = s[i]; v[(int)s[i]] = -1;}
		if (!v[(int)b[i]]) {t[Top++] = b[i]; v[(int)b[i]] = -1;}
		if (!v[(int)a[i]]) {t[Top++] = a[i]; v[(int)a[i]] = -1;}
	}
	
	Solve(0);
	
	cout << v['A'];
	for (i = 'B'; i < 'A' + n; ++i) cout << ' ' << v[i];
	cout << endl;
	
	return 0;
}

