#include <fstream>
#include <algorithm>
using namespace std;

ifstream cin("swiss.in");
ofstream cout("swiss.out");
const int N = 200007;
int n;
struct people
{
	int num, scr, str;
	
	friend bool operator < (const people& a, const people& b)
	{
		if (a.scr != b.scr) return a.scr > b.scr;
		else return a.num < b.num;
	}
} p[N], win[N], lose[N], cache[N];

inline void Merge()
{
	int top1 = 1, top2 = 1, top = 1;
	while (top1 <= n || top2 <= n)
	{
		if (top2 > n || (top1 <= n && win[top1] < lose[top2])) p[top++] = win[top1++];
		else p[top++] = lose[top2++];
	}
}

int main()
{
	int m, r, q;
	int i, j;
	
	cin >> n >> r >> q;
	m = n << 1;
	for (i = 1; i <= m; i++)
	{
		cin >> p[i].scr;
		p[i].num = i;
	}
	for (i = 1; i <= m; i++) cin >> p[i].str;
	
	sort(p + 1, p + m + 1);
	for (i = 0; i < r; i++)
	{
		for (j = 1; j <= n; j++)
			if (p[j * 2].str > p[j * 2 - 1].str)
			{
				p[j * 2].scr++;
				win[j] = p[j * 2];
				lose[j] = p[j * 2 - 1];
			}
			else {
				p[j * 2 - 1].scr++;
				win[j] = p[j * 2 - 1];
				lose[j] = p[j * 2];
			}
		Merge();
	}
	sort(p + 1, p + m + 1);
	
	cout << p[q].num << endl;
	
	return 0;
}

