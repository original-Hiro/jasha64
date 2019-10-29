#include <fstream>
#include <algorithm>
using namespace std;

ifstream cin("gen.in");
ofstream cout("gen.out");

const int N = 17;
int n, Res, a[N];
bool f[N], c[N];

void Search(const int& Cur)
{
	if (Cur == n + 1)
	{
		int i;
		fill(c, c + N, false);
		for (i = 1; i <= n; i++)
			if (!f[i]) c[a[i]] = true;
		for (i = 1; i <= n; i++)
			if (f[i] && !c[i]) return;
			
		int CurAns = 0;
		for (i = 1; i <= n; i++)
			if (f[i]) CurAns++;
		Res = max(Res, CurAns);
		return;
	}
	f[Cur] = true;
	Search(Cur + 1);
	f[Cur] = false;
	Search(Cur + 1);
}

int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	
	Search(1);
	
	cout << Res << endl;
	
	return 0;
}

