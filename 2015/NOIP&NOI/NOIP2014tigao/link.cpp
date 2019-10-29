#include <fstream>
using namespace std;

ifstream cin("link.in");
ofstream cout("link.out");
const int M = 200005, MOD = 10007;

struct Road
{
	int x, y;
	
	Road() {x = y = 0;}
} r[M];
struct Point
{
	int data, sum, max1, max2;
		
	Point() {data = sum = max1 = max2 = 0;}
} p[M];

int main()
{
	int n;
	int i, ans1 = 0, ans2 = 0;
	
	cin >> n;
	for (i = 1; i < n; i++) cin >> r[i].x >> r[i].y;
	for (i = 1; i <= n; i++) cin >> p[i].data;
	
	for (i = 1; i < n; i++)
	{
		p[r[i].x].sum += p[r[i].y].data;
		p[r[i].y].sum += p[r[i].x].data;
		if (p[r[i].y].data > p[p[r[i].x].max1].data)  {p[r[i].x].max2 = p[r[i].x].max1; p[r[i].x].max1 = r[i].y;}
		if (p[r[i].y].data > p[p[r[i].x].max2].data && p[r[i].x].max1 != r[i].y)  p[r[i].x].max2 = r[i].y;
		if (p[r[i].x].data > p[p[r[i].y].max1].data)  {p[r[i].y].max2 = p[r[i].y].max1; p[r[i].y].max1 = r[i].x;}
		if (p[r[i].x].data > p[p[r[i].y].max2].data && p[r[i].y].max1 != r[i].x)  p[r[i].y].max2 = r[i].x;
	}
	for (i = 1; i < n; i++)
	{
		ans2 += (p[r[i].y].sum - p[r[i].x].data) % MOD * p[r[i].x].data % MOD;
		ans2 += (p[r[i].x].sum - p[r[i].y].data) % MOD * p[r[i].y].data % MOD;
		ans2 %= MOD;
		ans1 = max(ans1, p[p[i].max1].data * p[p[i].max2].data);
	}
	ans1 = max(ans1, p[p[n].max1].data * p[p[n].max2].data);
	
	cout << ans1 << ' ' << ans2 << endl;
	
	return 0;
}

