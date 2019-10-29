#include <iostream>
using namespace std;

const int N = 407;
int G[N][N], Match[N], Match_[N], Lx[N], Ly[N], n1, n;
long long Res;
bool S[N], T[N];

bool Calc(int x)
{
	S[x] = true;
	for (int i = 1; i <= n1; i++)
		if (Lx[x] + Ly[i] == G[x][i] && !T[i])
		{
			T[i] = true;
			if (!Match[i] || Calc(Match[i])) {Match[i] = x; return true;}
		}
	return false;
}
void Update()
{
	int a = 1 << 30;
	for (int i = 1; i <= n; i++)
		if (S[i])
			for (int j = 1; j <= n1; j++)
				if (!T[j]) a = min(a, Lx[i] + Ly[j] - G[i][j]);
	for (int i = 1; i <= n; i++)
		if (S[i]) Lx[i] -= a;
	for (int i = 1; i <= n1; i++)
		if (T[i]) Ly[i] += a;
}
void KM()
{
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n1; j++) Lx[i] = max(Lx[i], G[i][j]);
	for (int i = 1; i <= n; i++)
		while (true)
		{
			fill(S, S + N, false); fill(T, T + N, false);
			if (Calc(i)) break; else Update();
		}
}

int main()
{
	ios::sync_with_stdio(false);
	int m;
	
	cin >> n >> n1 >> m; n1 = max(n1, n);
	for (int i = 0, a, b, v; i < m; i++) {cin >> a >> b >> v; G[a][b] = v;}
	
	KM();
	
	for (int i = 1; i <= n; i++) Res += Lx[i];
	for (int i = 1; i <= n1; i++) Res += Ly[i];
	for (int i = 1; i <= n1; i++)
		if (G[Match[i]][i]) Match_[Match[i]] = i;
	cout << Res << endl << Match_[1];
	for (int i = 2; i <= n; i++) cout << ' ' << Match_[i];
	cout << endl;
	
	return 0;
}

