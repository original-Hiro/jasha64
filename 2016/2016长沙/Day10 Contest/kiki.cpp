#include <fstream>
using namespace std;

ifstream cin("kiki.in");
ofstream cout("kiki.out");
const int N = 47;
int ch[N][2];
bool dir[N][2];

inline void Go(int& v, int p) {v = ch[v][dir[v][p] ^= 1];}

int main()
{
	int n;
	cin >> n;
	for (int i = 1; i < n; i++) cin >> ch[i][1] >> ch[i][0];
	
	int v = 1, u = 1;
	bool Stop = false;
	long long Res = 0;
	while (v != n)
	{
		Go(v, 0);
		if (!Stop) {Go(u, 1); Go(u, 1);}
		if (u == v && dir[u][1] == dir[v][0]) {cout << "Infinity" << endl; return 0;}
		if (u == n || u == 0) {u = 0; Stop = true;}
		++Res;
	}
	
	cout << Res << endl;
	
	return 0;
}

