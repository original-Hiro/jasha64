#include <iostream>
#include <algorithm>
using namespace std;

struct People
{
	int Num, Scr;
	
	friend bool operator < (const People& a, const People& b)
	{
		if (a.Scr != b.Scr) return a.Scr > b.Scr;
		return a.Num < b.Num;
	}
} p[5007];

int main()
{
	int n, m, i;
	
	cin >> n >> m;
	m = (double)m * 1.5;
	for (i = 1; i <= n; i++) cin >> p[i].Num >> p[i].Scr;
	
	sort(p + 1, p + n + 1);
	while (p[m].Scr == p[m + 1].Scr) m++;
	cout << p[m].Scr << ' ' << m << endl;
	for (i = 1; i <= m; i++) cout << p[i].Num << ' ' << p[i].Scr << endl;
	
	return 0;
}

