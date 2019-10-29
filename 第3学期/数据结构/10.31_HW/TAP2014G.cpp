//SPOJ - gallantry
//贪心 
//先排序战斗力数组，两人选人的方式一定是从高往低，而且显然第i轮会选第(2i-1)大和第2i大 
//一轮中让对方先选意味着两方战斗力的差值将会减少2倍的这一轮两个选手的差值，而且这一决策没有后效性 
//所以，在差值尽可能小的时候让对方先选，是最优策略，这样就得到了贪心算法 
#include <iostream>
#include <algorithm>
using namespace std;

int a[10001], b[5001];

int main()
{
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];
	
	sort(a, a+n);
	for (int i = 0; i < n; i += 2) b[i/2] = a[i+1] - a[i];
	int m = n/2;
	sort(b, b+m);
	int d = 0;
	for (int i = 0; i < m; i++) d += b[i];
	if (d <= 0) {cout << -1 << endl; return 0;}
	int p = 0;
	do {
		d -= b[p];
		d -= b[p];
		p++;
	} while (d > 0 && p < m);
	if (p >= m && d > 0) cout << m << endl;
	else cout << p-1 << endl;
	return 0;
}

