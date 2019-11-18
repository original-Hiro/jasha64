//"CTSC" 2016
#include <fstream>
#include <iomanip>
#include <algorithm>
using namespace std;

ifstream cin("classroom.in");
ofstream cout("classroom.out");
//n不是顶点数！n不是顶点数！！n不是顶点数！！！ 
const int N = 2007, V = 307, INF = 9000007;
int n, m, v, e, d[V][V], a[N], b[N];
double k[N], Res;

inline void Print(double v) {cout << setiosflags(ios::fixed) << setprecision(2) << v << endl;}
inline void Calc(double& Cur, int p)
{
	Cur += d[a[p]][a[p + 1]];
}
inline void Calc_Modified(double& Cur, int p)
{
	Cur += (d[a[p - 1]][b[p]] + d[b[p]][a[p + 1]]) * k[p];
	Cur += (d[a[p - 1]][a[p]] + d[a[p]][a[p + 1]]) * (1.0 - k[p]);
}
inline void Calc_Dual_Modified(double& Cur, int p)
{
	Cur += (d[a[p - 1]][b[p]] + d[b[p]][b[p + 1]] + d[b[p + 1]][a[p + 2]]) * k[p] * k[p + 1];
	Cur += (d[a[p - 1]][b[p]] + d[b[p]][a[p + 1]] + d[a[p + 1]][a[p + 2]]) * k[p] * (1.0 - k[p + 1]);
	Cur += (d[a[p - 1]][a[p]] + d[a[p]][b[p + 1]] + d[b[p + 1]][a[p + 2]]) * (1.0 - k[p]) * k[p + 1];
	Cur += (d[a[p - 1]][a[p]] + d[a[p]][a[p + 1]] + d[a[p + 1]][a[p + 2]]) * (1.0 - k[p]) * (1.0 - k[p + 1]);
}
//)(*&^%$#!
//记得注释调试输出 重不说三了 
void Work1() {for (int i = 1; i < n; i++) Calc(Res, i);}// cout << Res << endl;}
void Work2()
{
	Work1();
	double Cur;
	for (int i = 1; i <= n; i++)
	{
		Cur = 0;
		for (int j = 1; j < i - 1; j++) Calc(Cur, j);
		Calc_Modified(Cur, i);
		for (int j = i + 1; j < n; j++) Calc(Cur, j);
		Res = min(Res, Cur);
//		cout << i << ' ' << Cur << endl;
	}
}
void Work3()
{
	Work2();
	double Cur = 0;
	for (int i = 1; i < n; i++)
	{
		Cur = 0;
		for (int k = 1; k < i - 1; k++) Calc(Cur, k);
		Calc_Dual_Modified(Cur, i);
		for (int k = i + 2; k < n; k++) Calc(Cur, k);
		Res = min(Res, Cur);
//		cout << i << ' ' << i + 1 << ' ' << Cur << endl;
		for (int j = i + 2; j <= n; j++)
		{
			Cur = 0;
			for (int k = 1; k < i - 1; k++) Calc(Cur, k);
			Calc_Modified(Cur, i);
			for (int k = i + 1; k < j - 1; k++) Calc(Cur, k);
			Calc_Modified(Cur, j);
			for (int k = j + 1; k < n; k++) Calc(Cur, k);
			Res = min(Res, Cur);
//			cout << i << ' ' << j << ' ' << Cur << endl;
		}
	}
}

int main()
{
	cin >> n >> m >> v >> e;
	if (n == 1) {Print(0); return 0;}
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= n; i++) cin >> b[i];
	for (int i = 1; i <= n; i++) cin >> k[i];
	for (int i = 1; i <= v; i++)
		for (int j = 1; j <= v; j++)
			if (i != j) d[i][j] = INF;
	for (int i = 0, a, b, c; i < e; i++)
	{
		cin >> a >> b >> c;
		d[a][b] = min(d[a][b], c); d[b][a] = min(d[b][a], c);
	}
	for (int k = 1; k <= v; k++)
		for (int i = 1; i <= v; i++)
			for (int j = 1; j <= v; j++) d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
	
	if (m == 0) Work1();
	else if (m == 1) Work2();
	else if (m == 2) Work3();
	
	Print(Res);
	
	return 0; //噫吁嚱 我要死了 
}

