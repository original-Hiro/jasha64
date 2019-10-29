#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;
struct Point {int x, y;} a[200007];
inline ll Abs(ll x) {return x < 0 ? -x : x;}
inline ll Cross(ll x1, ll y1, ll x2, ll y2) {return x1 * y2 - x2 * y1;}
inline ll Area(Point b, Point c, Point d)
{
	ll x1 = c.x - b.x, y1 = c.y - b.y;
	ll x2 = c.x - d.x, y2 = c.y - d.y;
	return Abs(Cross(x1, y1, x2, y2));
}

int main()
{
	ios::sync_with_stdio(false);
	int n;
	
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i].x >> a[i].y;
	
	ll Res = (1ull << 63) - 1;
	for (int i = 0; i < n; i++) Res = min(Res, Area(a[i], a[(i+1)%n], a[(i+2)%n]));
	cout << Res << endl;
	
	return 0;
}

