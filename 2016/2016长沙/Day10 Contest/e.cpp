#include <fstream>
#include <iomanip>
#include <ctime>
#include <cstdlib>
#include <algorithm>
using namespace std;
#define coutf cout << setiosflags(ios::fixed) << setprecision(8)

ifstream cin("e.in");
ofstream cout("e.out");
const int N = 87;
int s[N], l[N], f[N][N], T = 15000000;
struct Mark
{
	double v;
	int p;
	friend bool operator < (const Mark& a, const Mark& b) {return a.v < b.v;}
} c[N];

int main()
{
	srand(time(NULL));
	
	int n;
	cin >> n;
	if (n == 1) {coutf << 1.0 << endl; return 0;}
	for (int i = 1, a, b; i <= n; i++) {cin >> a >> b; s[i] = a; l[i] = b - a;}
	
	T /= n;
	for (int i = 1; i <= T; i++)
	{
		for (int j = 1; j <= n; j++) {c[j].v = s[j] + rand() / (double)RAND_MAX * l[j]; c[j].p = j;}
		sort(c + 1, c + n + 1);
		for (int j = 1; j <= n; j++) ++f[c[j].p][j];
	}
	
	for (int i = 1; i <= n; i++)
	{
		coutf << f[i][1] / (double)T;
		for (int j = 2; j <= n; j++) coutf << ' ' << f[i][j] / (double)T;
		cout << endl;
	}
	
	return 0;
}

