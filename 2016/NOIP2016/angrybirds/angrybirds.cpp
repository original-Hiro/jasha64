//"CTSC" 2016
#include <fstream>
#include <algorithm>
#include <cmath>
using namespace std;

//搜索大赛！亦可赛艇 
ifstream cin("angrybirds.in");
ofstream cout("angrybirds.out");
const int N = 27;
const double eps = 1e-6;
struct Point {double x, y;} p[N];
int n, m, Res;
bool d[N];

inline double Abs(double x) {return x < 0 ? -x : x;}
inline bool Solve(Point p1, Point p2, double& a, double& b) //解方程 （坑爹） 
{
	double x1 = p1.x, x2 = p2.x, y1 = p1.y, y2 = p2.y; //ax1^2+bx1-y1=0 ax2^2+bx2-y2=0
	double a1 = y1 * x2 - y2 * x1, b1 = y2 * x1 * x1 - y1 * x2 * x2; //a, b的分子 
	double fenm = x1 * x2 * (x1 - x2); //分母 
	if (Abs(fenm) < eps) return false; //分母为0 
	if (Abs(a1) < eps) return false; //a = 0
	if (a1 / fenm > 0) return false; //a > 0
	a = a1 / fenm; b = b1 / fenm;
	return true;
}
inline bool On_Track(Point p, double a, double b) {return Abs(a * p.x * p.x + b * p.x - p.y) < eps;}
void Search(int cur) //正在发射第cur只小鸟 
{
	//调试输出 
//	cout << cur << ' ';
//	for (int i = 1; i <= n; i++) cout << d[i];
//	cout << endl;
	
	bool Complete = 1;
	for (int i = 1; i <= n; i++) Complete = Complete && d[i];
	if (Complete) {Res = cur - 1; return;}
	
	if (m == 1 && cur > ceil(n / 3.0 + 1)) return;
	if (cur >= Res) return;
	
	int kn = 0;
	bool dd[N];
	double a, b;
	copy(d, d + N, dd);
	for (int i = n; i > 1; i--)
	{
		if (d[i]) continue;
		for (int j = i - 1; j > 0; j--)
		{
			if (i == j) continue;
			if (d[j]) continue;
			if (!Solve(p[i], p[j], a, b)) continue;
			d[i] = d[j] = 1; kn = 2;
			for (int k = 1; k <= n; k++)
				if (!d[k] && On_Track(p[k], a, b)) {d[k] = 1; ++kn;}
			if (!(m == 2 && cur == 1 && kn < n / 3)) Search(cur + 1);
			copy(dd, dd + N, d);
		}
	}
	kn = 1;
	if (m == 2 && cur == 1 && kn < n / 3) return;
	for (int i = n; i > 0; i--)
		if (!d[i]) {d[i] = 1; Search(cur + 1); copy(dd, dd + N, d);}
}

int main()
{
	int T;
	
	cin >> T;
	while (T--)
	{
		Res = N;
		
		cin >> n >> m;
		for (int i = 1; i <= n; i++) cin >> p[i].x >> p[i].y;
		
		Search(1);
		
		cout << Res << endl;
	}
	
	return 0; //NOIP2016到此结束 尽人事听天命 
}

