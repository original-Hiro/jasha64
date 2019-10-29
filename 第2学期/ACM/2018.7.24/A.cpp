#include <iostream>
#include <cstdio>
#include <cctype>
#include <algorithm>
using namespace std;

inline int Read()
{
	int r = 0;
	char c = getchar();
	while (!isdigit(c)) c = getchar();
	while (isdigit(c)) {r = r*10 + c-'0'; c = getchar();}
	return r;
}

const int N = 100007;
struct Segment
{
	int l, r, v;
	long long t;
	friend bool operator < (const Segment& a, const Segment& b) {return a.l < b.l;}
} a[N];

int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		int n, k;
		cin >> n >> k;
		for (int i = 0; i < n; i++)
		{
			a[i].l = Read(); a[i].r = Read(); a[i].v = Read();
			a[i].r++; //改为左闭右开区间，这样计算元素个数的时候就不用+1 
			a[i].t = (long long)a[i].v * (a[i].r - a[i].l);
		}
		sort(a, a+n);
		
		long long Res = 0;
		//左端点与给定子线段i左端点重合
		long long cur = 0;
		for (int i = 0, j = 0; i < n; i++)
		{
			while (j < n && a[i].l + k >= a[j].r) {cur += a[j].t; j++;}
			long long tmp = j < n ? (long long)a[j].v * max(a[i].l + k - a[j].l, 0) : 0;
			cur += tmp; Res = max(Res, cur); cur -= tmp;
			cur -= a[i].t;
		}
		//右端点与给定子线段i右端点重合（此处倒过来以i = n-1...0循环，这样就可以和上面一种情况保持一致） 
		cur = 0;
		for (int i = n-1, j = n-1; i >= 0; i--)
		{
			while (j >= 0 && a[i].r - k <= a[j].l) {cur += a[j].t; j--;}
			long long tmp = j >= 0 ? (long long)a[j].v * max(a[j].r - (a[i].r - k), 0) : 0;
			cur += tmp; Res = max(Res, cur); cur -= tmp;
			cur -= a[i].t;
		}
		
		cout << Res << endl;
	}
	
	return 0;
}

