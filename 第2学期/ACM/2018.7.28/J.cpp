#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

const int N = 200007;
int T[N+N], top;
struct Segment
{
	int l, r, w, len, no;
	friend bool operator < (const Segment& a, const Segment& b)
	{
		return a.l < b.l || (a.l == b.l && a.r < b.r);
	}
} a[N];
long long f[N+N], h[N+N]; //f[t]: 1..t时间内最大收益值 
int g[N+N]; //g[t]: 按照f[t]的方案时在时间t参加的最后一场竞赛，打印方案用 
stack<int> Printer;

int main()
{
	ios::sync_with_stdio(false);
	
	//离散化 
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i].l >> a[i].r >> a[i].w; a[i].no = i+1; a[i].len = a[i].r - a[i].l;
		T[top++] = a[i].l; T[top++] = a[i].r;
	}
	sort(T, T+top);
	top = unique(T, T+top) - T;
	for (int i = 0; i < n; i++)
	{
		a[i].l = lower_bound(T, T+top, a[i].l) - T;
		a[i].r = lower_bound(T, T+top, a[i].r) - T;
	}
	sort(a, a+n);
	
	//DP
	g[0] = -1;
	for (int i = 0, j = 0; i < top; i++)
	{
		while (i == a[j].l)
		{
			int l = a[j].l, r = a[j].r, w = a[j].w, len = a[j].len;
			if (f[l] + w > f[r] || (f[l] + w == f[r] && h[l] + len < h[r]))
			{
				f[r] = f[l] + w;
				h[r] = h[l] + len;
				g[r] = j;
			}
			j++;
		}
		if ((!f[i+1] && !g[i+1]) || f[i] > f[i+1] || (f[i] == f[i+1] && h[i] < h[i+1]))
		{
			f[i+1] = f[i];
			h[i+1] = h[i];
			g[i+1] = g[i];
		}
	}
	
	//输出方案 
	for (int i = g[top-1]; i != -1; i = g[a[i].l]) Printer.push(a[i].no);
	cout << Printer.size() << ' ' << f[top-1] << ' ' << h[top-1] << endl;
	cout << Printer.top(); Printer.pop();
	while (!Printer.empty()) {cout << ' ' << Printer.top(); Printer.pop();}
		
	return 0;
}

