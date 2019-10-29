#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

const int INF = 1000007;
int n, Min = INF, Max = 0;
bool f[1 << 21 | 1], e[1000007];

inline int Find_Max(int s)
{
	int i = s;
	while (i <= n)
		if (f[i << 1 | 1]) i = i << 1 | 1;
		else i <<= 1;
	if (!f[i]) return 0;
	else return i - n;
}
inline int Find_Min(int s)
{
	int i = s;
	while (i <= n)
		if (f[i << 1]) i <<= 1;
		else i = i << 1 | 1;
	if (!f[i]) return INF;
	else return i - n;
}
inline void Insert()
{
	int c, i;
	scanf("%d", &c);
	if (e[++c]) return;
	
	e[c] = true;
	Max = max(Max, c); Min = min(Min, c);
	
	for (i = c + n; i; i >>= 1) f[i] = true;
}
inline void Delete()
{
	int c, i;
	scanf("%d", &c);
	if (!e[++c]) return;
	
	e[c] = false;
	
	f[i = c + n] = false;
	for (i >>= 1; i; i >>= 1)
		f[i] = f[i << 1] | f[i << 1 | 1];
	
	if (c == Max) Max = Find_Max(1);
	if (c == Min) Min = Find_Min(1);
}
inline void Print_Min()
{
	if (Min == INF) printf("-1\n");
	else printf("%d\n", Min - 1);
}
inline void Print_Max() {printf("%d\n", Max - 1);}
inline void Find_Prev()
{
	int c, i, o;
	scanf("%d", &c); ++c;
	
	o = c + n;
	i = o >> 1;
	while (i > 1)
	{
		if ((~o & 1) && f[(i << 1) - 1]) {i = (i << 1) - 1; break;}
		if ((o & 1) && f[i << 1]) {i <<= 1; break;}
		o >>= 1; i = o >> 1;
	}
	
	if (i == 1) {printf("-1\n"); return;}
	else printf("%d\n", Find_Max(i) - 1);
}
inline void Find_Next()
{
	int c, i, o;
	scanf("%d", &c); ++c;
	
	o = c + n;
	i = o >> 1;
	while (i > 1)
	{
		if ((o & 1) && f[(i + 1) << 1]) {i = (i + 1) << 1; break;}
		if ((~o & 1) && f[i << 1 | 1]) {i = i << 1 | 1; break;}
		o >>= 1; i = o >> 1;
	}
	
	if (i == 1) {printf("-1\n"); return;}
	else printf("%d\n", Find_Min(i) - 1);
}
inline void Find()
{
	int c;
	scanf("%d", &c);
	
	if (e[++c]) printf("1\n");
	else printf("-1\n");
}

int main()
{
	int m, q;
	
	cin >> n >> m;
	while (m--)
	{
		scanf("%d", &q);
		switch (q)
		{
			case 1: Insert(); break;
			case 2: Delete(); break;
			case 3: Print_Min(); break;
			case 4: Print_Max(); break;
			case 5: Find_Prev(); break;
			case 6: Find_Next(); break;
			case 7: Find(); break;
		}
	}
	
	return 0;
}

