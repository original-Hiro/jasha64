#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;

const int N = 100007; 
int X1, Y1, X2, Y2;
struct Target {int d1, d2;} t1[N], t2[N];

inline int Dist(int a, int b) {return a * a + b * b;}
bool cmp1(const Target& a, const Target& b) {return a.d1 < b.d1;}
bool cmp2(const Target& a, const Target& b) {return a.d2 < b.d2;}

int main()
{
	int n, i, j, x, y, Res = 0x7fffffff;
	
	cin >> X1 >> Y1 >> X2 >> Y2 >> n;
	for (i = 0; i < n; ++i)
	{
		scanf("%d%d", &x, &y);
		t1[i].d1 = t2[i].d1 = Dist(x - X1, y - Y1);
		t1[i].d2 = t2[i].d2 = Dist(x - X2, y - Y2);
	}
	
	sort(t1, t1 + n, cmp1); sort(t2, t2 + n, cmp2);
	j = n - 1;
	for (i = 0; i < n; ++i)
	{
		while (t2[j].d1 <= t1[i].d1 && j >= 0) --j;
		if (j == -1) Res = min(Res, t1[i].d1);
		else Res = min(Res, t1[i].d1 + t2[j].d2);
	}
	
	cout << Res << endl;
	
	return 0;
}

