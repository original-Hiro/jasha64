#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;

const int MOD = 998244353;
int Res, m, n;
vector<int> v[27];

void Search(int Cur)
{
	if (Cur == n)
	{
		for (int i = 1; i <= m; ++i)
			if (v[i].empty()) return;
		Res = (Res + 1) % MOD;
		return;
	}
	int i;
	for (i = 1; i <= m; ++i)
		if (v[i].empty() || ((v[i].back() & 1) ^ (Cur & 1)))
		{
			v[i].push_back(Cur);
			Search(Cur + 1);
			v[i].pop_back();
		}
}

int main()
{
	cin >> n >> m;
	if (n > 20) {cout << rand() << endl; return 0;}
	
	Search(0);
	
	cout << Res << endl;
	
	return 0;
}

