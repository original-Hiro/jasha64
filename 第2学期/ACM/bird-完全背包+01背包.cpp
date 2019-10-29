#include <iostream>
#include <algorithm>
using namespace std;

const int N = 10007, INF = 2000000000;
int x[N], y[N]; /*表示在横坐标位置0～n-1上玩家点击屏幕后，小鸟在下一位置上升的高
度X，以及在这个位置上玩家不点击屏幕时，小鸟在下一位置下降的高度Y。*/
int l[N], h[N]; //L表示此管道缝隙的下边沿高度为L，H表示管道缝隙上边沿的高度。 
bool hasP[N];
int f[N][1007];

inline void Relax(int& a, int b) {if (a > b) a = b;}

int main()
{
	ios::sync_with_stdio(false);
	
	int n, m, k;
	cin >> n >> m >> k;
	for (int i = 0; i < n; i++) cin >> x[i] >> y[i];
	fill(l, l+n+1, -1); fill(h, h+n+1, m+1);
	for (int i = 0, p; i < k; i++) {cin >> p; cin >> l[p] >> h[p]; hasP[p] = 1;}
	
	fill(f[0], f[0]+N*1007, INF);
	fill(f[0]+1, f[0]+m+1, 0);
	int pCnt = 0;
	for (int i = 0; i < n; i++)
	{
		fill(f[i], f[i]+l[i]+1, INF);
		fill(f[i]+h[i], f[i]+m+1, INF);
		int r = *min_element(f[i], f[i]+m+1);
		if (r == INF) {cout << 0 << endl << pCnt << endl; return 0;}
		else if (hasP[i]) pCnt++;
		for (int j = 1; j <= m; j++) Relax(f[i+1][min(j+x[i], m)], f[i][j]+1);
		for (int j = 1; j <= m; j++) Relax(f[i+1][min(j+x[i], m)], f[i+1][j]+1);
		for (int j = y[i]+1; j <= m; j++) Relax(f[i+1][j-y[i]], f[i][j]);
	}
	
	int Res = *min_element(f[n], f[n]+m+1);
	cout << 1 << endl << Res << endl;
	
	return 0;
}

