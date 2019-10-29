#include <fstream>
#include <string>
#include <vector>
using namespace std;

ifstream cin("game8.in");
ofstream cout("game8.out");
const int N = 1007;
char a[N][N];
struct X
{
	int x, y;
	X() {x = y = 0;}
	X(const int& a, const int& b) {x = a; y = b;}
};
vector<X> res;

int main()
{
	int n, m;
	int i, j, x = 1, y = 1, cnt = 0, cache;
	string s;
	bool needed = 0;
	
	cin >> n >> m;
	for (i = 0; i < 6; i++) cin >> cache;
	for (i = 1; i <= n; i++)
		for (j = 1; j <= m; j++) cin >> a[i][j];
	
	cout << 1 << endl;
	while (x < n && y < m)
	{
		while (y < m)
		{
			if (a[x][y] != '5' && a[x][y] != '6')
			{
				cnt--;
				res.erase(res.end() - 1);
				needed = 1;
			}
			s += a[x][y]; res.push_back(X(x, y)); y++; cnt++;
			if (needed) {cnt--;	res.erase(res.end() - 1); needed = 0;}
			if ((a[x][y] != '5' && a[x][y] != '6') || a[x][y] == a[x][y - 1]) {x++; y--;}
			if (a[x][y] != '5' && a[x][y] != '6')
			{
				cnt--;
				res.erase(res.end() - 1);
				y--;
			}
		}
		res.push_back(X(x, y)); cnt++; s += a[x][y]; x++;
		while (y > 1)
		{
			s += a[x][y]; res.push_back(X(x, y)); y--; cnt++;
			if ((a[x][y] != '5' && a[x][y] != '6') || a[x][y] == a[x][y + 1]) {x++; y++;}
			if (a[x][y] != '5' && a[x][y] != '6')
			{
				cnt--;
				res.erase(res.end() - 1);
				y++;
			}
		}
		res.push_back(X(x, y)); s += a[x][y]; cnt++; x++;
	}
	
	cout << cnt;
	for (i = 0; i < res.size(); i++) cout << ' ' << res[i].x << ' ' << res[i].y;
	
	cout << endl;
	for (i = 0; i < res.size(); i++)
		if (a[res[i].x][res[i].y] != a[res[res.size() - i - 1].x][res[res.size() - i - 1].y]) cout << i << ' ' << res[i].x << ' ' << res[i].y << ' ' << a[res[i].x][res[i].y] << endl << res[i - 1].x << ' ' << res[i - 1].y << ' ' << res[i + 1].x << ' ' << res[i + 1].y << endl;
			
	return 0;
}

