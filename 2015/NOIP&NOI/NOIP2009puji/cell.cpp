#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

const int N = 17, INF = 100000007;
int p[N], t[N], p2[N], t2[N], Top, Top2;

int main()
{
	int a, n, m1, m2, i, j, Res = INF, CurRes;
	
	cin >> n >> m1 >> m2;
	j = sqrt(m1) + 1;
	for (i = 2; i <= j; ++i)
		if (m1 % i == 0)
		{
			p[Top] = i; t[Top] = 1; m1 /= i;
			while (m1 % i == 0) {m1 /= i; ++t[Top];}
			++Top;
		}
	if (m1 > 1) {p[Top] = m1; t[Top++] = 1;}
	for (i = 0; i < Top; ++i) t[i] *= m2;
	while (n--)
	{
		cin >> a;
		Top2 = 0;
		j = sqrt(a) + 1;
		for (i = 2; i <= j; ++i)
			if (a % i == 0)
			{
				p2[Top2] = i; t2[Top2] = 1; a /= i;
				while (a % i == 0) {a /= i; ++t2[Top2];}
				++Top2;
			}
		if (a > 1) {p2[Top2] = a; t2[Top2++] = 1;}
		CurRes = 0;
		for (i = j = 0; i < Top; ++i)
		{
			while (p2[j] < p[i] && j < Top2) ++j;
			if (j == Top2 && i < Top) break;
			if (p2[j] > p[i]) {CurRes = INF; break;}
			if (p[i] == p2[j]) CurRes = max(CurRes, t[i] % t2[j] ? t[i] / t2[j] + 1 : t[i] / t2[j]);
		}
		if (j == Top2 && i < Top) CurRes = INF;
		Res = min(Res, CurRes);
	}
	
	if (Res == INF) cout << -1 << endl;
	else cout << Res << endl;
	
	return 0;
}

