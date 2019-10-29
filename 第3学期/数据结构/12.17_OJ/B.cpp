#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;
struct Line
{
    ll A, B; //下面用到A和B相乘的地方太多了，为编程方便起见，且此题对空间要求不高，干脆直接声明成long long得了，避免反复写强制类型转换 
    friend bool operator < (const Line& a, const Line& b) {return a.A * b.B < b.A * a.B;}
    friend bool operator == (const Line& a, const Line& b) {return a.A == b.A && a.B == b.B;}
} line[100001];
ll gcd(ll a, ll b)
{
    if (b == 0) return a;
    return gcd(b, a % b);
}
inline ll C2(ll x) {return x * (x - 1) / 2;}
inline ll dot(Line a, Line b) {return a.A * b.A + a.B * b.B;}

int main()
{
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    ll A0 = 0, B0 = 0; //A、B为0的直线计数 
    for (int i = 0, disc; i < n; i++)
    {
        ll& A = line[i].A;
        ll& B = line[i].B;
        cin >> A >> B >> disc; //discard C
        if (A == 0) {A0++; i--; n--; continue;}
        else if (B == 0) {B0++; i--; n--; continue;} //先把A或B为0的单独踢出去，从而不需特判 
        int c = gcd(A, B); A /= c; B /= c;
        if (A < 0) {A = -A; B = -B;} //不能和上一行交换，因为gcd可能是-1，从而又导致A变回负数 
	}
    
    sort(line, line + n);
    ll Res1 = C2(A0) + C2(B0); //n <= 1e5, res1 ~ n*n, 要开long long 
    for (int i = 0, j; i < n; i += j)
	{
        j = 0;
        while (i + j < n && line[i] == line[i+j]) j++;
        Res1 += C2(j);
    }
	ll Res2 = A0 * B0;
	int bd = lower_bound(line, line + n, (Line){.A = 1, .B = 0}) - line; //匿名结构体对象乱序声明方法，比顺序声明更直观、更不易错 
	for (int i = 0, j, k = bd; i < bd && k < n; i += j)
	{
		int cnt = 0;
		j = 0;
        while (i + j < bd && line[i] == line[i+j]) j++; //统计出和i相同角度的直线条数 
        while (k < n && dot(line[i], line[k]) > 0) k++;
        while (k < n && dot(line[i], line[k]) == 0) {k++; cnt++;} //统计出和k相同角度的直线条数 
        Res2 += (long long)j * cnt; //相乘 
    }
	
    cout << Res1 << ' ' << Res2 << endl;
    return 0;
}

