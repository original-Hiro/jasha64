#include <iostream>
#include <algorithm>
#include <cmath>
#include <set>
#include <iterator>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> Pair;
int n;
ll X0, Y0;
ll X1, Y1;
set<Pair> know;
inline ll sqr(ll X) {return X * X;}
bool In(ll X0, ll Y0, ll X1, ll Y1, ll R) {return sqr(X0 - X1) + sqr(Y0 - Y1) <= R;}
bool check(ll X, ll Y, ll R)
{
    cout << "? " << X << ' ' << Y << ' ' << R << endl;
    int num;
    cin >> num;
    for (set<Pair>::iterator I = know.begin(); I != know.end(); I++)
        if (In(I -> first, I -> second, X, Y, R)) num--;
    return num;
}
ll GetR(ll X, ll Y)
{
    ll Low = 0, High = 1e13;
    while (Low < High)
    {
        ll Mid = (Low + High) / 2;
        if (check(X, Y, Mid)) High = Mid;
        else Low = Mid + 1;
    }
    return Low;
}
 
namespace One
{
    struct Point
    {
        double x, y;
        Point(double a = 0, double b = 0) : x(a), y(b) {}
        friend Point operator + (const Point &a, const Point &b) {return Point(a.x + b.x, a.y + b.y);}
        friend Point operator - (const Point &a, const Point &b) {return Point(a.x - b.x, a.y - b.y);}
        friend Point operator * (const Point &a, const double &b) {return Point(a.x * b, a.y * b);}
        friend Point operator * (const double a, const Point &b) {return b * a;}
        friend Point operator / (const Point &a, const double &b) {return Point(a.x / b, a.y / b);}
        double norm() {return sqrt(sqr(x) + sqr(y));}
    };
 
    Point rotate(const Point &p, double cost, double sint)
    {
        double x = p.x, y = p.y;
        return Point(x * cost - y * sint, x * sint + y * cost);
    }
    pair<Point, Point> crossPoint(Point ap, double ar, Point bp, double br)
    {
        double d = (ap - bp).norm();
        double cost = (ar * ar + d * d - br * br) / (2 * ar * d);
        double sint = sqrt(1 - cost * cost);
        Point v = (bp - ap) / d * ar;
        return pair<Point, Point>(ap + rotate(v, cost, -sint), ap + rotate(v, cost, sint));
    }
}
using namespace One;
 
void check_ans(ll X, ll Y)
{
    for (int i = -2; i <= 2; i++)
        for (int j = -2; j <= 2; j++)
        {
            ll x = X + i;
            ll y = Y + j;
            if (abs(x) > 1e6 || abs(y) > 1e6)continue;
            if (check(x, y, 0)) know.insert(Pair(x, y));
        }
}
int main()
{
	ios::sync_with_stdio(false);
	srand(19260817);
    X0 = rand() * rand() % 1000000;
    Y0 = rand() * rand() % 1000000;
    X1 = X0;
    Y1 = Y0 + 1;
 
    cin >> n;
    while (know.size() < n)
    {
        ll R0 = GetR(X0, Y0);
        ll R1 = GetR(X1, Y1);
        pair<Point, Point> ans = crossPoint(Point(X0, Y0), sqrt(R0), Point(X1, Y1), sqrt(R1));
        check_ans(ans.first.x, ans.first.y);
        check_ans(ans.second.x, ans.second.y);
    }
    
    cout << '!';
    for (set<Pair>::iterator I = know.begin(); I != know.end(); I++) cout << ' ' << I -> first << ' ' << I -> second;
    cout << endl;
    return 0;
}

